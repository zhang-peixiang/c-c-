#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

// ����
void Test1()
{
	vector<int> v1;
	vector<int> v2(5, 10);
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v3(arr, arr+sizeof(arr)/sizeof(arr[0]));
	auto it = v3.begin();
	while(it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	vector<int> v4{ 1, 2, 3, 4, 5 };
	// e�Ƕ�ÿ��Ԫ�ص�����
	for (auto& e : v4)
	{
		e += 1;
		cout << e <<" ";
	}
	cout << endl;
	// e�Ƕ�ÿ��Ԫ�ص�һ�ݿ���
	vector<int> v5(v3);
	for (auto e : v5)
		cout << e << " ";
	cout << endl;
}

// ����
void Test2()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	
	if (v1.empty())
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "not empty" << endl;
	}

	v1.resize(3);
	cout << v1.size() << endl;
	v1.resize(6, 3);
	cout << v1.size() << endl;

	v1.reserve(5); // ��newcapacity<oldcapacityʱ��capacity=oldcapacity
	v1.reserve(20);	// ��newcapacity>oldcapacityʱ��capacity=newcapacity

	v1.clear();
	
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

}

void Test3()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	auto it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << v1.front() << endl;
	cout << v1.back() << endl;

	v1.clear();

	// front()��back()����vector��Ԫ��ʱ��vectorһ������Ϊ��
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}

void Test4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();

	for (auto e : v1)
		cout << e << " ";

}

// ����λ�ò��룺����
void Test5()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	v1.insert(v1.begin(), 6);
	v1.insert(v1.begin()+2, 7);

	v1.insert(find(v1.begin(), v1.end(), 2), 8);
	int arr[] = { 9, 10, 11 };
	v1.insert(v1.end(), arr, arr + sizeof(arr) / sizeof(arr[0]));

	v1.erase(v1.begin());
	v1.erase(v1.begin(), v1.begin() + 2);
}


// �����ά����
void Test6()
{
	vector<vector<int>> vv(4, vector<int>(5, 10)); //4��5�� ÿ��Ԫ����10
}

// �������
void Test7(int n)
{
	vector<vector<int>> vv;
	vv.resize(n);
	for (int i = 0; i < n; ++i)
	{
		vv[i].resize(i+1, 1);
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << vv[i][j] << "  ";
		}
		cout << endl;
	}

}

int main()
{
	//Test1();
	//Test2();
	// Test3();
	// Test4();
	// Test5();
	//Test6();
	Test7(5);

	return 0;
}