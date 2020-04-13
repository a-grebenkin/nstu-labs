#include "task.cpp"
#include "structs.cpp"

int main()
{
  Array *testDataArray = new Array();

  auto testNum1 = new List<int>(0), testNum2 = new List<int>(1488);
  auto testArray1 = new List<Array>(*new Array()), testArray2 = new List<Array>(*testDataArray);
  auto testStudent = new List<student>(*new student);
  auto testMatrix1 = new List<Matrix>(*new Matrix());

  for (size_t i = 0; i < 5; i++)
    testNum1->add(rand());

  for (size_t i = 0; i < 5; i++)
    testNum2->add(rand());

  for (size_t i = 0; i < 5; i++)
    testArray1->add(*new Array(rand()));

  for (size_t i = 0; i < 5; i++)
    testArray2->add(*new Array(rand()));

  for (size_t i = 0; i < 5; i++)
    testMatrix1->add(*new Matrix(rand()));

  printf("%d", testArray1->insert(*testDataArray, testArray2));
  printf("%p", testStudent->getMaxElement());
  printf("%p", testMatrix1->getMaxElement());
  printf("%d", testNum1->insert(0, testNum2));

  return 0;
}
