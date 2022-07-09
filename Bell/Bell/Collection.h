#pragma once
#include <functional>

namespace bell
{
	namespace collections
	{
		template <class T>
		class ICollection
		{
		public:
			virtual ~ICollection() = default;

			virtual void insert(const int& index, const T& obj) = 0;

			virtual int findFirst(const T& obj) = 0;

			virtual int findFirst(std::function<bool(const T&)> fun) = 0;

			virtual void remove(const T& obj) = 0;

			virtual void remove(const std::function<bool(const T&)>& fun) = 0;
		};
	}
}
