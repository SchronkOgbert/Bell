#include "pch.h"
#include "BString.h"

#include "Core.h"

using namespace bell;
using namespace core;

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

std::shared_ptr<collections::Array<string>> string::split(const string& delimiter)
{
	std::shared_ptr<collections::Array<string>> res(new collections::Array<string>());
	int start = 0;
	int end = this->findFirst(delimiter);
	while (end != -1) 
	{
		res->append(this->substring(start, end));
		start = end + delimiter.getLength();
		end = this->findFirst(delimiter, start);
	}
	res->append(this->substring(start, end));
	return res;
}

long long string::count(const char& chr) const
{
	long long count = 0;
	for (int i = 0; i < size; i++)
	{
		count += (chars[i] == chr);
	}
	return count;
}

long long string::count(const std::function<bool(const char&)>& fun) const
{
	long long count = 0;
	for (int i = 0; i < size; i++)
	{
		count += fun(chars[i]);
	}
	return count;
}

long long string::findFirst(const string& str, long long start) const
{
	return this->findFirst(str.chars, start);
}

long long string::findFirst(const char* str, long long start) const
{
	if (start >= strlen(this->chars)) throw std::out_of_range("Start position outside of string range");
	return std::string(this->chars).find(str, start);
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

bool string::operator==(const string& other) const
{
	return strcmp(this->chars, other.chars) == 0;
}

string string::substring(const int& start, const int& end) const
{
	if (end == -1)
	{
		return { std::string(this->chars).substr(start, this->size - start).c_str() };
	}
	if (end < start) 
		throw std::logic_error("End position cannot be smaller than start position");
	return { std::string(this->chars).substr(start, end - start).c_str() };
}
