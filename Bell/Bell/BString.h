#pragma once

#ifdef _MSC_VER
#define strdup(p) _strdup(p)
#endif



namespace bell
{
	class string
	{
		char* chars;

		int size;

	public:
		class iterator
		{
			int pos;
			string& object;
		public:
			iterator(const int& pos, string& obj);

			iterator& operator++();

			iterator& operator++(int);

			bool operator==(const iterator&) const;

			bool operator!= (const iterator&) const;

			char& operator*() const;
		};

		string();

		string(const string& other);

		string(const char* cString);

		inline int& getLength() { return size; }

		inline iterator begin() { return iterator(0, *this); }

		inline iterator end() { return iterator(size, *this); }

		string& operator=(const string& other);

		friend std::ostream& operator<<(std::ostream& out, const string& obj);

		string& operator=(const char* cString);

		char& operator[](const int& index) const;

		~string();
	};
	
}
	