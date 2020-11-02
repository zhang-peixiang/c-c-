#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

namespace bite
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		///构造-重载-析构/////
		string(const char* s="")
		{
			if (s == nullptr)
				s = "";
			_size = strlen(s);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, s);
		}
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s);
			this->Swap(tmp);
		}
		string operator = (string s)
		{
			this->Swap(s);
		}
		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}
		////迭代器////
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		////方法////
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		string& operator+=(char* str)
		{
			size_t sz = strlen(str);
			if (_size + sz >= _capacity)
			{
				reserve(_capacity * 2);
			}
			strcpy(_str + _size, str);
			_size += sz;
			return *this;
		}

		
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}


		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		////capacity////
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		void resize(size_t newsize, char c = '\0')
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_str[newsize] = '\0';
			_size = newsize;
		}
		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_capacity = newcapacity;
				_str = tmp;
			}
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}

int main()
{
	bite::string s("hello");
	char str[] = "world";
	string s1("abcde");
	s1.resize(3);
	s += str;
	return 0;
}