#pragma once

#include <iostream>
#include <list>
#include "Food.h"

using namespace std;
class Bag
{
public:
    explicit Bag(double _max_weight);

    double GetWeight() const;

    int GetCount() const;

    int GetNumberDamaged() const;

    int GetNumberPossibleDamaged(double Q) const;

    bool PutFood(const Food &food);

    void RemoveFood(int index);

    Food GetFood(int index) const;

private:
    double max_weight,
        weight;

    list<Food> product_list;
};
