#include "GeneratorWithStep.h"
#include <iostream>

double GeneratorWithStep::generate()
{
	double res = 0.0;

	try
	{
		res = this->getPrevious() + this->step + BaseGenerator::generate();
	}
	catch (const out_of_range &ex)
	{
		res = this->getPrevious() + this->step;
	}

	res /= this->generators.size() + 1.0;

	BaseGenerator::push(res);
	return res;
}

GeneratorWithStep::GeneratorWithStep(const string &name, int N, double first, double step) : BaseGenerator(name, N)
{
	this->step = step;
	this->push(first);
}
