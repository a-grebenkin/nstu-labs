#pragma once
#include <iostream>

using namespace std;

class Food
{
private:
    string name;

    float weight;

    int temperature;

    int max_temperature;

    int min_temperature;

    int condition; // 1 -переморожен 2 - перегрет 0 - нормальное

    float heat_capacity;

public:
    Food(string name, float weight, int temperature, int max_temperature, int min_temperature, float heat_capacity);

    string GetName();

    float GetWeight();

    int GetTemperature();

    int GetMaxTemperature();

    int GetMinTemperature();

    int GetCondition();

    void TransferThermalEnergy(int Q);

    int GetPossibleTemperature(int Q);

    string GetStatus();
};
