#include <iostream>
#include <string>
#include <locale>
#include "generators/RandomGenerator.h"
#include "generators/GeneratorWithStep.h"
#include "json.h"
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double N, k, a, b;
    string name;
    cout << "RandomGenerator" << endl;
    cout << "Введите N: ";
    cin >> N;

    cout << "Введите название генератора: ";
    cin >> name;

    RandomGenerator *gen1;

    ifstream test("test.json");

    try
    {
        gen1 = new RandomGenerator(name, 5);
    }
    catch (const std::exception &)
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
        cout << endl
             << "Сред. арифмет. - " << gen1->average() << endl;
    }
    catch (const std::exception &)
    {
        cout << "Недостаточно чисел" << endl;
    }

    cout << gen1->average() << endl;

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
        gen2 = new GeneratorWithStep(name, N, a, b);
    }
    catch (const std::exception &)
    {
        cout << "Произошла ошибка" << endl;
        return 1;
    }

    gen2->add(gen1);

    cout << "Введите кол-во необходимых генерируемых чисел: ";
    cin >> k;

    cout << "Сгенерированная последовательность: ";
    for (int i = 0; i < k; i++)
        cout << gen2->generate() << " ";

    try
    {
        cout << endl
             << "Сред. арифмет. - " << gen2->average() << endl;
    }
    catch (const std::exception &)
    {
        cout << "Недостаточно чисел" << endl;
    }

    BaseGenerator* testGen = BaseGenerator::load(test);
    cout << testGen->getName() << endl;
}
