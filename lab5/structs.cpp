#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include "cstdlib"
#include <string.h>
#define N 30
using namespace std;

struct student
{
  char name[N]; // фамилия
  int weight;   // вес
  float height; // рост
  //перегрузка операции отношения ==
  int operator==(student &right)
  {
    if (strcmp(name, right.name) == 0)
      return 1;
    return 0;
  }
  //перегрузка операции отношения >=
  int operator>=(student &right)
  {
    if (strcmp(name, right.name) >= 0)
      return 1;
    return 0;
  }
  //перегрузка оператора присваивания
  student &operator=(student &st)
  {
    strcpy(name, st.name);
    weight = st.weight;
    height = st.height;
    return *this;
  }
  //перегрузка операции вывода
  friend ostream &operator<<(ostream &output, const student &st)
  {
    output << st.name << "(" << st.weight << "/" << st.height << ")";
    return output;
  }
  //перегрузка операции ввода
  friend istream &operator>>(istream &input, student &st)
  {
    std::cout << "Familya: ";
    input >> st.name;
    std::cout << "Wes: ";
    input >> st.weight;
    std::cout << "Rost: ";
    input >> st.height;
    return input;
  }
};

struct Array
{
  int *Arr; // адрес памяти под массив
  int Size; // количество элементов
  // установка начальных значений
  void SetArr(int n)
  {
    int i;
    Arr = new int[n];
    Size = n;
    for (i = 0; i < Size; i++)
      Arr[i] = 0;
  }
  // изменение размера массива
  void ReSize(int n)
  {
    if (n < 2)
      std::cout << "ERROR";
    if (Size == n)
      return;
    int *newArr = new int[n];            // выделяем память под новый массив
    int newSize = (n < Size) ? n : Size; //находим минимальную длину
    int i = 0;
    while (i < newSize)
    {
      newArr[i] = Arr[i]; //копируем элементы массива
      i++;
    }
    delete[] Arr;
    Arr = newArr;
    Size = n;
  }
  //конструктор по умолчанию (создаем массив из 10 элементов, обнуляем их значения)
  Array(int n = 10)
  {
    SetArr(n);
  }
  //конструктор копирования
  Array(Array &a)
  {
    int i;
    Size = a.Size;             //копируем количество
    Arr = new int[Size];       //выделяем память
    for (i = 0; i < Size; i++) //копируем элементы
      Arr[i] = a.Arr[i];
  }
  //деструктор
  ~Array()
  {
    cout << "destruct Array\n";
    delete[] Arr;
  }
  //перегрузка оператора присваивания
  Array &operator=(Array &a)
  {
    int i;
    if (&a != this)
    {
      Size = a.Size;
      delete[] Arr;
      Arr = new int[Size];
      for (i = 0; i < Size; i++)
        Arr[i] = a.Arr[i];
    }
    return *this;
  }
  //перегрузка операции отношения ==
  int operator==(Array &a)
  {
    int i;
    if (Size != a.Size)
      return 0;
    for (i = 0; i < Size; i++)
      if (Arr[i] != a.Arr[i])
        return 0;
    return 1;
  }
  //перегрузка операции отношения >=
  int operator>=(Array &a)
  {
    int i;
    if (Size > a.Size)
      return 1;
    if (Size < a.Size)
      return 0;
    for (i = 0; i < Size; i++)
    {
      if (Arr[i] > a.Arr[i])
        return 1;
      if (Arr[i] < a.Arr[i])
        return 0;
    }
    return 1;
  }
  //перегрузка операции вывода
  friend ostream &operator<<(ostream &output, const Array &a)
  {
    int i;
    output << "(Kolichestvo chisl:" << a.Size << ")";
    for (i = 0; i < a.Size; i++)
      output << a.Arr[i] << ",";
    return output;
  }
  // перегрузка операции ввода
  friend istream &operator>>(istream &input, Array &a)
  {
    int i;
    std::cout << "Kolichestvo elementov:";
    input >> i;
    if (i != a.Size)
      a.ReSize(i);
    std::cout << "Enter elements:";
    for (i = 0; i < a.Size; i++)
      input >> a.Arr[i];
    return input;
  }
};

