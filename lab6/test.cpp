#include "Food.h"
#include "Bag.h"
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");

    const double
        temp1 = -15.0,       temp2=-16.0,       temp3=140.0,         //°С
        min_temp = -15.1,                                              //°С
        max_temp = 20.0,                                             //°С
        capacity1 = 13.0,  capacity2=10.0,      capacity3=1000.0,     //J·kg^−1·K^−1
    weight1 = 1000.0,     weight2=10000.00,        weight3=100;        //kg
    Bag bag;
    Food test1 = Food("1", weight1, temp1, max_temp, min_temp, capacity1);
    bag.PutFood(test1);
    cout << "Демонстрация методов:" << endl;
    for ( Food & elem : bag.product_list )
       {
           cout << "Имя: " << elem.GetName() << endl;
           cout << "Температура: " << elem.GetTemperature() << endl;
           cout << "Мин. температура: " << elem.GetMinTemperature() << endl;
           cout << "Макс. температура: " << elem.GetMaxTemperature() << endl;
           cout << "Масса: " << elem.GetWeight() << endl;
           cout << "Состояние: " << elem.GetStatus() << endl;
           cout << endl;
       }
    Food test2 = Food("2", weight2, temp2, max_temp, min_temp, capacity2);
    bag.PutFood(test2);
    cout << "Демонстрация методов:" << endl;
    for ( Food & elem : bag.product_list )
    {
        cout << "Имя: " << elem.GetName() << endl;
        cout << "Температура: " << elem.GetTemperature() << endl;
        cout << "Мин. температура: " << elem.GetMinTemperature() << endl;
        cout << "Макс. температура: " << elem.GetMaxTemperature() << endl;
        cout << "Масса: " << elem.GetWeight() << endl;
        cout << "Состояние: " << elem.GetStatus() << endl;
        cout << endl;
    }
    Food test3 = Food("3", weight3, temp3, max_temp, min_temp, capacity3);
    bag.PutFood(test3);
    cout << "Демонстрация методов:" << endl;
    for ( Food & elem : bag.product_list )
    {
        cout << "Имя: " << elem.GetName() << endl;
        cout << "Температура: " << elem.GetTemperature() << endl;
        cout << "Мин. температура: " << elem.GetMinTemperature() << endl;
        cout << "Макс. температура: " << elem.GetMaxTemperature() << endl;
        cout << "Масса: " << elem.GetWeight() << endl;
        cout << "Состояние: " << elem.GetStatus() << endl;
        cout << endl;
    } 
   

    return 0;
}
