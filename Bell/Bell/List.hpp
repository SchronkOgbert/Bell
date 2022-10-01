#pragma once
#include "Node.hpp"

namespace bell
{
	namespace collections
	{
		template<class T>
		class List : public ICollection<T>
		{
			Node<T>* head{ nullptr };
			Node<T>* tail{ nullptr };
			BSize size = 0;
		public:
			List() = default;

			void insert(const long long& index, const T& obj) override
			{
				if (index >= size && size || index < 0)
				{
					throw std::out_of_range("You are trying to insert outside the bounds");
				}
				if (index == 0)
				{
					insert(obj);
					return;
				}
				long long current = index;
				Node<T>* walker = head;
				while (current)
				{
					walker = walker->Next;
					current--;
				}
				auto newNode = new Node<T>(obj);
				newNode->Prev = walker->Prev;
				newNode->Next = walker;
				if (walker->Prev)
				{
					walker->Prev->Next = newNode;
				}
				walker->Prev = newNode;
			}

			void insert(const T& obj)
			{
				if (!head)
				{
					head = new Node<T>(obj);
					tail = head;
					size = 1;
					return;
				}
				tail->Next = new Node<T>(obj);
				tail->Prev->Next = tail;
				tail = tail->Next;
				size++;
			}

			BSize findFirst(const T& obj) override
			{
				throw std::logic_error("Not implemented");
			}
			BSize findFirst(std::function<bool(const T&)> fun) override
			{
				throw std::logic_error("Not implemented");
			}
			void removeAt(const long long& index) override
			{
				throw std::logic_error("Not implemented");
			}
			void remove(const T& obj) override
			{
				
			}
			void remove(const std::function<bool(const T&)>& fun) override
			{
				throw std::logic_error("Not implemented");
			}

			bool empty() override
			{
				return !size;
			}

			T operator[](long long&& index) const
			{
				if (index >= size)
				{
					throw std::out_of_range("Given index is out of range");
				}
				Node<T>* walker = head;
				while(index)
				{
					walker = walker->Next;
					index--;
				}
				return walker->getKey();
			}
		};
	}
}
