#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//��ӡ����
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)//��ӡ�ϰ벿��
	{
		int j = 0;
		for (j = 1; j < n-i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 1+2*i ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		for (j = 0; j < i+1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2*n-3-2*i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//�������
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰn��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	int sum = 0;
//	scanf("%d%d", &a,&b);
//	int c = a;
//	for (i = 1; i <= b; i++)
//	{
//	/*	c = 10 *c + a;
//		sum += c;*/
//		sum += c;
//		c = a*pow(10, i) + c;
//		
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//


//���0-100000������
//ָһ��nλ�������λ���ֵ�n�η�֮�����õ��ڸ���������:153��1 ^ 3��5 ^ 3��3 ^ 3����153
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++)
//	{
//		int a = 0;
//		int b = i;
//		int c = i;
//		int sum = 0;
//		int j = 0;
//		int n = 1;//n=1����Ϊ�κ�����������һλ��
//		while (c/=10)//��i�Ǽ�λ��
//		{
//			n++;
//		}
//		for (j = 0; j < n; j++)
//		{
//			a = b % 10;
//			sum += pow(a, n);
//			b /= 10;
//		}
//		if (sum == i)//�ж�
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}
