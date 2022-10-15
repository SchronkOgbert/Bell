#pragma once
#include <initializer_list>
#include <stdexcept>

#include "Collection.h"

namespace bell::collections
{
	template <class T>
	class Queue final : public ICollection<T>
	{
		struct Node
		{
			T value;
			Node *prev, *next;
			Node(const T& value, Node* prev = nullptr, Node* next = nullptr) :
			value(value), prev(prev), next(next) {}
		};
		Node *head, *tail;
	public:
		Queue()
		{
			head = nullptr;
			tail = nullptr;
		}
		Queue(const std::initializer_list<T>& elements)
		{
			head = nullptr;
			tail = nullptr;
			for (auto& el : elements)
			{
				this->push(el);
			}
		}

		void push_back(const T& element)
		{
			tail = new Node(element, tail);
			if (!head) head = tail;
		}

		void pop_front()
		{
			
		}

		T back()
		{
			if (!tail) throw std::exception("Queue is empty");
			return tail->value;
		}

		bool empty() override
		{
			return !head;
		}

		void insert(const long long& index, const T& obj) override
		{
			throw std::logic_error("Please use Queue::push_back to add elements");
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
