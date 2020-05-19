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

    if (temperature < -273.15)
        throw invalid_argument("temperature must be greater than or equal to absolute zero of temperature");

    if (temperature < -273.15)
        throw invalid_argument("min_temperature must be greater than or equal to absolute zero of temperature");

    if (max_temperature < -273.15)
        throw invalid_argument("max_temperature must be greater than or equal to absolute zero of temperature");

    this->weight = weight;
    this->heat_capacity = heat_capacity;

    this->condition = NORMAL;
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
        case NORMAL:
            return "Нормальное";
        case FROZEN:
            return "Переоморожен";
        case OVERHEATED:
            return "Перегрет";
        default:
            return "Неизвестное";
    }
}

void Food::UpdateCondition()
{
    if (condition == CONDITION::NORMAL)
        if (temperature >= max_temperature)
            condition = OVERHEATED;
        else if (min_temperature >= temperature)
            condition = FROZEN;
}

double Food::GetHeatCapacity() const
{
    return heat_capacity;
}

void Food::SetTemperature(double temp) {
    temperature = temp;

    UpdateCondition();
}

void Food::PrintInfo(){
    cout << "Имя: " << GetName() << endl;
    cout << "Температура: " << GetTemperature() << endl;
    cout << "Мин. температура: " << GetMinTemperature() << endl;
    cout << "Макс. температура: " << GetMaxTemperature() << endl;
    cout << "Масса: " << GetWeight() << endl;
    cout << "Состояние: " << GetStatus() << endl;
}
