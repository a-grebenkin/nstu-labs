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

List *Get_Max_Element(List *head)
{
    List *element = head,    // текущий элемент в списке
        *max_element = NULL; // адрес максимального элемента в списке

    // если список пустой/состоит из 1 элемента
    if (element == NULL || head->next == NULL)
        return head; // возвращаем его

    do
    {
        if (element->value > max_element->value) // если значение текущего элемента > значение максимального элемента
            max_element = element;               // => текущий элемент максимальный

        element = element->next;     // переход
    } while (element->next != NULL); // пока список не закончится

    return max_element; // возврат максимального элемента
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

int main()
{
    List *list;
    List *max = NULL;

    setlocale(LC_ALL, "Russian");

    list = Enter_List();

    max = Get_Max_Element(list);
    printf("Адрес максимального элемента списка - %p\n", max);

    return 0;
}
