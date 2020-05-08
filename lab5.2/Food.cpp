#include "Food.h"
#include <iostream>

using namespace std;

Food::Food(string name, float weight, int temperature, int max_temperature, int min_temperature, float heat_capacity)
{
    if (weight <= 0)
        throw(string) "weight must be greater than 0";

    this->name = name;
    this->weight = weight;
    this->temperature = temperature;
    this->max_temperature = max_temperature;
    this->min_temperature = min_temperature;
    this->heat_capacity = heat_capacity;

    if (temperature >= max_temperature)
        this->condition = 2;
    else if (min_temperature >= temperature)
        this->condition = 1;
    else
        this->condition = 0;
}

string Food::GetName()
{
    return name;
}

float Food::GetWeight()
{
    return weight;
}

int Food::GetTemperature()
{
    return temperature;
}

int Food::GetMaxTemperature()
{
    return max_temperature;
}

int Food::GetMinTemperature()
{
    return min_temperature;
}

int Food::GetCondition()
{
    return condition;
}

void Food::TransferThermalEnergy(int Q)
{
    temperature = GetPossibleTemperature(Q);

    if (!condition)
        if (temperature >= max_temperature)
            condition = 2;
        else if (min_temperature >= temperature)
            condition = 1;
}

int Food::GetPossibleTemperature(int Q)
{
    return (int)(temperature + (Q / (weight * heat_capacity)));
}

string Food::GetStatus()
{
    switch (condition)
    {
    case 0:
        return "Нормальное";
    case 1:
        return "Переоморожен";
    case 2:
        return "Перегрет";
    default:
        return "Неизвестное";
    }
}
