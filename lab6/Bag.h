#pragma once
#include <iostream>
#include <vector>
#include "Food.h"
using namespace std;
class Bag{
public:
    double GetWeight();
    double GetNumber();
    int GetNumberDamaged();
    int GetNumberPossibleDamaged(double Q);
    void PutFood(Food f);
    void RemoveFood(int n);
    vector <Food> product_list;
private:
    double max_weight;
    double weight;
};
