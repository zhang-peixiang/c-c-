#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


#if 0
// reverse---字符串逆置
// sort---排序
// s.begin\s.end---迭代器
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
// 遍历字符串的三种方式
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

	// 迭代器--正向
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// 迭代器--反向
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