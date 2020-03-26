#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct btree
{
  int value;
  struct btree *left, *right;
};

struct stack
{
  btree **elem;
  int top;

  stack(int value = 0) //конструктор
  {
    top = value;
    elem = (btree**)calloc(1, sizeof(btree));
  }

  void push(btree *e) //добавление узла в стек
  {
    elem[top] = e;
    top++;
    elem = (btree **)realloc(elem, sizeof(btree) * (top + 1));
  }

  btree *pop() // считываение и удаление узла из стека
  {
    if (top > 0)
    {
      top--;
      return elem[top];
    }
    else
      return 0;
  }

  bool isEmpty() // проверка стека на наличие элементов
  {
    return top ? false : true;
  }
};

// Включение вершины в дерево
void Ins_Btree(int val, btree **q)
{
  if (*q == NULL)
  { //Нашли место для добавления
    *q = new btree;
    (*q)->left = NULL;
    (*q)->right = NULL;
    (*q)->value = val;
    return;
  }

  if ((*q)->value > val)
    // Добавляем в левое поддерево
    Ins_Btree(val, &(*q)->left);
  else
    // Добавляем в правое поддерево
    Ins_Btree(val, &(*q)->right);
}

// Рекурсивная проверка равенства 2 деревьев
bool Comp_Btre_Rec(btree *q1, btree *q2)
{
  if (q1 == NULL && q2 == NULL) //если узлы одновременно отсутсвуют возвращаем истину
    return 1;

  if (q1 == NULL || q2 == NULL) //если один из узлов отсутсвует возвращаем ложь
    return 0;

  if (q1->value != q2->value) //если значения различаются возвращаем ложь
    return 0;

  return Comp_Btre_Rec(q1->left, q2->left) * Comp_Btre_Rec(q1->right, q2->right); //возвращаем произведение результатов сравнеия правых и левых поддеревьев первого и второго дерева
}

// Итеративная проверка равенства 2 деревьев
bool Comp_Btre_Iter(btree *q1, btree *q2)
{
  stack *s1 = new stack(), *s2 = new stack(); // создаем два стека для хранения узлов правых поддеревьев

  while (q1 != NULL || !s1->isEmpty() || q2 != NULL || !s2->isEmpty()) //  пока узел одного из деревьев существет или один из стеков не пуст
  {
    if (s1->isEmpty() != s2->isEmpty()) // если один из стеков пуст, а другой нет возвращаем ложь
      return 0;

    if (!s1->isEmpty()) // если первый стек не пуст переходим к последнему записанному в него поддереву
      q1 = s1->pop();

    if (!s2->isEmpty()) // если второй стек не пуст переходим к последнему записанному в него поддереву
      q2 = s2->pop();

    while (q1 != NULL || q2 != NULL) // пока оба узла существуют 
    {
      if (s1->isEmpty() != s2->isEmpty()) // если один из стеков пуст возвращаем ложь
        return 0;

      if ((q1 == NULL || q2 == NULL) && !(q1 == NULL && q2 == NULL)) //если один из узлов отсутствует (но не 2 одновременно) возвращаем ложь
        return 0; 

      if (q1->value != q2->value) // если значения различаются возвращаем ложь
        return 0; 

      if (q1->right != NULL) // если узел правого поддерева первого дерева существует добавляем его в первый стек
        s1->push(q1->right);

      if (q2->right != NULL) // если узел правого поддерева второго дерева существует добавляем его во второй стек
        s2->push(q2->right);

      q1 = q1->left; // переходим к узлу левого подеерева первого дерева 
      q2 = q2->left; // переходим к узлу левого подеерева второго дерева 
    }
  }
  if (q1 != NULL || q2 != NULL) // если один из узлов отсутствует возвращаем ноль
    return 0;

  return 1;
}

void Print_Btree_It(btree *p)
{
  stack *s1 = new stack();

  while (p != NULL || !s1->isEmpty())
  {
    if (!s1->isEmpty())
      p = s1->pop();

    while (p != NULL)
    {
      printf("%d ", p->value);
      if (p->right != NULL)
        s1->push(p->right);

      p = p->left;
    }
  }
}

//Вывод содержимого дерева
void Print_Btree(btree *p)
{
  if (p == NULL)
    return;

  Print_Btree(p->left);
  printf("%d ", p->value);
  Print_Btree(p->right);
}

int main()
{
  int d;
  btree *root1 = NULL, *root2 = NULL;

  puts("Дерево1. Ввод чисел:");
  while (1)
  {
    scanf("%d", &d);
    if (d == 0)
      break;

    Ins_Btree(d, &root1);
  }

  puts("Дерево2. Ввод чисел:");
  while (1)
  {
    scanf("%d", &d);
    if (d == 0)
      break;

    Ins_Btree(d, &root2);
  }

  printf("Рекурсивное сравнение: ");
  if (Comp_Btre_Rec(root1, root2) == 1)
    printf("Деревья одинаковы\n");
  else
    printf("Деревья различны\n");

  printf("Итеративное сравнение: ");
  if (Comp_Btre_Iter(root1, root2) == 1)
    printf("Деревья одинаковы\n");
  else
    printf("Деревья различны\n");

  Print_Btree_It(root1);
  printf("\n");
  Print_Btree_It(root2);
  printf("\n");
}
