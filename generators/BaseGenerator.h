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

    double average() const;

    virtual void save(ostream &stream);

protected:
    void push(double number);

    vector<BaseGenerator *> generators;

    enum GEN_TYPES {BASE, RAND, STEP};

    GEN_TYPES genType = BASE;

    void _save(ostream &stream, const string &additional_data = "");

private:
    vector<double> sequence;

    string name;

    size_t counter = 0;

    size_t N;

    bool full = false;
};