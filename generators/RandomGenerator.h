#pragma once
#include "BaseGenerator.h"

class RandomGenerator : public BaseGenerator
{
public:
    RandomGenerator(const string &name, int N);

    //RandomGenerator(ifstream& stream);

    double generate() override;

    void setPrevious(double number) override;

    //void save(ostream &stream) override;
};
