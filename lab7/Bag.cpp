#include "Bag.h"
#include <stdexcept>

using namespace std;

Bag::Bag(double max_weight) : max_weight(max_weight), weight(0)
{
    if (max_weight <= 0)
        throw invalid_argument("weight must be greater than 0");

    this->product_list = List<Food>();
}

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

int Bag::GetNumberPossibleDamaged(const List<Food> &food_list) const
{
    List<Food> temp = product_list;
    double _weight = weight, _max = max_weight;
    size_t size = food_list.size();

    for (int i = 0; i < size; ++i)
        AddToList(food_list[i], temp, _weight, _max);

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

    Food element = product_list[index];

    weight -= element.GetWeight();
    product_list.pop(index);
}

Food& Bag::operator[] (int index)
{
    if (index < 0)
        throw invalid_argument("index must be greater or equal 0");

    return product_list[index];
}

bool Bag::AddToList(const Food &food, List<Food> _list, double &_weight, double &_max_weight) {
    if (_weight + food.GetWeight() > _max_weight)
        return false;

    _weight += food.GetWeight();

    if (_list.empty())
    {
        _list.push_back(food);
        return true;
    }

    double  k1 = 0,                                          //k1=c1m1+c2m2+...+c(n-1)m(n-1)
            t1 = _list[0].GetTemperature(),
            k2 = food.GetWeight() * food.GetHeatCapacity(),
            t2 = food.GetTemperature();

    size_t size = _list.size();
    for (size_t i = 0; i < size; ++i)
        k1 += _list[i].GetWeight() * _list[i].GetHeatCapacity();

    _list.push_back(food);

    double t = (k1 * t1 + k2 * t2) / (k1 + k2);

    size++;
    for (int i = 0; i < size; ++i)
        _list[i].SetTemperature(t);

    return true;
}

int Bag::CountDamaged(List<Food> _list) {
    return _list.count_if([](const Food &product) { return product.GetCondition() != Food::CONDITION::NORMAL; });
}
