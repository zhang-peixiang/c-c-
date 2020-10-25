#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

#if 0
// 字符串直接比大小----逐个比较，直到遇到不同的字符
int main()
{
	string s1("hello");
	string s2("world");

	if (s1 > s2)
	{
		cout << "s1 > s2" << endl;
	}
	else if (s1 < s2)
	{
		cout << "s1 < s2" << endl;
	}
	return 0;
}
#endif

#if 0
 //s.c_str -----将c++转换为c语言返回首地址
// atoi函数，将字符串转换为int型

int main()
{
	string s1("12345");
	int value = atoi(s1.c_str());
	cout << value << endl;

	string s2("abcd");
	char* p = (char*)s2.c_str();
	*p = 'A';
	
	// string大小28----> size、capacity、char*  还有一个大小为16的空间
	cout << sizeof(string) << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s;
	// cin用来输入，遇到空格会停止
	//cin >> s;
	//cout << s << endl;
	// getline来获得输入时，遇到空格不会停止
	getline(cin, s);
	cout << s << endl;
	return 0;
}

#endif



