#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class BaseGenerator
{
public:
    BaseGenerator(const string &name, int N);

    //BaseGenerator(istream& stream);

    virtual double generate();

    double getPrevious() const;

    virtual void setPrevious(double number);

    string getName() const;

    void add(BaseGenerator *);

    //virtual void save(ostream& stream);

    double average() const;

protected:
    void push(double number);

    vector<BaseGenerator *> generators;

private:
    vector<double> sequence;

    string name;

    size_t counter = 0;

    size_t N;

    bool full = false;
};