#include <iostream>
#include <string>
using namespace std;


// ���ǳ����
// ��ʽ1����ͳ��

class String{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator= (String s)
	{
		if (_str != s._str)
		{
			char* tmp = new char[strlen(s._str) + 1];
			_str = tmp;
			strcpy(_str, s._str);
		}
		return *this;
	}


	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}


private:
	char* _str;
};