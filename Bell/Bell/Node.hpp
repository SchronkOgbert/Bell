#pragma once
#include <ostream>

namespace bell
{
	namespace collections
	{
		template<class T>
		class Node
		{
			T key;
		public:
			Node<T>* Next{ nullptr };
			Node<T>* Prev{ nullptr };

			Node(const T& key) : key(key) {}

			Node(const Node& other)
				: key(other.key),
				  Next(other.Next),
				  Prev(other.Prev)
			{
			}

			Node(Node&& other) noexcept
				: key(std::move(other.key)),
				  Next(other.Next),
				  Prev(other.Prev)
			{
			}

			Node& operator=(const Node& other)
			{
				if (this == &other)
					return *this;
				key = other.key;
				Next = other.Next;
				Prev = other.Prev;
				return *this;
			}

			friend std::ostream& operator<<(std::ostream& os, const Node& obj)
			{
				return os << obj.key;
			}

			[[nodiscard]] T getKey() const { return key; }

			void setKey(const T& key) { this->key = key; }

			~Node()
			{
				delete Next;
				delete Prev;
			}
		};
	}
}
