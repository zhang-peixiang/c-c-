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

	//���뽫_count���public�����Բ�����������з���
	//����һ��������ʹ���������������ĸ���
	// static���εľ�̬���������ܷ������еķǾ�̬��Ա�����ͷǾ�̬��Ա����
	static int Getcount()  // const --����ʹ��const�����Σ���Ϊ��̬������û��thisָ��
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
	static int _count; //static ���γ�Ա����
};

// ��̬���������������ȫ���������н��ж���
int Data::_count = 0;

int main()
{
	Data d1(2020, 9, 10);
	Data d2(2020, 9, 11);
	Data d3(2020, 9, 12);
	Data d4(2020, 9, 13);
	Data d5(2020, 9, 14);

	// �������еľ�̬������ֱ���࣫�����޶������з���
	cout << Data::Getcount() << endl;
	return 0;
}
#endif

#if 0
// ��ʾ��<< ���ܽ������������
class Data
{
public:
	Data(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	void operator<<(ostream& _cout) // ���ô˺���������d<<cout�������ϳ����߼�
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
	d << cout; // �����н��� << ���صĽ��
	return 0;
}
#endif


class Data
{
	// ��Ԫ����
	// ע�⣺��Ԫ����������ĳ�Ա����
	friend ostream& operator<<(ostream& _cout, Data& d);  // ��Ԫ����
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

ostream& operator<<(ostream& _cout, Data& d) // ����Ҫ�з���ֵ����Ϊ����������ӡ�����
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

