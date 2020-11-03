#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <assert.h>
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

		const char* c_str()const
		{
			return _str;
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
		bool empty()const
		{
			return _size == 0;
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

		////access////
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////relational operators////
		bool operator<(const string& s)
		{
			if (strcmp(_str, s._str)>=0)
			{
				return false;
			}
			return true;
		}
		bool operator<=(const string& s)
		{
			if (strcmp(_str, s._str)>0)
			{
				return false;
			}
			return true;
		}

		bool operator>(const string& s)
		{
			if (strcmp(_str, s._str) > 0)
				return true;
			return false;
		}

		bool operator>=(const string& s)
		{
			if (strcmp(_str, s._str) < 0)
			{
				return false;
			}
			return true;
		}

		bool operator==(const string& s)
		{
			if (strcmp(_str, s._str) == 0)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const string& s)
		{
			if (strcmp(_str, s._str) == 0)
			{
				return false;
			}
			return true;
		}

		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return -1;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			assert(s);
			assert(pos < _size);

			char* src = _str + pos;
			while (src)
			{
				const char* tmp = s;
				char* src1 = src;
				while (src1 && *src == *tmp)
				{
					++src1;
					++tmp;
				}
				if (*src1 == '\0'&& *tmp=='\0')
				{
					return src - _str;
				}
				else
				{
					++src;
				}
			}
			return -1;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			assert(pos < _size);
			if (_size == _capacity)
				reserve(_capacity*2);
			size_t tmp = _size - 1;
			while (tmp >= pos)
			{
				_str[tmp + 1] = _str[tmp];
				--tmp;
			}
			_str[pos] = c;
			_size += 1;
			_str[_size] = '\0';
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t sz = strlen(str);
			int tmp =(int) _size;
			if (_size + sz>_capacity)
			{
				reserve(_size + sz);
			}
			while (tmp >= (int)pos)
			{
				_str[tmp + sz] = _str[tmp];
				tmp--;
			}
			strncpy(_str + pos, str,sizeof(char)*sz);
			_size += sz;
			return *this;
		}



		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			assert(pos < _size);
			for (int i = pos; i < _size - len; ++i)
			{
				if (i + len<_size)
				{
					_str[i] = _str[i + len];
				}
				else
				{
					_str[i] = '\0';
				}
			}
			if (pos + len>_size)
			{
				_size = pos;
			}
			else
			{
				_size -= len;
			}
			_str[_size] = '\0';
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}



#if 0
int main()
{
	bite::string s("hello");
	char str[] = "world";
	 s1("abcde");
	s1.resize(3);
	s += str;
	s1.find('a', 2);
	return 0;
}
#endif

int main()
{
	bite::string s("hello");
	char s1[] = "world";
	s.insert(0, s1);
	s.erase(6, 5);
	return 0;
}