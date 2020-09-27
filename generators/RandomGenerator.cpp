#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(const string &name, int N) : BaseGenerator(name, N) {

}

int RandomGenerator::generate() {
    int res = rand();
    this->push(res);

    return res;
}

void RandomGenerator::setPrevious(int number) {
    BaseGenerator::setPrevious(number);
    srand(number);
}
