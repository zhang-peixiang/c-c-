#define _CRT_SECURE_NO_WARNINGS 1


#if 0
#include <stdio.h>

// �����ռ䣨namespace��

// ����namespace������
// ʹ�ã�
// 1.ֱ����N:: �����е���
// 2.using N:: 
// 3.using namespace N;  ��N�ռ�����б���������Ϊȫ�ֱ���
// ȱ�㣺2��3 ���ܻ������ͻ
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


// C++����������

// Ҫ����#include <iostream.h> ---�ɰ汾
//�����µı������� <iostream> + std (��׼�����ռ䣩

#include <iostream>
using namespace std;

#if 0 
int main()
{
	//���
	cout << 10 << endl; //---endl����
	cout << 12.34 << endl;
	cout << "abcder\n";
	cout << 666;
	cout << 888 << " " << "!!!" << endl;
	
	return 0;
}
#endif

//����
// ���cin�����������������ձ��������Ͳ�ƥ�䣬�򲻻Ὣ������õ����յı�����
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