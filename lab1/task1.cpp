#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/* Ввод слов */
char **getWords()
{
    int length = 0;                                // количество слов
    char **w = (char **)malloc(sizeof(char *));    // массив слов
    w[length] = (char *)calloc(255, sizeof(char)); // выделение памяти под одно слово

    printf("Вам необходимо ввести слова. Каждое слово должно разделяться с помощью Enter.\n");
    printf("По окончанию ввода слов просто нажмите Enter.\n");

    printf("Введите слово: "); // приглашение пользователя ввести слово
    gets(w[length]);           // ввод первого слова
    while (w[length][0])       // пока не введена пустая строка
    {
        length++;                                               // увеличение количества слов
        w = (char **)realloc(w, sizeof(char *) * (length + 1)); // увеличение памяти массива
        w[length] = (char *)calloc(255, sizeof(char));          // выделение памяти под новое слово

        printf("Введите слово: "); // приглашение пользователя ввести слово
        gets(w[length]);           // ввод нового слова
    }

    w[length] = NULL; // обозначение конца массива
    return w;         // возврат массива
}

/* Вывод цепочек.
words - массив слов (или же цепочка), position - позиция в массиве. */
void printChainWords(char **words, int position)
{
    int i = 0; // счетчик

    printf("\n"); // переход на новую строку

    while (words[i] != NULL && i < position) // пока есть слова в массиве
    {
        printf("%s ", words[i]); // вывод слова
        i++;                     // увеличение счетчика
    }
}

/* Рекурсивная функция. 
words - массив слов, position - позиция в массиве. */
int handle(char **words, int position)
{
    char *temp_word = (char *)calloc(255, sizeof(char)); // временное слово
    int i = position;                                    // индекс в массиве

    if (words[position] == NULL) // если достигли конца массива
    {
        printChainWords(words, position); // вывод цепочки
        return 1;
    }

    while (words[i] != NULL)
    {
        if (position == 0 || words[position - 1][strlen(words[position - 1]) - 1] == words[i][0])
        {
            if (position == 0) // переход к новому слову => оповещаем пользователя
                printf("\n\n-- ВЫВОД КОМБИНАЦИЙ --");

            /* меняем слова местами */
            strcpy(temp_word, words[position]);
            strcpy(words[position], words[i]);
            strcpy(words[i], temp_word);

            handle(words, position + 1); // вызов функции для новых перестановок

            /* меняем слова местами обратно */
            strcpy(temp_word, words[position]);
            strcpy(words[position], words[i]);
            strcpy(words[i], temp_word);
        }
        i++;
    }
    printChainWords(words, position); // вывод цепочки слов

    return 0;
}

int main()
{
    char **words; // массив слов

    setlocale(LC_ALL, "Russian"); // настройка локали

    /* приветствие пользователя */
    printf("Здравствуйте.\n");
    printf("Данная программа составляет линейный кроссворд из слов, которые введены Вами.\n");

    words = getWords(); // ввод слов
    handle(words, 0);   // вызов рекурсивной функции

    return 0;
}
