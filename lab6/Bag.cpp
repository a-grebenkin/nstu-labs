#include <iostream>
#include "Bag.h"

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
    list<Food> temp = product_list;
    temp.remove_if([](const Food &product) { return product.GetCondition() == Food::NORMAL; });

    return temp.size();
}

int Bag::GetNumberPossibleDamaged(double Q) const
{
    list<Food> temp = product_list;

    temp.remove_if([Q](const Food &product) { return product.GetPossibleTemperature(Q) <= product.GetMaxTemperature(); });

    return temp.size();
}

bool Bag::PutFood(const Food &food)
{
    if (weight + food.GetWeight() > max_weight)
        return false;

    weight += food.GetWeight();

    if (product_list.empty())
    {
        product_list.push_back(food);
        return true;
    }

    auto it = product_list.begin();

    double k1 = 0, //k1=c1m1+c2m2+...+c(n-1)m(n-1);
        t1 = it->GetTemperature(),
           k2 = food.GetWeight() * food.GetHeatCapacity(),
           t2 = food.GetTemperature();

    for (const Food &elem : product_list)
        k1 += elem.GetWeight() * elem.GetHeatCapacity();

    product_list.push_back(food);

    double t = (k1 * t1 + k2 * t2) / (k1 + k2);

    for (Food &elem : product_list)
        elem.SetTemperature(t);

    return true;
}

void Bag::RemoveFood(int index)
{
    auto element = product_list.begin();
    advance(element, index);

    weight -= element->GetWeight();
    product_list.erase(element);
}

Food Bag::GetFood(int index) const
{
    auto element = product_list.begin();
    advance(element, index);

    return *element;
}

Bag::Bag(double max_weight) : max_weight(max_weight), weight(0)
{
    if (max_weight <= 0)
        throw invalid_argument("weight must be greater than 0");
}
