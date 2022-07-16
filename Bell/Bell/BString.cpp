#include "pch.h"
#include "BString.h"

using namespace bell;

string::string()
{
	chars = new char[1];
	chars[0] = '\0';
}

string::string(const string& other)
{
	chars = _strdup(other.chars);
}

string::string(const char* cString)
{
	chars = _strdup(cString);
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
