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

    int GetNumberPossibleDamaged(list<Food> product_list) const;

    bool PutFood(const Food &food);

    void RemoveFood(size_t index);

    Food GetFood(size_t index) const;

    Food& operator[] (const size_t index);
private:
    double max_weight,
        weight;

    list<Food> product_list;
};
