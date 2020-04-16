#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

//打印菱形
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)//打印上半部分
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

//计算求和
//求Sn = a + aa + aaa + aaaa + aaaaa的前n项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
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


//求出0-100000自幂数
//指一个n位数，其各位数字的n次方之和正好等于该数本身，如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153
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
//		int n = 1;//n=1是因为任何数都至少是一位数
//		while (c/=10)//求i是几位数
//		{
//			n++;
//		}
//		for (j = 0; j < n; j++)
//		{
//			a = b % 10;
//			sum += pow(a, n);
//			b /= 10;
//		}
//		if (sum == i)//判断
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}
