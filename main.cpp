#include <iostream>
#include <string>
#include <locale>
#include "generators/RandomGenerator.h"
#include "generators/GeneratorWithStep.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int N, k,a,b;
    string name;
    cout << "RandomGenerator" << endl;
    cout << "Введите N: ";
    cin >> N;

    cout << "Введите название генератора: ";
    cin >> name;

    RandomGenerator *gen1;

    try
    {
        gen1 = new RandomGenerator(name, N);
    }
    catch (const std::exception&)
    {
        cout << "Произошла ошибка" << endl;
        return 1;
    }

    cout << "Введите кол-во необходимых генерируемых чисел: ";
    cin >> k;

    cout << "Сгенерированная последовательность: ";
    for (int i = 0; i < k; i++)
        cout << gen1->generate() << " ";

    try
    {
        cout << endl << "Сред. арифмет. - " << gen1->average() << endl;
    }
    catch (const std::exception&)
    {
        cout << "Недостаточно чисел" << endl;
    }

    cout << "GeneratorWithStep" << endl;
    cout << "Введите N: ";
    cin >> N;

    cout << "Введите название генератора: ";
    cin >> name;

    cout << "Введите начальное число: ";
    cin >> a;

    cout << "Введите начальное шаг: ";
    cin >> b;

    GeneratorWithStep *gen2;
    try
    {
        gen2 = new GeneratorWithStep(name, a, b, N);
    }
    catch (const std::exception&)
    {
        cout << "Произошла ошибка" << endl;
        return 1;
    }

    cout << "Введите кол-во необходимых генерируемых чисел: ";
    cin >> k;

    cout << "Сгенерированная последовательность: ";
    for (int i = 0; i < k; i++)
        cout << gen2->generate() << " ";

    try
    {
        cout << endl << "Сред. арифмет. - " << gen2->average() << endl;
    }
    catch (const std::exception&)
    {
        cout << "Недостаточно чисел" << endl;
    }

    cout << "Мат. ожидание - " << RandomGenerator::expectedValue() << endl;
}

