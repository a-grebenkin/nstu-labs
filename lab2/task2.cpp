#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct List
{
    int value;
    List *next;

    List(int val = 0, List *p = NULL) //конструктор
    {
        value = val;
        next = p;
    }
};

//включение элемента в конец
List *Add_last(int n, List *head)
{
    List *q = new List(n), *p = head;
    // если список пуст
    if (head == NULL)
        return q;
    // «идем в конец списка»
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    return head;
}

List *Enter_List()
{
    List *list = NULL;
    char *input = (char *)calloc(25, sizeof(char));

    fgets(input, 25, stdin);
    input[strlen(input) - 1] = '\0';

    while (input[0] != '\0')
    {
        list = Add_last(atoi(input), list);

        fgets(input, 25, stdin);
        input[strlen(input) - 1] = '\0';
    }

    return list;
}

int Insert_List(int E, List *l1, List *l2)
{
    List *element = l1, // текущий элемент в l1
        *temp = NULL;   // элемент, идущий после E
    int count = 1;      // количество элементов

    // если первый или второй список пуст
    if (l1 == NULL || l2 == NULL)
        return -1;

    // поиск элемента, содержащий E
    while (element->value != E && element->next != NULL)
    {

        element = element->next;
        count++;
    }

    // если элемент не найден
    if (element->value != E && element->next == NULL)
        return -1;

    temp = element->next; // запоминаем элемент идущий после E
    element->next = l2;   // добавляем в l1 l2

    // идем до конца измененного списка
    while (element->next != NULL)
    {
        element = element->next;
        count++;
    }
    element->next = temp; // добавление к измененному списку элемент, идущий после E

    while (element->next != NULL)
    {
        element = element->next;
        count++;
    }

    return count; // возврат длины нового списка
}

int main()
{
    List *l1, *l2;
    int E, count;

    setlocale(LC_ALL, "Russian");

    printf("Ввод L1:\n");
    l1 = Enter_List();

    printf("Ввод L2:\n");
    l2 = Enter_List();

    printf("Ввод числа E: ");
    scanf("%d", &E);

    count = Insert_List(E, l1, l2);
    if (count > 0)
        printf("Длина нового списка - %d.\n", count);
    else
        printf("Некорректные данные.");

    return 0;
}
