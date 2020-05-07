#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct btree
{
  char *name, *value;
  btree *left, *right;

  btree(char *name, char *value)
  {
    this->name = name;
    this->value = value;
    this->left = NULL;
    this->right = NULL;
  }
};

// сравнить строки
int compareStrings(char *stringOne, char *stringTwo)
{
  int length_one = strlen(stringOne),                                 // длина первой строки
      length_two = strlen(stringTwo),                                 // длина второй строки
      min_length = length_one > length_two ? length_two : length_one; // Минимальная длина

  // сравнение по буквам
  for (size_t i = 0; i < min_length; i++)
  {
    if (stringOne[i] > stringTwo[i])
      return 1;
    else if (stringTwo[i] > stringOne[i])
      return 2;
  }

  // если в слове больше букв чем в другом => оно больше
  if (length_one - min_length > 0)
    return 1;
  else if (length_two - min_length > 0)
    return 2;

  // если слова равны
  return 0;
}

// добавить в дерево
void Ins_Btree(char *name, char *value, btree **q)
{
  int compare;

  if (*q == NULL)
  { //Нашли место для добавления
    *q = new btree(name, value);

    return;
  }

  compare = compareStrings((*q)->name, name); // сравнение слов

  if (compare == 1)
    // Добавляем в левое поддерево
    Ins_Btree(name, value, &(*q)->left);
  else if (compare == 2)
    // Добавляем в правое поддерево
    Ins_Btree(name, value, &(*q)->right);
}

// обработка слов после решетки
btree *handleSharp(FILE *stream, btree *tree)
{
  char define_buffer[8],        // для поиска макроса
      letter,                   // буква
      *name,                    // имя макроса
      *value,                   // значение макроса
      define_str[] = "define "; // определение макроса
  size_t position = 0;

  // чтение из файла
  fread(define_buffer, sizeof(char), 7, stream);
  define_buffer[7] = '\0';

  // если определение макроса не совпадает
  if (compareStrings(define_buffer, define_str))
    return tree; // возвращаем дерево

  name = (char *)calloc(1, sizeof(char)); // место для имени макроса

  // пока не конец файла
  while (!feof(stream))
  {
    fread(&letter, sizeof(char), 1, stream); // чтение буквы

    // если имя макроса закончилось, переход к следующему циклу
    if (letter == ' ')
      break;

    // добавление буквы в название файла
    name[position] = letter;
    position++;
    name = (char *)realloc(name, sizeof(char) * (position + 1));
  }

  name[position] = '\0';
  value = (char *)calloc(1, sizeof(char)); // место для значения макроса
  position = 0;

  // пока не конец файла
  while (!feof(stream))
  {
    fread(&letter, sizeof(char), 1, stream);

    // если имя макроса закончилось, переход к следующему этапу
    if (letter == '\n' || letter == '\0')
      break;

    // добавление буквы к значению
    value[position] = letter;
    position++;
    value = (char *)realloc(value, sizeof(char) * (position + 1));
  }
  value[position] = '\0';
  position = 0;

  Ins_Btree(name, value, &tree); // добавляем в дерево

  return tree; // возвращаем
}

// найти элемент в дереве
btree *getItem(btree *tree, char *name)
{
  int compare;

  if (tree == NULL)
    return NULL;

  compare = compareStrings(tree->name, name);

  if (compare == 1)
    return getItem(tree->left, name);
  else if (compare == 2)
    return getItem(tree->right, name);
  else
    return tree;
}

// заменить все дефайны
void replaceAllDefines(FILE *reader, FILE *writer, btree *tree)
{
  char letter = '\0', // символ
      previous,       // предыдущий символ
      *temp;          // временная строка
  size_t position;    // позиция
  btree *item;        // дерево
  long point,         // место в файле
      difference;     // разница от point и сейчас

  // в начало файла
  fseek(reader, 0, 0);
  fseek(writer, 0, 0);

  // пока не конец файла
  while (!feof(reader))
  {
    previous = letter;
    fread(&letter, sizeof(char), 1, reader);

    if (letter == '#')
    {
      fwrite(&letter, sizeof(char), 1, writer);

      point = ftell(reader);            // получаем место в файле
      tree = handleSharp(reader, tree); // обрабатываем знак решетки

      // возврат на позицию (в pointer)
      difference = ftell(reader) - point;
      fseek(reader, difference * (-1), 1);

      // запись символов после решетки
      temp = (char *)calloc(difference, sizeof(char));
      fread(temp, sizeof(char), difference, reader);
      fwrite(temp, sizeof(char), difference, writer);

      continue;
    }

    // фильтр
    if (isalpha(letter) && (previous == ' ' || previous == '(' || previous == ',' || previous == '\n'))
    {
      temp = (char *)calloc(2, sizeof(char));
      temp[0] = letter;
      position = 1;

      // пока не конец файла
      while (!feof(reader))
      {
        fread(&letter, sizeof(char), 1, reader);

        // запись символа к "подозрительной" последовательности символов
        temp[position] = letter;

        // если фильтр сработал - остановка цикла
        if (letter == ' ' || letter == ')' || letter == ',' || letter == '\n' || letter == '(')
          break;

        position++;
        temp = (char *)realloc(temp, sizeof(char) * (position + 1));
      }

      temp[position] = '\0';
      item = getItem(tree, temp); // поиск макроса по дереву

      if (item) // если он есть, то заменяем его на необходимое значение
      {
        fwrite(item->value, sizeof(char), strlen(item->value), writer);
        fwrite(&letter, sizeof(char), 1, writer);
      }
      else // иначе запишем эту последовательность символов
      {
        temp[position] = letter;
        temp[position + 1] = '\0';
        fwrite(temp, sizeof(char), strlen(temp), writer);
      }
    }
    else // если фильтр не сработал, просто пишем этот символ
      fwrite(&letter, sizeof(char), 1, writer);
  }
}

int main()
{
  btree *test_tree = NULL;
  FILE *stream_reader, *stream_writer;
  char *filename = (char *)calloc(255, sizeof(char));

  scanf("%s", filename);
  stream_reader = fopen(filename, "r");

  scanf("%s", filename);
  stream_writer = fopen(filename, "w");

  replaceAllDefines(stream_reader, stream_writer, test_tree);

  printf("done.\n");
  fclose(stream_reader);
  fclose(stream_writer);

  return 0;
}