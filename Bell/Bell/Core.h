#pragma once
#include <iostream>
#include <string>

namespace bell
{
	namespace core
	{
		// print functions
		template<class T>
		void print(const T& t)
		{
			std::cout << t;
		}

		template<class T>
		void print(const T&& t)
		{
			std::cout << t;
		}

		template<class T>
		void print(T* t)
		{
			std::cout << *t;
		}

		template <class T, class ... TAIL>
		void print(const T& t, TAIL... tail)
		{
			print(t);
			print(tail...);
		}

		template <class T, class ... TAIL>
		void print(const T&& t, TAIL... tail)
		{
			print(t);
			print(tail...);
		}

		template<class T, class ...TAIL>
		void print(T* t, TAIL... tail)
		{
			print(t);
			print(tail...);
		}

		template<class T>
		void println(const T& t)
		{			
			print(t, '\n');
		}

		template<class T>
		void println(const T&& t)
		{
			print(t, '\n');
		}

		template<class T>
		void println(T* t)
		{
			print(t, '\n');
		}

		template<class T, class ...TAIL>
		void println(const T& t, TAIL... tail)
		{
			print(t);
			println(tail...);
		}

		template<class T, class ...TAIL>
		void println(const T&& t, TAIL... tail)
		{
			print(t);
			println(tail...);
		}

		template<class T, class ...TAIL>
		void println(T* t, TAIL... tail)
		{
			print(t);
			println(tail...);
		}

		template<class T>
		T& read(const std::string& message)
		{
			T res;
			print(message);
			std::cin >> res;
			return res;
		}

		//overloaded << for shared ptr and unique ptr
		template<class T>
		std::ostream& operator<<(std::ostream& out, const std::shared_ptr<T>& obj)
		{
			return out << *obj;
		}

		template <class T>
		std::ostream& operator<<(std::ostream& out, std::unique_ptr<T>& obj)
		{
			return out << *obj;
		}
	}
}

