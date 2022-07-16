#include "pch.h"
#include "BString.h"

using namespace bell;

string::iterator::iterator(const int& pos, string& obj) : pos(pos), object(obj)
{
	
}

string::iterator& string::iterator::operator++()
{
	pos++;
	return *this;
}

string::iterator& string::iterator::operator++(int)
{
	pos++;
	return *this;
}

bool string::iterator::operator==(const iterator& other) const
{
	return this->pos == other.pos;
}

bool string::iterator::operator!=(const iterator& other) const
{
	return this->pos != other.pos;
}

char& string::iterator::operator*() const
{
	return object[pos];
}

string::string()
{
	chars = new char[1];
	size = 1;
	chars[0] = '\0';
}

string::string(const string& other)
{
	chars = strdup(other.chars);
	size = strlen(chars);
}

string::string(const char* cString)
{
	chars = strdup(cString);
	size = strlen(chars);
}

string& string::operator=(const string& other)
{
	delete[] chars;
	chars = _strdup(other.chars);
	return *this;
}

string& string::operator=(const char* cString)
{
	delete[] chars;
	chars = _strdup(cString);
	return *this;
}

string::~string()
{
	delete[] chars;
}

std::ostream& bell::operator<<(std::ostream& out, const string& obj)
{
	out << obj.chars;
	return out;
}

char& string::operator[](const int& index) const
{
	if (index >= 0)
	{
		return chars[index];
	}
	return chars[size + index];
}
