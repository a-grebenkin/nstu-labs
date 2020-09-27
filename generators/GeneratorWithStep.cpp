#include "GeneratorWithStep.h"

int GeneratorWithStep::generate() {
    int res = this->getPrevious() + this->step;

    BaseGenerator::push(res);
    return res;
}

GeneratorWithStep::GeneratorWithStep(const string &name, int N, int first, int step) : BaseGenerator(name, N) {
    this->step = step;
    this->push(first);
}
