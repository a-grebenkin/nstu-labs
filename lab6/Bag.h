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

    int GetNumberPossibleDamaged(const list<Food> &food_list) const;

    bool PutFood(const Food &food);

    void RemoveFood(int index);

    Food& operator[] (int index);
private:
    double max_weight,
        weight;

    list<Food> product_list;

    static bool AddToList(const Food &food, list<Food> _list, double &_weight, double &_max_weight);

    static int CountDamaged(list<Food> _list);
};
