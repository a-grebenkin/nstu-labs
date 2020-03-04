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

List *Ins_Sort(int n, List *head)
{
    List *q = new List(n), *p = head;

    if (head == NULL)
        return q;
    // включение в начало
    if (n < head->value)
    {
        q->next = head;
        return q;
    }
    // включение в «середину»
    while (p->next != NULL)
        if (n < p->next->value)
        {
            q->next = p->next;
            p->next = q;
            break;
        }
        else
            p = p->next;
    // включаем последним
    p->next = q;
    return head;
}

List *Get_Last_Element(List *head)
{
    List *element = head;

    if (element == NULL || head->next == NULL)
        return head;

    while (element->next->next != NULL)
        element = element->next;

    return element->next;
}

List *Enter_List()
{
    List *list = NULL;
    char *input = (char *)calloc(25, sizeof(char));

    fgets(input, 25, stdin);
    input[strlen(input) - 1] = '\0';

    while (input[0] != '\0')
    {
        list = Ins_Sort(atoi(input), list);

        fgets(input, 25, stdin);
        input[strlen(input) - 1] = '\0';
    }

    return list;
}

int main()
{
    List *list;
    List *max = NULL;

    setlocale(LC_ALL, "Russian");

    list = Enter_List();

    max = Get_Last_Element(list);
    printf("Адрес максимального элемента списка - %p\n", max);

    return 0;
}
