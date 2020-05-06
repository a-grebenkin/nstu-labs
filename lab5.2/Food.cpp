#include "Food.h"
#include <iostream>
using namespace std;
Food :: Food(string name, int weight, int temperature,int max_temperature, int min_temperature,float heat_capacity){
    this->name=name;
    this->weight=weight;
    this->max_temperature = max_temperature;
    this->min_temperature = min_temperature;
    this->heat_capacity = heat_capacity;
}
string Food :: GetName(){
    return name;
 }
int Food :: GetWeight(){
    return weight;
 }
int Food :: GetTemperature(){
    return temperature;
 }

int Food::GetMaxTemperature() {
    return max_temperature;
}
int Food::GetMinTemperature() {
    return min_temperature;
}
int Food::GetCondition() {
    return condition;
}
void Food::TransferThermalEnergy(int Q) {
    temperature+=Q*k;
}
int Food::GetPossibleTemperature(int Q){
    return temperature+(Q*k);
}
