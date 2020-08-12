#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//���������
class Date
{
public:
	Date(int year, int month, int day)
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
	
	Date& operator++() //ǰ��++
	{
		_day += 1;
		return *this;
	}
	//����++ �����ز���ֻ��ΪDate ���ܷ���Date&����Ϊtmp����ջ�Ͽ��ٵĿռ�,�������˳�ʱ��tmp�ͻᱻ����
	// ����++ �����б�����һ��int�Ͳ��������Բ�����
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
	d2 = d1.operator++(); //��ֱ����++ʱ����д�����������ڵ���operatorʱ������++�ü�һ�����Ͳ�����

	Date d3 = d1++;
	d3 = d1.operator++(0);

	return 0;
}
#endif



#if 0
//��ֵ���������
//����û�û����ʾ���壬�������������һ��Ĭ�ϵĸ�ֵ��������غ���
// ע�⣺�������ǰ���ǳ�����ķ�ʽ���ɵĸ�ֵ���������
// �������δ�漰����Դ����ʱ����ֵ����������Ƿ��ṩ����ʹ�ñ༭��Ĭ�ϵ��ǲ�����������
// ��������漰����Դ����ʱ�����û�����Ҫ��ʽ�ṩ��ֵ��������أ�
// ����ͻᵼ�� 1.��Դй¶ 2.ͬһ����Դ������������ڶ�������ʱ��һ����Դ���ͷŶ�ζ�����������

class Date
{
public:
	Date(int year=2020, int month=8, int day=1)
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

	//����ֵ���⣬a=b=c ��������ֵ�У����û�з���ֵ��������������ֵ
	Date& operator=(const Date& d) 
	{
		// �����Լ����Լ���ֵ
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this; 
		//����this���Ƿ���d������   ��a=b=c�У���c��b��ֵ��Ȼ��b�ٸ�a��ֵ���������ﷵ��this
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


// const���α�����
/*
��c�����У���const���ε���һ�����ܱ��޸ĵı���
	���ԣ� const int a=10; int arr[a];  ������ܶ���ɹ�����һ��������������� ��aΪ����

�� c++�У���const���ε���һ�����������к��滻������
	void TestConst()
	{
		const int a=10;
		int* pa=(int*) &a;

		*pa=100;
		cout<<a<<endl; //10  ԭ������Ϊ�ڱ���׶��Ѿ���a��10�滻
		cout<<*pa<<endl; //100

	}

const ���εĳ������滻�����ڱ���׶Σ������������ͼ�⣬����İ�ȫ�Ը�
���飺��c++��ʹ��const���εĳ�������곣��
*/

/*
��c++�У�constҲ����������ĳ�Ա
1. const������ĳ�Ա�����������ó�Ա���ܱ��޸�
2. const������ĳ�Ա������������������>��Ϊconst���͵ĳ�Ա����
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
	Date(const Date& d) //�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��const���εĳ�Ա������Ϊconst���͵ĳ�Ա����
	// const��Ա�����в����޸���ġ���Ա������
	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		// _day++;
		// _month++;
		cout << typeid(this).name() << endl; //��ӡ����
	}
private:
	int _year;
	int _month;
	mutable int _day;
	/*
	mutable:���ʺ����ʾ�ɱ�
	���γ�Ա����ʱ�������ó�Ա����������const��Ա�����б��޸�
	*/
};

int main()
{
	Date d;
	d.PrintDate();
	return 0;
}