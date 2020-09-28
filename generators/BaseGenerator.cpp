#include "BaseGenerator.h"
#include <stdexcept>

BaseGenerator::BaseGenerator(const string &name, int N) {
    if (name.empty() && N <= 0)
        throw invalid_argument("invalid arguments for generator");

    this->name = name;
    this->N = N;
    this->sequence = vector<int>(N);

    BaseGenerator::allGenerators.push_back(this);
    this->index = BaseGenerator::allGenerators.size() - 1;
}

int BaseGenerator::getPrevious() const {
    if (this->sequence.empty())
        throw out_of_range("sequence is empty");

    int ndx = (int)this->counter - 1;

    return sequence[ndx == -1 ? this->N - 1 : ndx];
}

void BaseGenerator::push(int number) {
    this->sequence[counter] = number;
    this->counter++;

    if (this->counter == this->N)
    {
        this->counter = 0;
        if (!full)
            this->full = true;
    }
}

void BaseGenerator::setPrevious(int number) {
    this->sequence[this->counter ? this->counter : N - 1] = number;
}

string BaseGenerator::getName() const {
    return this->name;
}

double BaseGenerator::average() const {
    double sum = 0.0;

    if (!full)
        throw out_of_range("invalid variable value");

    for (size_t i = 0; i < N; i++)
        sum += sequence[i];

    return sum / N;
}

double BaseGenerator::expectedValue(int N) {
    if (BaseGenerator::allGenerators.size() < N)
        throw out_of_range("not enough generators");

    double sum = 0;

    for (auto it = BaseGenerator::allGenerators.end() - N; it != BaseGenerator::allGenerators.end(); it++)
        sum += (*it)->generate();

    return sum / BaseGenerator::allGenerators.size();
}

BaseGenerator::~BaseGenerator() {
    for (auto it = BaseGenerator::allGenerators.begin() +  this->index + 1; it != BaseGenerator::allGenerators.end(); it++)
        (*it)->index -= 1;

    BaseGenerator::allGenerators.erase(BaseGenerator::allGenerators.begin() + this->index);
}
