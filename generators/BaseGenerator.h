#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class GEN_TYPES { BASE, RAND, STEP };

class BaseGenerator
{
public:
    BaseGenerator(const string &name, int N);

    static BaseGenerator* load(istream& stream);

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

    GEN_TYPES genType = GEN_TYPES::BASE;

    void _save(ostream &stream, const string &additional_data = "");

private:
    vector<double> sequence;

    string name;

    size_t counter = 0;

    size_t N;

    bool full = false;
};