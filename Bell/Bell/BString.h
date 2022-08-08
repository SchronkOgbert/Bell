#pragma once

#ifdef _MSC_VER
#define strdup(p) _strdup(p)
inline void strcpy(char* dest, char* source)
{
	strcpy_s(dest, strlen(dest) + 1, source);
}
#endif
#include "Array.hpp"


namespace bell
{
	class string
	{
		char* chars;

		BSize size;

	public:
		class iterator
		{
			BSize pos;
			string& object;
		public:
			iterator(const BSize& pos, string& obj);

			iterator& operator++();

			iterator& operator++(int);

			bool operator==(const iterator&) const;

			bool operator!= (const iterator&) const;

			char& operator*() const;
		};

		string();

		string(const string& other);

		string(const char* cString);

		std::shared_ptr<collections::Array<string>> split(const string& delimiter = " ");

		[[nodiscard]] BSize count(const char& chr) const;

		BSize count(const std::function<bool(const char&)>& fun) const;

		[[nodiscard]] BSize findFirst(const string& str, BSize start = 0) const;

		BSize findFirst(const char* str, BSize start = 0) const;

		[[nodiscard]] string substring(const BSize& start, const BSize& end) const;

		[[nodiscard]] inline BSize getLength() const { return size; }

		inline iterator begin() { return iterator(0, *this); }

		inline iterator end() { return iterator(size, *this); }

		string& operator=(const string& other);

		friend std::ostream& operator<<(std::ostream& out, const string& obj);

		string& operator=(const char* cString);

		char& operator[](const BSize& index) const;

		bool operator==(const string&) const;

		~string();
	};
}
	