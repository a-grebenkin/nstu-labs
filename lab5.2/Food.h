#pragma once
#include <iostream>
using namespace std;

class Food{
private:
    string name;
    int k; //k=1/(c*m)
    int weight;
    int temperature;
    int max_temperature;
    int min_temperature;
    int condition; //0 -переморожен 1 - перегрет 2 - нормальное
    float heat_capacity;
public:
    Food(string name, int weight, int temperature,int max_temperature, int min_temperature,float heat_capacity);
    string GetName();
    int GetWeight();
    int GetTemperature();
    int GetMaxTemperature();
    int GetMinTemperature();
    int GetCondition();
    void TransferThermalEnergy(int Q);
    int GetPossibleTemperature(int Q);
};
