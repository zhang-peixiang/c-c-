#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

using namespace std;

//class Data
//{
//public:
//	Data(int year=2020,	int month=1, int day=1)
//	{
//		// ���캯���У������Ǹ�ֵ�����ǳ�ʼ��
//		// �����Ƿ��ǳ�ʼ���ķ���
//		// 1. ���ã����ñ����ʼ��
//      // 2. const���εĳ�Ա����
//      // 3.���û���ʾ���幹�캯��ʱ���ڶԳ�Ա���г�ʼ��ʱ���������Ĭ�ϵĹ��캯��
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
//		// ���г�Ա��ʼ��
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
		// ���г�Ա��ʼ��˳�����������˳���й�
		// ��Ϊ��_month�ڳ�ʼ��ʱ��_day��δ��ʼ���������ֵ������_month��ʼ�����ʱ�ŵ������ֵ
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
		// ��Ϊ_day ��_month������������_day�ȳ�ʼ��������_month��ʼ����ֵ��Ϊ���ֵ���ŵ���_day��ֵ
		:_year(year)
		, _month(_day)
		, _day(day)
	{

	}

private: // ���������˳�����ʼ��˳���й�
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
	// ���εĹ��캯����������ת��������
	Data(int year)
		:_year(year)
		, _month(1)
		, _day(1)
	{
		cout << this << endl; //���ӡ���Σ���Ϊ������һ����_year=2020����ʱ����
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
	// 2020��int�ͣ�dΪData����int��d��ֵ��
	// ʵ���ǻᴴ��һ��_year = 2020 ����ʱData������d���и�ֵ�����εĹ��캯���ᷢ������ת��
	return 0;
}
#endif

#if 0
class Data
{
public:
	// ���εĹ��캯����������ת��������
	// �ڱ���У�Ϊ�˱��ⵥ�εĹ��캯����������ת��������ؼ���explicit����
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
	d = 2020; //����ؼ���explicit�󣬵��εĹ��캯����֧������ת��
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
	static int count; //static���εĳ�Ա��������֮Ϊ��̬��Ա��������Data�����ı������ɹ���
};

int Data::count = 0; //static���εĳ�Ա����������������г�ʼ��


void testdata()
{
	// d1,d2,d3,d4,d5����static���ε�count
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