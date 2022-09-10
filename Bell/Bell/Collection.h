#pragma once
#include <functional>
typedef long long BSize;

namespace bell
{
	namespace collections
	{
		template <class T>
		class ICollection
		{
		public:
			virtual void insert(const long long& index, const T& obj) = 0;

			virtual BSize findFirst(const T& obj) = 0;

			virtual BSize findFirst(std::function<bool(const T&)> fun) = 0;

			virtual void removeAt(const long long& index) = 0;

			virtual void remove(const T& obj) = 0;

			virtual void remove(const std::function<bool(const T&)>& fun) = 0;
		};
	}
}
