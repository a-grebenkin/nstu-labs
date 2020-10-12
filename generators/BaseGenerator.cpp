#include "BaseGenerator.h"
#include <stdexcept>
#include <sstream>
#include <map>

BaseGenerator::BaseGenerator(const string &name, int N)
{
    if (name.empty() && N <= 0)
        throw invalid_argument("invalid arguments for generator");

    this->name = name;
    this->N = N;
    this->sequence = vector<double>(N);
}
/*
BaseGenerator::BaseGenerator(istream& stream)
{
    if (!stream.good())
        throw invalid_argument("invalid stream");


    string value;
    getline(stream, value, ';'); // ���

    this->name = value;
    getline(stream, value, ';'); // N

    try
    {
        this->N = atoi(value.c_str());
    }
    catch (const std::exception&)
    {
        throw invalid_argument("wrong stream");
    }

    this->sequence = vector<int>(this->N);

    stringstream lineStream;
    getline(stream, value, ';');
    lineStream << value;

    this->full = true;
    for (size_t i = 0; i < N; i++)
    {
        string next;
        getline(lineStream, next, ',');

        if (next == "end")
        {
            this->full = false;
            break;
        }

        try
        {
            this->sequence[this->counter] = atoi(next.c_str());
            this->counter++;
        }
        catch (const std::exception&)
        {
            throw invalid_argument("wrong stream");
        }
    }
}
*/

double BaseGenerator::generate()
{
    if (this->generators.empty())
        throw out_of_range("not enough generators");

    double sum = 0.0;

    for (auto it = this->generators.begin(); it != this->generators.end(); it++)
        sum += (*it)->generate();

    return sum / (double)this->generators.size();
}

double BaseGenerator::getPrevious() const
{
    if (this->sequence.empty())
        throw out_of_range("sequence is empty");

    int ndx = (int)this->counter - 1;

    return sequence[ndx == -1 ? this->N - 1 : ndx];
}

void BaseGenerator::push(double number)
{
    this->sequence[counter] = number;
    this->counter++;

    if (this->counter == this->N)
    {
        this->counter = 0;
        if (!full)
            this->full = true;
    }
}

void BaseGenerator::setPrevious(double number)
{
    this->sequence[this->counter ? this->counter - 1 : N - 1] = number;
}

string BaseGenerator::getName() const
{
    return this->name;
}

void BaseGenerator::add(BaseGenerator *gen)
{
    this->generators.push_back(gen);
}

double BaseGenerator::average() const
{
    double sum = 0.0;

    if (!full)
        throw out_of_range("invalid variable value");

    for (size_t i = 0; i < N; i++)
        sum += sequence[i];

    return sum / N;
}

void BaseGenerator::_save(ostream &stream, const string &additional_data) {
    stream << R"({"name":")" << this->name << '"' ;
    stream << R"(,"size":)" << this->N;
    stream << R"(,"type":)" << this->genType;
    stream << R"(,"sequence":[)";

    if (this->full)
    {
        for (int i = 0; i < this->N; i++)
        {
            stream << this->sequence[(i + this->counter) % this->N];
            if (i != this->N - 1)
                stream << ',';
        }
    }
    else
    {
        for (size_t i = 0; i < this->counter; i++)
        {
            stream << this->sequence[i];
            if (i != this->counter - 1)
                stream << ',';
        }
    }

    stream << R"(],"generators":[)";
    for (int i = 0; i < this->generators.size(); ++i) {
        this->generators[i]->save(stream);
        if (i != this->generators.size() - 1)
            stream << ",";
    }
    stream << ']';

    if (!additional_data.empty())
        stream << ',' << additional_data;

    stream << '}';
}

void BaseGenerator::save(ostream &stream) {
    this->_save(stream);
}