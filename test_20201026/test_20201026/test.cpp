#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#if 0
// reverse---�ַ�������
// sort---����
// s.begin\s.end---������
int main()
{
	string s("hello");

	reverse(s.begin(), s.end());
	cout << s << endl;

	sort(s.begin(), s.end());
	cout << s << endl;

	return 0;
}
#endif

#if 0
// �����ַ��������ַ�ʽ
int main()
{
	string s("hello");

	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ������--����
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// ������--����
	auto rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;


	return 0;
}
#endif