#include "Food.h"
#include <stdexcept>

using namespace std;

Food::Food(const string& name, double weight, double temperature, double max_temperature, double min_temperature, double heat_capacity):
        name(name),
        temperature(temperature),
        max_temperature(max_temperature),
        min_temperature(min_temperature)
{
    if (name.empty())
        throw invalid_argument("name must be not empty");

    if (weight <= 0)
        throw invalid_argument("weight must be greater than 0");

    if (heat_capacity <= 0)
        throw invalid_argument("heat capacity must be greater than 0");

    if (min_temperature < -273.15)
        throw invalid_argument("min_temperature must be greater than or equal to absolute zero of temperature");

    if (max_temperature < -273.15)
        throw invalid_argument("max_temperature must be greater than or equal to absolute zero of temperature");
    
    if (max_temperature < min_temperature)
        throw invalid_argument("max_temperature must be greater than or equal to min_temperature");
    
    SetTemperature(temperature);
    
    this->weight = weight;
    this->heat_capacity = heat_capacity;

    this->condition = CONDITION::NORMAL;
    this->UpdateCondition();
}

string Food::GetName() const
{
    return name;
}

double Food::GetWeight() const
{
    return weight;
}

double Food::GetTemperature() const
{
    return temperature;
}

double Food::GetMaxTemperature() const
{
    return max_temperature;
}

double Food::GetMinTemperature() const
{
    return min_temperature;
}

Food::CONDITION Food::GetCondition() const
{
    return condition;
}

void Food::TransferThermalEnergy(double Q)
{
    temperature = GetPossibleTemperature(Q);

    UpdateCondition();
}

double Food::GetPossibleTemperature(double Q) const
{
    return (temperature + (Q / (weight * heat_capacity)));
}

string Food::GetStatus() const
{
    switch (condition)
    {
        case CONDITION::NORMAL:
            return "Нормальное";
        case CONDITION::FROZEN:
            return "Переоморожен";
        case CONDITION::OVERHEATED:
            return "Перегрет";
        default:
            return "Неизвестное";
    }
}

void Food::UpdateCondition()
{
    if (condition == CONDITION::NORMAL)
        if (temperature >= max_temperature)
            condition = CONDITION::OVERHEATED;
        else if (min_temperature >= temperature)
            condition = CONDITION::FROZEN;
}

double Food::GetHeatCapacity() const
{
    return heat_capacity;
}

void Food::SetTemperature(double temp)
{
    if (temp < -273.15)
    throw invalid_argument("temperature must be greater than or equal to absolute zero of temperature");
    temperature = temp;
    UpdateCondition();
}

string  Food::GetStringInfo() const
{
    string s;
    s+="Имя: "+GetName()+'\n';
    s+="Температура: " + to_string(GetTemperature()) + '\n';
    s+="Мин. температура: " + to_string(GetMinTemperature())+'\n';
    s+="Макс. температура: "+ to_string(GetMaxTemperature())+'\n';
    s+= "Масса: " + to_string(GetWeight()) +'\n';
    s+="Состояние: " +  GetStatus() +'\n';
    return s;
}

Food::Food() {
    return;
}