#pragma once
#include <ostream>
#include <stdexcept>
#include <initializer_list>

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
			BSize size;


			// how many elements there are in memory
			BSize capacity;
			
			T* duplicateArray(
				T* source,
				const BSize& new_size,
				const BSize& old_size
			)
			{
				if (new_size < old_size)
				{
					throw std::logic_error("New size cannot be smaller");
				}
				T* res = new T[new_size];
				for (BSize i = 0; i < old_size; i++)
				{
					res[i] = source[i];
				}
				return res;
			}

		public:
			T& operator[](const int& index) const
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

			Array(const long long& size) : size(size), capacity(size)
			{
				elements = new T[size];
			}

			Array(const Array<T>& other)
			{
				this->size = other.size;
				this->capacity = other.capacity;
				elements = duplicateArray(other.elements, capacity, size);
			}

			Array(const std::initializer_list<T>& numbers)
			{
				this->size = 0;
				this->capacity = numbers.size();
				this->elements = new T[this->capacity];
				for (auto& el : numbers)
				{
					this->append(el);
				}
			}

			virtual ~Array()
			{
				delete[] elements;
			}

			void insert(const long long& index, const T& obj) override
			{
				this->append(obj);
				std::swap(elements[index], elements[size - 1]);
			}

			BSize findFirst(const T& obj) override
			{
				for (BSize i = 0; i < size; i++)
				{
					if (elements[i] == obj)
					{
						return i;
					}
				}
				return -1;
			}

			BSize findFirst(std::function<bool(const T&)> fun) override
			{
				for (BSize i = 0; i < size; i++)
				{
					if (fun(elements[i]))
					{
						return i;
					}
				}
				return -1;
			}

			std::shared_ptr<Array<int>> findAll(const T& obj)
			{
				std::shared_ptr<Array<int>> res(new Array<int>());
				for (int i = 0; i < size; i++)
				{
					if (elements[i] == obj)
					{
						res->append(elements[i]);
					}
				}
				return res;
			}

			std::shared_ptr<Array<int>> findAll(std::function<bool(const T&)> fun)
			{
				std::shared_ptr<Array<int>> res(new Array<int>());
				for (int i = 0; i < size; i++)
				{
					if (fun(elements[i]))
					{
						res->append(elements[i]);
					}
				}
				return res;
			}

			void removeAt(const long long& index) override
			{
				if (index >= size || index < 0) 
					throw std::out_of_range("index out of range");
				for (auto i = index; i < size - 1; i++)
				{
					elements[i] = elements[i + 1];
				}
				size--;
			}

			void remove(const T& obj) override
			{
				T* new_elements = new T[capacity];
				auto new_size = size;
				for (int i = 0, j = 0; i < size; i++)
				{
					if (elements[i] == obj)
					{
						new_size--;
						continue;
					}
					new_elements[j] = elements[i];
					j++;
				}
				size = new_size;
				delete[] elements;
				elements = new_elements;
			}

			void remove(const std::function<bool(const T&)>& fun) override
			{
				T* new_elements = new T[capacity];
				auto new_size = size;
				for (int i = 0, j = 0; i < size; i++)
				{
					if (fun(elements[i]))
					{
						new_size--;
						continue;
					}
					new_elements[j] = elements[i];
					j++;
				}
				size = new_size;
				delete[] elements;
				elements = new_elements;
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

			[[nodiscard]] BSize getSize() const
			{
				return size;
			}

			[[nodiscard]] T* getCArray() const { return this->elements; }

			// iterators
			class iterator
			{
				int pos;
				Array<T>& object;
			public:
				iterator(const int& pos, Array<T>& obj) : pos(pos), object(obj) {}

				iterator& operator++()
				{
					pos++;
					return *this;
				}

				iterator& operator++(int)
				{
					pos++;
					return *this;
				}

				T& operator*() const
				{
					return object[pos];
				}

				bool operator==(const iterator& other) const
				{
					return pos == other.pos;
				}

				bool operator!=(const iterator& other) const
				{
					return pos != other.pos;
				}
			};

			inline iterator begin() { return iterator(0, *this); }

			inline iterator end() { return iterator(size, *this); }
		};
		template <class U>
		std::ostream& operator<<(std::ostream& out, const Array<U>& obj)
		{
			if (obj.getSize())
			{
				out << '[';
				for (int i = 0; i < obj.getSize() - 1; i++)
				{
					out << obj[i] << ", ";
				}
				out << obj[obj.getSize() - 1] << "]";
			}
			else
			{
				out << "[]";
			}
			return out;
		}
		
	}
};
