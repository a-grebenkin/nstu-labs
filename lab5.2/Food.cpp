#include "Food.h"
#include <iostream>

using namespace std;

Food::Food(string name, double weight, double temperature, double max_temperature, double min_temperature, double heat_capacity):
name(name),
temperature(temperature),
max_temperature(max_temperature),
min_temperature(min_temperature)
{
    if (weight <= 0)
        throw(string) "weight must be greater than 0";

    if (heat_capacity<=0)
       throw(string) "heat capacity must be greater than 0";
    
    this->weight = weight;

    this->heat_capacity = heat_capacity;

    if (temperature >= max_temperature)
        this->condition = overheated;
    else if (min_temperature >= temperature)
        this->condition = frozen;
    else
        this->condition = overheated;
}

string Food::GetName()
{
    return name;
}

double Food::GetWeight()
{
    return weight;
}

double Food::GetTemperature()
{
    return temperature;
}

double Food::GetMaxTemperature()
{
    return max_temperature;
}

double Food::GetMinTemperature()
{
    return min_temperature;
}

condition_food Food::GetCondition()
{
    return condition;
}

void Food::TransferThermalEnergy(int Q)
{
    temperature = GetPossibleTemperature(Q);

    if (!condition)
        if (temperature >= max_temperature)
            condition = overheated;
        else if (min_temperature >= temperature)
            condition = frozen;
}

int Food::GetPossibleTemperature(int Q)
{
    return (int)(temperature + (Q / (weight * heat_capacity)));
}

string Food::GetStatus()
{
    switch (condition)
    {
    case normal:
        return "Нормальное";
    case frozen:
        return "Переоморожен";
    case overheated:
        return "Перегрет";
    default:
        return "Неизвестное";
    }
}
