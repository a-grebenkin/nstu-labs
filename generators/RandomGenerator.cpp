#include "RandomGenerator.h"
#include <iostream>

RandomGenerator::RandomGenerator(const string &name, int N) : BaseGenerator(name, N)
{
    this->genType = GEN_TYPES::RAND;
}

double RandomGenerator::generate()
{
	double res = 0.0;

	try
	{
		res = rand() / (rand() + 1.0) + BaseGenerator::generate();
	}
	catch (const out_of_range &ex)
	{
		res = rand() / (rand() + 1.0);
	}

	res /= this->generators.size() + 1;

	this->push(res);
	return res;
}

void RandomGenerator::setPrevious(double number)
{
	BaseGenerator::setPrevious(number);
	srand(number);
}
