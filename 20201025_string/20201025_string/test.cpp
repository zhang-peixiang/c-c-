#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;

#if 0
// �ַ���ֱ�ӱȴ�С----����Ƚϣ�ֱ��������ͬ���ַ�
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
 //s.c_str -----��c++ת��Ϊc���Է����׵�ַ
// atoi���������ַ���ת��Ϊint��

int main()
{
	string s1("12345");
	int value = atoi(s1.c_str());
	cout << value << endl;

	string s2("abcd");
	char* p = (char*)s2.c_str();
	*p = 'A';
	
	// string��С28----> size��capacity��char*  ����һ����СΪ16�Ŀռ�
	cout << sizeof(string) << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s;
	// cin�������룬�����ո��ֹͣ
	//cin >> s;
	//cout << s << endl;
	// getline���������ʱ�������ո񲻻�ֹͣ
	getline(cin, s);
	cout << s << endl;
	return 0;
}

#endif



