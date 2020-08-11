#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


#if 0
class String
{
public:
	String(const char* str=" ")
	{
		int len = strlen(str);
		if (str == nullptr)
		{
			str = "";
		}
		_str = (char*)malloc(len + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};


int main()
{
	String s1("hello");
	String s2(s1);//浅引用，报错
	return 0;
}


#endif


#if 0
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d) //拷贝构造函数，必须是Date& 形式，如果按传值的方式，会造成无限递归
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2020, 8, 11);
	Date d2(d1);
	return 0;
}

#endif


//运算符重载 operator+运算符
class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date d)
	{
		if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
			return true;
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 7);
	Date d2(d1);
	Date d3(2020, 8, 11);

	if (d1 < d3)
		cout << "d1 < d3" << endl;
	return 0;
}