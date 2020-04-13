#include "stdio.h"

template <class T>
struct List
{
  T value;       // значение
  List<T> *next; // следующий элемент

  // конструктор
  List(T val)
  {
    value = val;
    next = NULL;
  }

  // получить максимальный элемент из списка
  List<T> *getMaxElement()
  {
    List<T> *element,        // текущий элемент из списка
        *max_element = this; // максимальный элемент

    if (this->next == NULL) // если нет следуюшего элемента
      return element;       // вернуть текущий

    element = element->next; // переход к следущему элементу

    do
    {
      if (element->value >= max_element->value) // если значение текущего элемента > значение максимального элемента
        max_element = element;                  // => текущий элемент максимальный

      element = element->next;       // переход
    } while (element->next != NULL); // пока список не закончится

    return max_element; // возврат максимального элемента
  }

  void add(T value)
  {
    auto *element = this; // текущий элемент

    // идем до самого конца списка
    while (element->next != NULL)
      element = element->next;

    element->next = new List<T>(value); // добавление элемента в конец
  }

  // вставить список перед каким-то значением
  int insert(T before_value, List<T> *list)
  {
    List<T> *element = this, // текущий элемент
        *temp = NULL;        // элемент идущий после необходимого значения
    int count = 1;           // количество элементов

    // если второй список пуст
    if (list == NULL)
      return -1;

    // поиск нужного элемента
    while (element->value != before_value && element->next != NULL)
    {
      element = element->next;
      count++;
    }

    // если элемент не найден
    if (element->value != before_value && element->next == NULL)
      return -1;

    temp = element->next; // запоминаем элемент идущий после необходимого значения
    element->next = list; // добавляем второй список в первый

    // идем в самый конец списка
    while (element->next != NULL)
    {
      element = element->next;
      count++;
    }

    element->next = temp; // добавление к измененному списку элемент, идущий после нужного значения

    // подсчет оставшихся элементов в списке
    while (element->next != NULL)
    {
      element = element->next;
      count++;
    }

    return count; // возврат длины нового списка
  }
};

int main()
{
  return 0;
}
