#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;
#include <queue>
#include <stack>

// stack
void Test1()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
}

// queue
void Test2()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;
	
	q.pop();
	q.pop();

	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;
}



int main()
{
	// Test1();
	Test2();
	return 0;
}