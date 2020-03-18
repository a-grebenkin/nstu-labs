#include <stdio.h>
#define NMAX 100

struct btree
{
     int value;
     struct btree *left, *right;
};

struct stack {
    btree *elem [NMAX];
    int top;
};

void init(struct stack *stk) {
  stk->top = 0;
}

void push(struct stack *stk, btree *e) {
  if(stk->top < NMAX) {
    stk->elem[stk->top] = e;
    stk->top++;
  } else
    printf("Стек полон, количество элементов: %d !\n", stk->top);
}

btree * pop(struct stack *stk) {
  btree * elem;
  if((stk->top) > 0)
  {
    stk->top--;
    elem = stk->elem[stk->top];
    return elem;
  }
  else
  {
    printf("Стек пуст!\n");
    return 0;
  }
}

bool isempty(struct stack *stk) {
  if(stk->top == 0)    return 1;
  else return 0;
}

// Включение вершины в дерево
void Ins_Btree (int val, btree **q)
{
    if(*q == NULL)
    {//Нашли место для добавления
        *q = new btree;
        (*q) -> left = NULL;
        (*q) -> right = NULL;
        (*q) -> value = val;
        return;
    }
    if((*q) -> value > val)
    // Добавляем в левое поддерево
    Ins_Btree (val, &(*q) -> left);
    else
    // Добавляем в правое поддерево
    Ins_Btree (val, &(*q) ->right);
}
bool Сomp_Btre_Rec(btree *q1,btree *q2)
{
    if(q1 == NULL && q2 == NULL) return 1;
    if(q1 == NULL || q2 == NULL) return 0;
    if (q1 -> value != q2 -> value) return 0;
    return Сomp_Btre_Rec( q1 -> left,q2 -> left) * Сomp_Btre_Rec(q1 -> right,q2 -> right);
}

bool Сomp_Btre_Iter(btree *q1,btree *q2)
{
    stack *s1 = new stack;
    stack *s2 = new stack;
    init(s1);
    init(s2);
    while ((q1!=NULL || !isempty(s1)) || (q2!= NULL || !isempty(s2)))
    {
        if (isempty(s1) != isempty(s2)) return 0;
        if (!isempty(s1)) q1 = pop(s1);
        if (!isempty(s2)) q2 = pop(s2);
        while (q1!=NULL || q2!=NULL)
        {
            if (isempty(s1) != isempty(s2)) return 0;
            if ((q1==NULL || q2==NULL) && !(q1==NULL && q2==NULL)) return 0; //один из узлов отсутствует
            if (q1->value != q2-> value) return 0; //различные значения
            if ( q1->right != NULL) push(s1,q1->right);
            if ( q2->right != NULL) push(s2,q2->right);
            q1 = q1->left;
            q2 = q2->left;
        }
    }
    if (q1!=NULL || q2!=NULL)  return 0;
    return 1;
}

        
void Print_Btree_It(btree *p)
{
    stack *s1 = new stack;
    init(s1);
    while (p!=NULL || !isempty(s1))
    {
        if (!isempty(s1)) p = pop(s1);
        while (p!=NULL)
        {
            printf("%d ",p->value);
            if ( p->right != NULL) push(s1,p->right);
            p = p->left;
        }
    }
}
//Вывод содержимого дерева
void Print_Btree (btree *p)
{
     if (p == NULL) return;
     Print_Btree(p -> left);
     printf("%d ", p-> value);
     Print_Btree(p -> right);
}
int main()
{
    int d;
    btree *root1 = NULL;
    btree *root2 = NULL;
    puts("Дерево1. Ввод чисел:");
    while(1)
    {
    scanf("%d", &d);
    if(d == 0)break;
    Ins_Btree(d, &root1);
    }
    puts("Дерево2. Ввод чисел:");
    while(1)
    {
    scanf("%d", &d);
    if(d == 0)break;
    Ins_Btree(d, &root2);
    }
    printf("Рекурсивное сравнение: ");
    if (Сomp_Btre_Rec(root1,root2)==1) printf("Деревья одинаковы\n");
    else printf("Деревья различны\n");
    printf("Итеративное сравнение: ");
    if (Сomp_Btre_Iter(root1,root2)==1) printf("Деревья одинаковы\n");
    else printf("Деревья различны\n");
    Print_Btree_It(root1);
    printf("\n");
    Print_Btree_It(root2);
    printf("\n");
}
