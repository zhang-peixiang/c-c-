#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// 运算符重载
class Date
{
public:
	Date(int year=2020, int month=8, int day=1) //构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) //拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 前置++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++
	// 因为是后置++，需要先将this的值赋给其他参数，
	// 然后在进行+1，所以需要先将this进行保存在进行+=1的操作

	// 这里需要注意因为保存this的值为栈上开辟的空间，所以不能用Date&进行返回。
	Date operator++(int)
	{
		Date tmp = *this;
		_day += 1;
		return tmp;
	}


	// 在连续赋值中，如果没有返回值，将无法进行连续赋值
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	
	Date d1(2020, 8, 12);
	Date d2;
	Date d3;


	// 在连续赋值中必须要有返回值。 d3=d2=d1 等价于d3.operator=（d2.operator(d1))
	// 当没有返回值时，执行完d2.operator(d1)时，上式就变为d3.operator()
	d3 = d2 = d1;
	
	return 0;
}