#pragma once
#include <initializer_list>
#include <stdexcept>

#include "Collection.h"

namespace bell::collections
{
	template <class T>
	class Stack final : ICollection<T>
	{
		struct Node
		{
			T value;
			Node* prev;
			Node(const T& value, Node* prev = nullptr) : value(value), prev(prev) {}
		};
		Node* root;
	public:
		Stack()
		{
			root = nullptr;
		}
		Stack(const std::initializer_list<T>& elements)
		{
			root = nullptr;
			for(auto& el : elements)
			{
				this->push(el);
			}
		}

		void push(const T& element)
		{
			root = new Node(element, root);
		}

		void pop()
		{
			const Node* old_root = root;
			root = root->prev;
			delete old_root;
		}

		T top()
		{
			if (!root) throw std::exception("Queue is empty");
			return root->value;
		}

		bool empty() override
		{
			return !root;
		}

		void insert(const long long& index, const T& obj) override
		{
			throw std::logic_error("Not implemented");
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
			throw std::logic_error("Not implemented");
		}
		void remove(const std::function<bool(const T&)>& fun) override
		{
			throw std::logic_error("Not implemented");
		}
	};
}