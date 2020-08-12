#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//运算符重载
class Date
{
public:
	Date(int year, int month, int day)
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
	
	Date& operator++() //前置++
	{
		_day += 1;
		return *this;
	}
	//后置++ ，返回参数只能为Date 不能返回Date&，因为tmp是在栈上开辟的空间,当函数退出时，tmp就会被销毁
	// 后置++ 括号中必须有一个int型参数，可以不命名
	Date operator++(int)
	{
		Date tmp = *this;
		_day += 1;
		return tmp;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 12);
	Date d2 = ++d1;
	d2 = d1.operator++(); //在直接用++时不用写参数，但是在调用operator时，后置++得加一个整型参数。

	Date d3 = d1++;
	d3 = d1.operator++(0);

	return 0;
}
#endif



#if 0
//赋值运算符重载
//如果用户没有显示定义，则编译器会生成一份默认的赋值运算符重载函数
// 注意：编译器是按照浅拷贝的方式生成的赋值运算符重载
// 如果类中未涉及到资源管理时，赋值运算符重载是否提供或者使用编辑器默认的是不会出现问题的
// 如果类中涉及到资源管理时，则用户必须要显式提供赋值运算符重载，
// 否则就会导致 1.资源泄露 2.同一份资源被多个对象共享，在对象销毁时，一份资源被释放多次而引起程序崩溃

class Date
{
public:
	Date(int year=2020, int month=8, int day=1)
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

	//返回值问题，a=b=c 在连续赋值中，如果没有返回值，将不能连续赋值
	Date& operator=(const Date& d) 
	{
		// 避免自己给自己赋值
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this; 
		//返回this还是返回d的问题   在a=b=c中，是c给b赋值，然后b再给a赋值，所以这里返回this
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

	d3 = d2 = d1;
	return 0;
}
#endif


// const修饰变量：
/*
在c语言中，被const修饰的是一个不能被修改的变量
	测试： const int a=10; int arr[a];  如果不能定义成功就是一个变量，如果可以 即a为常量

在 c++中，被const修饰的是一个常量，具有宏替换的属性
	void TestConst()
	{
		const int a=10;
		int* pa=(int*) &a;

		*pa=100;
		cout<<a<<endl; //10  原因是因为在编译阶段已经将a用10替换
		cout<<*pa<<endl; //100

	}

const 修饰的常量的替换发生在编译阶段，会参与参数类型检测，代码的安全性高
建议：在c++中使用const修饰的常量代替宏常量
*/

/*
在c++中，const也可以修饰类的成员
1. const修饰类的成员变量，表明该成员不能被修改
2. const修饰类的成员函数，——————>称为const类型的成员函数
*/



class Date
{
public:
	Date(int year = 2020, int month = 8, int day = 1)
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

	// 被const修饰的成员函数称为const类型的成员函数
	// const成员函数中不能修改类的“成员变量”
	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		// _day++;
		// _month++;
		cout << typeid(this).name() << endl; //打印类型
	}
private:
	int _year;
	int _month;
	mutable int _day;
	/*
	mutable:单词含义表示可变
	修饰成员变量时，表明该成员变量可以在const成员函数中被修改
	*/
};

int main()
{
	Date d;
	d.PrintDate();
	return 0;
}