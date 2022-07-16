#pragma once

namespace bell
{
	class string
	{
		char* chars;

	public:
		string();

		string(const string& other);

		string(const char* cString);

		string& operator=(const string& other);

		friend std::ostream& operator<<(std::ostream& out, const string& obj);

		string& operator=(const char* cString);

		~string();
	};
}
	