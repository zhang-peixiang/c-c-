#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#if 0
class Data
{
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}
	Data(const Data& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	//不想将_count变成public，所以不能在类外进行访问
	//构造一个函数，使其可以在类外获得类的个数
	// static修饰的静态函数，不能访问类中的非静态成员变量和非静态成员函数
	static int Getcount()  // const --不能使用const来修饰，因为静态函数中没有this指针
	{
		// this._year = 10;

		return _count;
	}

	~Data()
	{
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;
	static int _count; //static 修饰成员变量
};

// 静态变量必须在类外的全局作用域中进行定义
int Data::_count = 0;

int main()
{
	Data d1(2020, 9, 10);
	Data d2(2020, 9, 11);
	Data d3(2020, 9, 12);
	Data d4(2020, 9, 13);
	Data d5(2020, 9, 14);

	// 访问类中的静态变量，直接类＋访问限定符进行访问
	cout << Data::Getcount() << endl;
	return 0;
}
#endif

#if 0
// 演示：<< 不能进行运算符重载
class Data
{
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void operator<<(ostream& _cout) // 调用此函数方法：d<<cout，不符合常用逻辑
	{
		_cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Data d(2020, 1, 1);
	d << cout; // 在类中进行 << 重载的结果
	return 0;
}
#endif


class Data
{
	// 友元函数
	// 注意：友元函数不是类的成员函数
	friend ostream& operator<<(ostream& _cout, Data& d);  // 友元函数
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, Data& d) // 必须要有返回值，因为会有连续打印的情况
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	Data d(2020, 9, 13);
	cout << d;
	return 0;
}

