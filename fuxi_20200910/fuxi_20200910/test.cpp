#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

// ���������
class Date
{
public:
	Date(int year=2020, int month=8, int day=1) //���캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) //�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// ǰ��++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//����++
	// ��Ϊ�Ǻ���++����Ҫ�Ƚ�this��ֵ��������������
	// Ȼ���ڽ���+1��������Ҫ�Ƚ�this���б����ڽ���+=1�Ĳ���

	// ������Ҫע����Ϊ����this��ֵΪջ�Ͽ��ٵĿռ䣬���Բ�����Date&���з��ء�
	Date operator++(int)
	{
		Date tmp = *this;
		_day += 1;
		return tmp;
	}


	// ��������ֵ�У����û�з���ֵ�����޷�����������ֵ
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


	// ��������ֵ�б���Ҫ�з���ֵ�� d3=d2=d1 �ȼ���d3.operator=��d2.operator(d1))
	// ��û�з���ֵʱ��ִ����d2.operator(d1)ʱ����ʽ�ͱ�Ϊd3.operator()
	d3 = d2 = d1;
	
	return 0;
}