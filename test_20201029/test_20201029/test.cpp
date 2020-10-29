#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;


// 解决浅拷贝问题

#if 0
// 解决方式1---传统方法
class String
{
public:
	String(const char* str="")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};


#endif


#if 0
// 方式2：简洁版
class String
{
public:
	String(const char* str="")
	{
		if (str == nullptr)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);

	String s3("");

	s3=s1;
	return 0;
}

#endif


