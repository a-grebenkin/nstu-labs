#pragma once

#include <string>
#include <vector>

using namespace std;

class BaseGenerator {
public:
    BaseGenerator(const string &name, int N);

    ~BaseGenerator();

    virtual int generate() = 0;

    int getPrevious() const;

    virtual void setPrevious(int number);

    string getName() const;

    double average() const;

    static double expectedValue();


protected:
    void push(int number);

    vector<int> sequence;

private:
    string name;

    size_t counter = 0;

    size_t N;

    bool full = false;

    inline static vector<BaseGenerator*> allGenerators;

    size_t index;

};