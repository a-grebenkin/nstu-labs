#pragma once
#include "BaseGenerator.h"

class GeneratorWithStep : public BaseGenerator
{
public:
    GeneratorWithStep(const string &name, int N, double first, double step);

    //GeneratorWithStep(istream& stream);

    double generate() override;

    //void save(ostream &stream) override;

private:
    double step;
};
