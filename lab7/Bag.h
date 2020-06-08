#pragma once

#include "Food.h"
#include "List.h"

using namespace std;
class Bag
{
public:
    explicit Bag(double _max_weight);

    double GetWeight() const;

    int GetCount() const;

    int GetNumberDamaged() const;

    int GetNumberPossibleDamaged(const List<Food> &food_list) const;

    bool PutFood(const Food &food);

    void RemoveFood(int index);

    Food& operator[] (int index);
private:
    double max_weight,
        weight;

    List<Food> product_list;

    static bool AddToList(const Food &food, List<Food> _list, double &_weight, double &_max_weight);

    static int CountDamaged(List<Food> _list);
};
