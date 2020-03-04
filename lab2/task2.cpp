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

List *Get_Last_Element(List *head)
{
    List *element = head;

    if (element == NULL || head->next == NULL)
        return head;

    while (element->next->next != NULL)
        element = element->next;

    return element->next;
}

int Count_List(List *list)
{
    int count = 1;
    List *element = list;

    if (list == NULL)
        return 0;

    while (element->next != NULL)
    {
        element = element->next;
        count++;
    }

    return count;
}

int Insert_List(int E, List *l1, List *l2)
{
    List *element = l1,
         *temp = NULL;

    if (l1 == NULL)
        return 0;

    if (l2 == NULL)
        return Count_List(l1);

    while (element->value != E && element->next != NULL)
        element = element->next;

    if (element->value != E && element->next != NULL)
        return Count_List(l1);

    temp = element->next;
    element->next = l2;

    while (element->next != NULL)
        element = element->next;

    element->next = temp;

    return Count_List(l1);
}

int main()
{
    List *l1, *l2;
    int E, count;

    printf("Ввод L1:\n");
    l1 = Enter_List();
    
    printf("Ввод L2:\n");
    l2 = Enter_List();

    printf("Ввод числа E: ");
    scanf("%d", &E);

    count = Insert_List(E, l1, l2);
    printf("Длина нового списка - %d\n", count);

    return 0;
}
