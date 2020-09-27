#pragma once
#include "BaseGenerator.h"

class RandomGenerator : public BaseGenerator {
public:
    RandomGenerator(const string &name, int N);

    int generate() override;

    void setPrevious(int number) override;
};

