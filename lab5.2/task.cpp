#include <iostream>
using namespace std;
class Food{
private:
    string name;
    int weight;
    int temperature;
    int max_temperature;
    int min_temperature;
    int condition; //0 -переморожен 1 - перегрет 2 - нормальное
    float heat_capacity;
    Food(string name, int weight, int temperature,int max_temperature, int min_temperature,float heat_capacity){
        this->name=name;
        this->weight=weight;
        this->max_temperature = max_temperature;
        this->min_temperature = min_temperature;
        this->heat_capacity = heat_capacity;
    }
public:
    string GetName(){
        return name;
    }
    int GetWeight(){
        return weight;
    }
    int GerTemperature(){
        return temperature;
    }
};
int main(int argc, const char * argv[]) {
    return 0;
}
