#include "json.h"
#include <stdexcept>
#include <ios>


JSONDecoder::JSONDecoder(istream& stream)
{
	string key, token;
	char letter;

	if (stream.bad())
		throw invalid_argument("invalid stream");

	while (true) {
		letter = stream.get();
		if (letter == ',' || letter == '{')
			continue;
		else if (letter == '}' || stream.eof())
			break;


		key = readKey(stream);
		letter = stream.get();

		if (letter != ':')
			throw invalid_argument("invalid json");

		if (key == "name")
		{
			this->name = readString(stream);
		}
		else if (key == "size") {
			this->N = readInt(stream);
		}
		else if (key == "type") {
			this->genType = (GEN_TYPES)readInt(stream);
		}
		else if (key == "sequence") {
			this->sequence = readDoubleArray(stream);
		}
		else if (key == "generators") {
			this->generators = readStringArray(stream);
		}
		else {
			this->additional_data.insert({ key, readDynamicToken(stream) });
		}
	}
}

string JSONDecoder::readKey(istream& stream)
{
	char letter;
	string key;

	while (true)
	{
		letter = stream.get();
		if (letter == '"')
			break;

		key.push_back(letter);
	}

	return key;
}

int JSONDecoder::readInt(istream& stream)
{
	char letter;
	string number;
	bool minus = false;

	while (true) {
		letter = stream.get();

		if (letter >= '0' && letter <= '9')
			number.push_back(letter);
		else if (!minus && letter == '-' && number.empty())
			number.push_back(letter);
		else
			break;
	}

	return stoi(number);
}

vector<double> JSONDecoder::readDoubleArray(istream& stream)
{
	char letter;
	bool point = false, minus = false;
	string str;
	vector<double> data;

	letter = stream.get();
	if (letter != '[')
		throw invalid_argument("invalid json");

	while (true)
	{
		letter = stream.get();

		if (letter >= '0' && letter <= '9')
			str.push_back(letter);
		else if (letter == '.' && !point && !str.empty())
		{
			str.push_back(',');
			point = true;
		}
		else if (letter == '-' && !minus && str.empty())
		{
			str.push_back(letter);
			minus = true;
		}
		else if (letter == ',') {
			double num = stod(str);
			data.push_back(num);
			minus = false;
			point = false;
			str.erase();
		}
		else if (letter == ']') {
			data.push_back(stod(str));
			break;
		}
		else {
			throw invalid_argument("invalid array");
		}
	}

	return data;
}

vector<string> JSONDecoder::readStringArray(istream& stream)
{
	char letter;
	string str;
	int counter_obj = 0, counter_arr = 1;
	vector<string> data;

	letter = stream.get();
	if (letter != '[')
		throw invalid_argument("invalid json");

	while (true)
	{
		letter = stream.get();

		switch (letter)
		{
		case '{':
			counter_obj++;
			str.push_back(letter);
			break;
		case '}':
			counter_obj--;
			str.push_back(letter);
			if (counter_obj == 0)
			{
				data.push_back(str);
				str.erase();
			}
			break;
		case ']':
			counter_arr--;
			if (counter_arr == 0)
				return data;
			str.push_back(letter);
			break;
		case '[':
			counter_arr++;
			str.push_back(letter);
			break;
		case ',':
			if (counter_obj != 0)
				str.push_back(letter);
			break;
		default:
			str.push_back(letter);
			break;
		}
	}

}

string JSONDecoder::readDynamicToken(istream& stream)
{
	char letter;
	string str;

	while (true) {
		letter = stream.get();

		switch (letter)
		{
		case ',':
		case '}':
			return str;
		default:
			str.push_back(letter);
			break;
		}
	}
}

string JSONDecoder::readString(istream& stream)
{
	char letter;
	string str;

	letter = stream.get();
	if (letter != '"')
		throw invalid_argument("invalid string");

	while (true)
	{
		letter = stream.get();
		if (letter == '"')
			break;

		str.push_back(letter);
	}

	return str;
}
