#include <iostream>
#include "Bag.h"
#include <algorithm>

using namespace std;

double Bag::GetWeight() const
{
    return weight;
}

int Bag::GetCount() const
{
    return product_list.size();
}

int Bag::GetNumberDamaged() const
{
    return CountDamaged(product_list);
}

int Bag::GetNumberPossibleDamaged(const list<Food> &food_list) const
{
    list<Food> temp = product_list;
    double _weight = weight, _max = max_weight;

    for (const Food& product : food_list)
        AddToList(product, temp, _weight, _max);

    return CountDamaged(temp);
}

bool Bag::PutFood(const Food &food)
{
    return AddToList(food, product_list, weight, max_weight);
}

void Bag::RemoveFood(int index)
{
    if (index < 0)
        throw invalid_argument("index must be greater than 0");

    if (index > product_list.size())
        throw invalid_argument("no more than the number of products");
    
    auto element = product_list.begin();
    advance(element, index);

    weight -= element->GetWeight();
    product_list.erase(element);
}

Bag::Bag(double max_weight) : max_weight(max_weight), weight(0)
{
    if (max_weight <= 0)
        throw invalid_argument("weight must be greater than 0");
}

Food& Bag::operator[] (int index)
{
    if (index < 0)
        throw invalid_argument("index must be greater or equal 0");

    auto element = product_list.begin();
    advance(element, index);
    return *element;
}

bool Bag::AddToList(const Food &food, list<Food> _list, double &_weight, double &_max_weight) {
    if (_weight + food.GetWeight() > _max_weight)
        return false;

    _weight += food.GetWeight();

    if (_list.empty())
    {
        _list.push_back(food);
        return true;
    }

    auto it = _list.begin();

    double  k1 = 0,                                          //k1=c1m1+c2m2+...+c(n-1)m(n-1)
            t1 = it->GetTemperature(),
            k2 = food.GetWeight() * food.GetHeatCapacity(),
            t2 = food.GetTemperature();

    for (const Food &elem : _list)
        k1 += elem.GetWeight() * elem.GetHeatCapacity();

    _list.push_back(food);

    double t = (k1 * t1 + k2 * t2) / (k1 + k2);

    for (Food &elem : _list)
        elem.SetTemperature(t);

    return true;
}

int Bag::CountDamaged(list<Food> _list) {
    return count_if(_list.begin(), _list.end(), [](const Food &product) { return product.GetCondition() != Food::CONDITION::NORMAL; });
}
