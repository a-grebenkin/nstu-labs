#pragma once
#include <iostream>

using namespace std;

enum condition_food{
       normal, // нормальное состояние
       frozen, // перегрет
       overheated // переморожен
   };

class Food
{
public:
    Food(string name, double weight, double temperature, double max_temperature, double min_temperature, double heat_capacity);
    string GetName();

    double GetWeight();

    double GetTemperature();

    double GetMaxTemperature();

    double GetMinTemperature();

    condition_food GetCondition();

    void TransferThermalEnergy(int Q);

    int GetPossibleTemperature(int Q);

    string GetStatus();

private:
    string name;

    double weight; //kg

    double temperature; //°С

    double max_temperature; //°С

    double min_temperature; //°С
    
    condition_food condition;
    
    double heat_capacity; //J·kg^−1·K^−1
};
