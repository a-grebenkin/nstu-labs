#pragma once
#include "BaseGenerator.h"

class GeneratorWithStep : public BaseGenerator {
public:
    GeneratorWithStep(const string &name, int N, int first, int step);

    int generate() override;

private:
    int step;
};
