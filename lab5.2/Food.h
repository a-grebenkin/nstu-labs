#pragma once
#include <iostream>

using namespace std;

enum CONDITION
{
    NORMAL,    // нормальное состояние
    FROZEN,    // перегрет
    OVERHEATED // переморожен
};

class Food
{
public:
    Food(const string &name, double weight, double temperature, double max_temperature, double min_temperature, double heat_capacity);

    string GetName() const;

    double GetWeight() const;

    double GetTemperature() const;

    double GetMaxTemperature() const;

    double GetMinTemperature() const;

    CONDITION GetCondition() const;

    void TransferThermalEnergy(double Q);

    double GetPossibleTemperature(double Q) const;

    string GetStatus() const;

private:
    string name;

    double weight; //kg

    double temperature; //°С

    double max_temperature; //°С

    double min_temperature; //°С

    CONDITION condition;

    double heat_capacity; //J·kg^−1·K^−1
};
