#include "Food.h"
#include <locale>

int main()
{
  setlocale(LC_ALL, "Russian");

  const int temp = 10,
            min_temp = 0,
            max_temp = 20,
            capacity = 460,
            q = 45000;

  const double weight = 0.11;

  const string name = "Test";

  try
  {
    cout << "Создание класса с отрицательным весом." << endl;
    auto error = Food(name, -5, 1, 2, 3, 4);
  }
  catch (const string &e)
  {
    cout << "Исключение: " << e << endl;
  }

  cout << endl;

  auto test = Food(name, weight, temp, max_temp, min_temp, capacity);

  cout << "Демонстрация методов:" << endl;
  cout << "Имя: " << test.GetName() << endl;
  cout << "Температура: " << test.GetTemperature() << endl;
  cout << "Мин. температура: " << test.GetMinTemperature() << endl;
  cout << "Макс. температура: " << test.GetMaxTemperature() << endl;
  cout << "Масса: " << test.GetWeight() << endl;
  cout << "Состояние: " << test.GetStatus() << endl;
  cout << "Температура, достижимая при передаче заданного количества тепловой энергии: " << test.GetPossibleTemperature(q) << endl;

  test.TransferThermalEnergy(q);
  cout << "Состояние после передачи тепловой энергии: " << test.GetStatus() << endl;
  cout << "Текущая температура: " << test.GetTemperature() << endl;

  return 0;
}