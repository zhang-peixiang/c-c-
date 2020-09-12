#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

using namespace std;

//class Data
//{
//public:
//	Data(int year=2020,	int month=1, int day=1)
//	{
//		// 构造函数中，这种是赋值，不是初始化
//		// 检验是否是初始化的方法
//		// 1. 引用，引用必须初始化
//      // 2. const修饰的成员变量
//      // 3.在用户显示定义构造函数时，在对成员进行初始化时，不会调用默认的构造函数
//		_year = year;
//		_month = month;
//		_day = day; 
//		&ra = _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	int& ra;
//};
//
//int main()
//{
//	Data d();
//	return 0;
//}

//class Data
//{
//public:
//	Data(int year, int month, int day)
//		// 类中成员初始化
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d(2020,1,1);
//	return 0;
//}

#if 0
class Data
{
public:
	Data(int year, int month, int day)
		// 类中成员初始化顺序跟类中声明顺序有关
		// 因为在_month在初始化时，_day还未初始化，是随机值。所以_month初始化完成时放的是随机值
		:_year(year)
		, _month(_day)
		, _day(day)
	{
		
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d(2020, 1, 1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	Data(int year, int month, int day)
		// 因为_day 比_month先声明，所以_day先初始化，这里_month初始化的值不为随机值，放的是_day的值
		:_year(year)
		, _month(_day)
		, _day(day)
	{

	}

private: // 这里的声明顺序与初始化顺序有关
	int _year;
	int _day;
	int _month;
	
};

int main()
{
	Data d(2020, 1, 1);
	return 0;
}
#endif

#if 0
class Data
{
public:
	// 单参的构造函数具有类型转换的作用
	Data(int year)
		:_year(year)
		, _month(1)
		, _day(1)
	{
		cout << this << endl; //会打印两次，因为构造了一次以_year=2020的临时变量
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d(1);
	d = 2020;
	// 2020是int型，d为Data，用int对d赋值，
	// 实质是会创建一个_year = 2020 的临时Data变量对d进行赋值，单参的构造函数会发生类型转换
	return 0;
}
#endif

#if 0
class Data
{
public:
	// 单参的构造函数具有类型转换的作用
	// 在编程中，为了避免单参的构造函数进行类型转换，加入关键字explicit即可
	explicit Data(int year)
		:_year(year)
		, _month(1)
		, _day(1)
	{
		cout << this << endl; 
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d(1);
	d = 2020; //加入关键字explicit后，单参的构造函数不支持类型转换
	return 0;
}
#endif


class Data
{
public:
	Data(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		count++;
	}
	Data(const Data& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		count++;
	}

	~Data()
	{
		count--;
	}
private:
	int _year;
	int _month;
	int _day;
public:
	static int count; //static修饰的成员变量，称之为静态成员变量，用Data创建的变量都可共用
};

int Data::count = 0; //static修饰的成员变量必须在类外进行初始化


void testdata()
{
	// d1,d2,d3,d4,d5共用static修饰的count
	Data d1(2020, 1, 1);
	cout << Data::count << endl;

	Data d2(2020, 1, 1);
	cout << Data::count << endl;

	Data d3(2020, 1, 1);
	cout << Data::count << endl;

	Data d4(2020, 1, 1);
	cout << Data::count << endl;

	Data d5(d1);
	cout << Data::count << endl;
}

int main()
{
	testdata();
	cout << Data::count << endl;
	return 0;
}