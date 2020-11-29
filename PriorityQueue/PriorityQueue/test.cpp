#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
#include <queue>
#include <vector>
#include <functional>
// 优先级队列---堆排序
int main()
{
	// 优先级队列默认为：大堆
	priority_queue<int> p; // 初始化1
	p.push(0);
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	cout << p.size() << endl;
	cout << p.top() << endl;

	p.pop();
	cout << p.size() << endl;
	cout << p.top() << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	priority_queue<int> p1(v.begin(), v.end()); //初始化2
	cout << p1.size() << endl;
	cout << p1.top() << endl;

	vector<int> v1{ 9, 8, 7, 6, 0, 3, 4, 5 };
	// 小堆
	priority_queue<int, vector<int>, greater<int>> p2(v1.begin(), v1.end());
	cout << p2.size() << endl;
	cout << p2.top() << endl;

	return 0;
}
#endif

#include <queue>
#include <vector>
#include <functional>

// 自定义类型需要自己重载大于和小于
class Data
{
friend ostream& operator<<(ostream& _cout, const Data& d);

public:
	Data(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator <(const Data& d)const
	{
		return ((_year < d._year) ||
			(_year == d._year && _month < d._month)||
			(_year == d._year && _month == d._month&&_day < d._day));
	}

	bool operator>(const Data& d)const
	{
		return ((_year>d._year) ||
			(_year == d._year && _month>d._month) ||
			(_year == d._year && _month == d._month && _day > d._day));
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Data& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	// 大堆
	Data d1(2020, 10, 1);
	Data d2(2020, 11, 2);
	Data d3(2020, 11, 5);

	priority_queue<Data> p1;
	p1.push(d1);
	p1.push(d2);
	p1.push(d3);
	cout << p1.top() << endl;

	// 小堆
	priority_queue<Data, vector<Data>, greater<Data>> p2;
	p2.push(d1);
	p2.push(d2);
	p2.push(d3);
	return 0;
}