struct Matrix
{
  int Size;      //количество элементов
  int **element; //элементы матрицы
  // установка начальных значений
  void SetMatr(int razmer)
  {
    int i, j;
    Size = razmer;             //размер
    element = new int *[Size]; //выделение памяти
    for (i = 0; i < Size; i++)
      element[i] = new int[Size];
    for (i = 0; i < Size; i++) //установка начальных значений равных 0
      for (j = 0; j < Size; j++)
        element[i][j] = 0;
  }
  // конструктор по умолчанию создается матрица 2х2
  Matrix(int n = 2)
  {
    SetMatr(n);
  }
  //конструктор копирования
  Matrix(Matrix &M)
  {
    int i, j;
    Size = M.Size; //копируем размер
    //выделяем память
    element = new int *[Size];
    for (i = 0; i < Size; i++)
      element[i] = new int[Size];
    //копируем элементы
    for (i = 0; i < Size; i++)
      for (j = 0; j < Size; j++)
        element[i][j] = M.element[i][j];
  }
  //деструктор
  ~Matrix()
  {
    int i;
    cout << "destruct Matrix\n";
    // освобождение памяти
    for (i = 0; i < Size; i++)
      delete[] element[i];
    delete[] element;
  }
  // перегрузка оператора присваивания
  Matrix &operator=(Matrix &M)
  {
    int i, j;
    if (&M != this)
    {
      for (i = 0; i < Size; i++) // освобождение памяти
        delete[] element[i];
      delete[] element;
      Size = M.Size;
      // выделение памяти
      element = new int *[Size];
      for (i = 0; i < Size; i++)
        element[i] = new int[Size];
      for (i = 0; i < Size; i++)
        // копируем элементы
        for (j = 0; j < Size; j++)
          element[i][j] = M.element[i][j];
    }
    return *this;
  }
  //перегрузка операции равно
  int operator==(Matrix &M)
  {
    int i, j;
    if (Size != M.Size)
      return 0; // сравниваем размер
    for (i = 0; i < Size; i++)
      for (j = 0; j < Size; j++)
        if (element[i][j] != M.element[i][j])
          return 0; // сравниваем элементы
    return 1;
  }
  //перегрузка операции больше или равно
  int operator>=(Matrix &M)
  {
    int i, j;
    if (Size > M.Size)
      return 1;
    if (Size < M.Size)
      return 0;
    for (i = 0; i < Size; i++)
      for (j = 0; j < Size; j++)
      {
        if (element[i][j] > M.element[i][j])
          return 1;
        if (element[i][j] < M.element[i][j])
          return 0;
      }
    return 0;
  }
  // изменение размера матрицы
  void ReSize(int n)
  {
    if (n < 2)
      std::cout << "ERROR";
    if (Size == n)
      return;
    int **newelement = new int *[n];
    int i = 0, j = 0;
    int newSize = (n < Size) ? n : Size; //находим минимальную длину
    for (i = 0; i < n; i++)
      newelement[i] = new int[newSize];
    for (i = 0; i < newSize; i++)
      for (j = 0; j < newSize; j++)
        newelement[i][j] = element[i][j];
    delete[] element;
    element = newelement;
    Size = n;
  }
  //перегрузка операции вывода
  friend ostream &operator<<(ostream &output, const Matrix &M)
  {
    int i, j;
    output << "Razmer:" << M.Size << "\n";
    for (i = 0; i < M.Size; i++)
    {
      for (j = 0; j < M.Size; j++)
        output << M.element[i][j] << "\t";
      output << "\n";
    }
    return output;
  }
  //перегрузка операции ввода
  friend istream &operator>>(istream &input, Matrix &M)
  {
    int i, j;
    std::cout << "Vvedi razmer martix:";
    while (1)
    {
      input >> i;
      if (i > 1)
        break;
      std::cout << "Razmer ne doljen nije 2";
    }
    if (i != M.Size)
      M.ReSize(i);
    std::cout << "Enter elements:";
    for (i = 0; i < M.Size; i++)
    {
      std::cout << "Stroka:\n";
      for (j = 0; j < M.Size; j++)
        input >> M.element[i][j];
    }
    std::cout << M;
    return input;
  }
};