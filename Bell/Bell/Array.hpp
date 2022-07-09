#pragma once
#include <ostream>
#include <stdexcept>

#include "Collection.h"

namespace bell
{
	namespace collections
	{
		template <class T>
		class Array final : public ICollection<T>
		{
			T* elements;

			// actual number of elements
			int size{};

			// how many elements there are in memory
			int capacity{};

			template <class T>
			T* duplicateArray(
				T* source,
				const int& new_size,
				const int& old_size
			)
			{
				if (new_size < old_size)
				{
					throw std::logic_error("New size cannot be smaller");
				}
				T* res = new T[new_size];
				for (size_t i = 0; i < old_size; i++)
				{
					res[i] = source[i];
				}

				return res;
			}

		public:
			T &operator[](const int& index)
			{
				if (index >= 0)
				{
					return elements[index];					
				}
				return elements[size + index];
			}

			Array()
			{
				this->size = 0;
				this->capacity = 0;
				elements = new T[0];
			}

			Array(const int& size) : size(size), capacity(size)
			{
				elements = new T[size];
			}

			Array(const Array<T>& other)
			{
				this->size = other.size;
				this->capacity = other.capacity;
				elements = duplicateArray(other.elements, capacity, size);
			}

			~Array() override
			{
				delete[] elements;
			}

			void insert(const int& index, const T& obj) override
			{
				throw std::logic_error("Not implemented");
			}

			int findFirst(const T& obj) override
			{
				for (size_t i = 0; i < size; i++)
				{
					if (elements[i] == obj)
					{
						return i;
					}
				}
				return -1;
			}

			int findFirst(std::function<bool(const T&)> fun) override
			{
				for (int i = 0; i < size; i++)
				{
					if (fun(elements[i]))
					{
						return i;
					}
				}
				return -1;
			}

			Array<int> findAll(const T& obj)
			{
				auto res = Array<int>();
				for (int i = 0; i < size; i++)
				{
					if(elements[i] == obj)
					{
						res.append(i);
					}
				}
				return res;
			}

			void remove(const T& obj) override
			{
				throw std::logic_error("Not implemented");
			}

			void remove(const std::function<bool(const T&)>& fun) override
			{
				throw std::logic_error("Not implemented");
			}

			void append(const T obj)
			{
				if (size < capacity)
				{
					elements[size++] = obj;
					return;
				}
				capacity == 0 ? capacity = 1 : capacity *= 2;
				const T* old = elements;
				elements = duplicateArray(elements, capacity, size);
				delete[] old;
				elements[size++] = obj;
			}

			template<class U>
			friend std::ostream& operator<<(std::ostream& os, const Array<U>& obj)
			{
				os << '[';
				for (int i = 0; i < obj.size - 1; i++)
				{
					os << obj.elements[i] << ", ";
				}
				os << obj.elements[obj.size - 1] << "]";
				return os;
			}
		};
	}
};
