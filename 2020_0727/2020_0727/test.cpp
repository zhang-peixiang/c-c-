#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include <stdio.h>

// 命名空间（namespace）

// 利用namespace来定义
// 使用：
// 1.直接用N:: 来进行调用
// 2.using N:: 
// 3.using namespace N;  将N空间的所有变量都定义为全局变量
// 缺点：2和3 可能会引起冲突
namespace N
{
	int a = 10;
	int Add(int left, int right)
	{
		return left + right;
	}
}

using N::Add;
int main()
{
	printf("%d\n", N::a);

	printf("%d\n", Add(10, 20));
	return 0;
}

#endif


// C++的输入和输出

// 要包含#include <iostream.h> ---旧版本
//现在新的编译器： <iostream> + std (标准命名空间）

#include <iostream>
using namespace std;

#if 0 
int main()
{
	//输出
	cout << 10 << endl; //---endl换行
	cout << 12.34 << endl;
	cout << "abcder\n";
	cout << 666;
	cout << 888 << " " << "!!!" << endl;
	
	return 0;
}
#endif

//输入
// 如果cin检测道输入的数据与接收变量的类型不匹配，则不会将输入放置到接收的变量中
int main()
{
	int a, b;
	float c;
	char d;

	cin >> a;
	cout << a << endl;

	cin >> a >> b;
	cout << a << " " << b << endl;

	cin >> a >> c >> d;
	cout << a << " " << c << " " << d << endl;
	return 0;
 }