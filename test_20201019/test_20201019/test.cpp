#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


#if 0
// ��̬���� new �� delete
// new ��malloc����
// c�����е�malloc��calloc �ڿ��ٿռ��ǲ�����ù��캯������free���ͷſռ�ʱ�����������������

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
// ģ��
// ģ���ڲ�����ʱ����ռ���ڴ�ռ䡣 
// �ڵ�����ͬģ��ʱ��ֻ������һ��

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


// ����
void teststring1()
{
	string s1;
	//s1 = "world";
	string s2("hello world");
	string s3("hello", 2);
	string s4(s2);
	string s5(10, 'a');

}

// ����
void teststring2()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;  //length��size ����һ��
	cout << s1.capacity() << endl;

	if (s1.empty())
	{
		cout << "���ַ���" << endl;
	}
	else
	{
		cout << "�ǿ��ַ���" << endl;
	}

	s1.clear();

	if (s1.empty())
	{
		cout << "���ַ���" << endl;
	}
	else
	{
		cout << "�ǿ��ַ���" << endl;
	}
}


// resize
void teststring3()
{
	string s1("hello");

	// Ĭ���� '\0' ����
	s1.resize(10);

	// ����Ч�ַ�������15�����󲿷��ã����
	s1.resize(15, '!');

	// ����Ч�ַ�������capacityʱ�����������
	s1.resize(30, '#');

	// ��С
	s1.resize(20, '*');

	s1 += "world";

	s1.resize(15);
}



int main()
{
	teststring3();

	return 0;
}