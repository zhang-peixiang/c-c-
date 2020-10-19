#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


#if 0
// 动态管理 new 和 delete
// new 和malloc区别
// c语言中的malloc和calloc 在开辟空间是不会调用构造函数，用free来释放空间时不会调用析构函数。

struct data
{
public:
	data(int year=2020, int month=10, int day=19)
		:_year(year),
		_month(month),
		_day(day)
	{
		cout << "data" << endl;
	}

	~data()
	{
		cout << "~data" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	int* a = new int[10];
	int* ptr = new int;
	int* ptr1 = new int(0);

	data* b = new data(1, 1, 1);
	data* c = new data();

	data* d = new data[5];


	delete[] a;
	delete b;
	delete c;
	delete[] d;
	return 0;
}

#endif

#if 0
// 模板
// 模板在不调用时，不占用内存空间。 
// 在调用相同模板时，只会生成一份

template <class T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);

	return 0;
}
#endif


// 构造
void teststring1()
{
	string s1;
	//s1 = "world";
	string s2("hello world");
	string s3("hello", 2);
	string s4(s2);
	string s5(10, 'a');

}

// 容量
void teststring2()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;  //length和size 作用一样
	cout << s1.capacity() << endl;

	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}

	s1.clear();

	if (s1.empty())
	{
		cout << "空字符串" << endl;
	}
	else
	{
		cout << "非空字符串" << endl;
	}
}


// resize
void teststring3()
{
	string s1("hello");

	// 默认用 '\0' 补齐
	s1.resize(10);

	// 将有效字符串增大到15，增大部分用！填充
	s1.resize(15, '!');

	// 在有效字符串大于capacity时，会进行扩容
	s1.resize(30, '#');

	// 缩小
	s1.resize(20, '*');

	s1 += "world";

	s1.resize(15);
}



int main()
{
	teststring3();

	return 0;
}