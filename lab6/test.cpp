#include "Food.h"
#include "Bag.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");

    const double
        temp1 = 5.0,       temp2=24.0,        temp3=24.0,           //°С
        min_temp1 = 0.0,   min_temp2 = 0.0,   min_temp3 = 0.0,      //°С
        max_temp1 = 20.0,  max_temp2 = 40.0,  max_temp3 = 30.0,     //°С
        capacity1 = 2800.0,capacity2=9000.0,  capacity3=17150.0,    //J·kg^−1·K^−1
        weight1 = 0.7,     weight2=1.0,       weight3=5.0,          //kg
        max_weight=10;                                              //kg
    
    try
    {
        cout << "Создание сумки с отрицательным максимальным весом" << endl;
        Bag bag0(-100);
    }
    catch (const invalid_argument &e)
    {
        cout << "Исключение: " << e.what() << endl;
    }

    Bag bag(max_weight);
    cout << "Демонстрация методов:" << endl;
    cout << endl;
    
    cout << "Добавление 1 продукта" << endl;
    Food test1 = Food("Молоко", weight1, temp1, max_temp1, min_temp1, capacity1);
    bag.PutFood(test1);
    test1.PrintInfo();
    cout << endl;
    
    cout << "1 продукт после добавления в сумку"<< endl;
    bag.GetFood(0).PrintInfo();
    cout << endl;
    
    cout << "Добавление 2 продукта" << endl;
    Food test2 = Food("Хлеб", weight2, temp2, max_temp2, min_temp2, capacity2);
    bag.PutFood(test2);
    test2.PrintInfo();
    cout << endl;
    
    cout << "2 продукт после добавления в сумку"<< endl;
    bag.GetFood(1).PrintInfo();
    cout << endl;
    
    cout << "Добавление 3 продукта" << endl;
    Food test3 = Food("Сахар", weight3, temp3, max_temp3, min_temp3, capacity3);
    bag.PutFood(test3);
    test3.PrintInfo();
    cout << endl;

    cout << "3 продукт после добавления в сумку"<< endl;
    bag.GetFood(2).PrintInfo();
    cout << endl;
    
    cout<< "Итоговое содержимое сумки" <<endl;
    for (int i=0;i<bag.GetCount();i++ )
    {
        cout<< i+1 <<" продукт" << endl;
        bag.GetFood(i).PrintInfo();
        cout << endl;
    }
    
    return 0;
}
