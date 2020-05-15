#include <iostream>
#include <vector>
#include <cmath>
#include "Bag.h"
#include "Food.h"

using namespace std;

double Bag:: GetWeight(){
    return weight;
}

double Bag:: GetNumber(){
    return product_list.size();
}
int Bag::GetNumberDamaged(){
    int n=0;
    for ( Food & elem : product_list )
       {
           if (elem.GetCondition()!=NORMAL)
               n++;
       }
    return n;
}
int Bag::GetNumberPossibleDamaged(double Q){
    int n=0;
    for ( Food & elem : product_list )
        {
            if (elem.GetPossibleTemperature(Q)>elem.GetMaxTemperature())
                  n++;
        }
    return n;
}

void Bag:: PutFood(Food f){
    if (product_list.size()!=0){
        double k1=0;//k1=c1m1+c2m2+...+c(n-1)m(n-1);
        double t1=product_list[0].GetTemperature();
        double k2=f.GetWeight()*f.GetHeatCapacity();
        double t2=f.GetTemperature();
        for ( Food & elem : product_list )
        {
            k1+=elem.GetWeight()*elem.GetHeatCapacity();
        }
        product_list.push_back(f);
        double t = (k1*t1+k2*t2)/(k1+k2);
        for ( Food & elem : product_list )
        {
            elem.SetTemperature(t);
        }
    }
    else
    product_list.push_back(f);
}

void Bag::RemoveFood(int n){
    product_list.erase(product_list.begin() + n);
}
