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
  int length_one = strlen(stringOne);
  int length_two = strlen(stringTwo);
  int min_length = length_one > length_two ? length_two : length_one;

  for (size_t i = 0; i < min_length; i++)
  {
    if (stringOne[i] > stringTwo[i])
      return 1;
    else if (stringTwo[i] > stringOne[i])
      return 2;
  }

  if (length_one - min_length > 0)
    return 1;
  else if (length_two - min_length > 0)
    return 2;

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

  compare = compareStrings((*q)->name, name);

  if (compare == 1)
    // Добавляем в левое поддерево
    Ins_Btree(name, value, &(*q)->left);
  else if (compare == 2)
    // Добавляем в правое поддерево
    Ins_Btree(name, value, &(*q)->right);
}

// получить все дефайны
btree *getAllDefines(FILE *stream, btree *tree)
{
  char define_buffer[8], letter, *name, *value, define_str[] = "define ";
  size_t position = 0;

  fseek(stream, 0, 0);

  while (!feof(stream))
  {
    fread(&letter, sizeof(char), 1, stream);
    if (letter != '#')
      continue;

    fread(define_buffer, sizeof(char), 7, stream);
    define_buffer[7] = '\0';

    if (compareStrings(define_buffer, define_str))
      continue;

    name = new char[1];

    while (!feof(stream))
    {
      fread(&letter, sizeof(char), 1, stream);

      if (letter == ' ')
        break;

      name[position] = letter;
      position++;

      name = (char *)realloc(name, sizeof(char) * (position + 1));
    }

    name[position] = '\0';
    value = new char[1];
    position = 0;

    while (!feof(stream))
    {
      fread(&letter, sizeof(char), 1, stream);

      if (letter == '\n' || letter == '\0')
        break;

      value[position] = letter;
      position++;

      value = (char *)realloc(value, sizeof(char) * (position + 1));
    }
    value[position] = '\0';
    position = 0;

    Ins_Btree(name, value, &tree);
  }

  return tree;
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
  char letter = '\0', previous, *temp;
  size_t position;
  btree *item;

  fseek(reader, 0, 0);
  fseek(writer, 0, 0);

  while (!feof(reader))
  {
    previous = letter;
    fread(&letter, sizeof(char), 1, reader);

    if (letter == '#')
    {
      do
      {
        fwrite(&letter, sizeof(char), 1, writer);
        fread(&letter, sizeof(char), 1, reader);

      } while (!feof(reader) && letter != '\n');

      fwrite(&letter, sizeof(char), 1, writer);
      continue;
    }

    if (isalpha(letter) && (previous == ' ' || previous == '(' || previous == ',' || previous == '\n'))
    {
      temp = new char[2];
      temp[0] = letter;
      position = 1;

      while (!feof(reader))
      {
        fread(&letter, sizeof(char), 1, reader);

        temp[position] = letter;

        if (letter == ' ' || letter == ')' || letter == ',' || letter == '\n' || letter == '(')
          break;

        position++;
        temp = (char *)realloc(temp, sizeof(char) * (position + 1));
      }

      temp[position] = '\0';
      item = getItem(tree, temp);

      if (item)
      {
        fwrite(item->value, sizeof(char), strlen(item->value), writer);
        fwrite(&letter, sizeof(char), 1, writer);
      }
      else
      {
        temp[position] = letter;
        temp[position + 1] = '\0';
        fwrite(temp, sizeof(char), strlen(temp), writer);
      }
    }
    else
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
  test_tree = getAllDefines(stream_reader, test_tree);
  
  scanf("%s", filename);
  stream_writer = fopen(filename, "w");

  replaceAllDefines(stream_reader, stream_writer, test_tree);
  
  printf("done.\n");
  fcloseall();

  return 0;
}