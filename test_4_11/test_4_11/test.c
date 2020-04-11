#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
////给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
//int numberOfSteps(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 0)
//		{
//			num /= 2;
//			count++;
//		}
//		else
//		{
//			num -= 1;
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	int num = 0;
//	scanf("%d", &num);
//	ret = numberOfSteps(num);
//	printf("%d\n", ret);
//	return 0;
//}

//给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
int subtractProductAndSum(int n)
{
	int i = 1;
	int j = 0;
	while (n)
	{
		i *= (n % 10);
		j += (n % 10);
		n /= 10;
	}
	return i - j;

}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = subtractProductAndSum(n);
	printf("%d\n", ret);
	return 0;
}




//int main()
//{
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(a));//16
	//printf("%d\n", sizeof(a + 0));//4
	//printf("%d\n", sizeof(*a));//4
	//printf("%d\n", sizeof(a + 1));//4
	//printf("%d\n", sizeof(a[1]));//4
	//printf("%d\n", sizeof(&a));//4
	//printf("%d\n", sizeof(*&a));//16
	//printf("%d\n", sizeof(&a + 1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0] + 1));//4

	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4
	//printf("%d\n", strlen(arr));//随机
	//printf("%d\n", strlen(arr + 0));//随机
	////printf("%d\n", strlen(*arr));//错误
	////printf("%d\n", strlen(arr[1]));//错误
	//printf("%d\n", strlen(&arr));//随机
	//printf("%d\n", strlen(&arr + 1));//随机
	//printf("%d\n", strlen(&arr[0] + 1));//随机

	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//7
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4

	//printf("%d\n", strlen(arr));//6
	//printf("%d\n", strlen(arr + 0));//6
	////printf("%d\n", strlen(*arr));//err
	////printf("%d\n", strlen(arr[1]));//err
	//printf("%d\n", strlen(&arr));//6
	//printf("%d\n", strlen(&arr + 1));//随机
	//printf("%d\n", strlen(&arr[0] + 1));//5

	//char *p = "abcdef";
	//printf("%d\n", sizeof(p));//4
	//printf("%d\n", sizeof(p + 1));//4
	//printf("%d\n", sizeof(*p));//1
	//printf("%d\n", sizeof(p[0]));//1
	//printf("%d\n", sizeof(&p));//4
	//printf("%d\n", sizeof(&p + 1));//4
	//printf("%d\n", sizeof(&p[0] + 1));//4

	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p + 1));//5
	////printf("%d\n", strlen(*p));//err
	////printf("%d\n", strlen(p[0]));//err
	//printf("%d\n", strlen(&p));//随机
	//printf("%d\n", strlen(&p + 1));//随机
	//printf("%d\n", strlen(&p[0] + 1));//5

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));//48
	//printf("%d\n", sizeof(a[0][0]));//4
	//printf("%d\n", sizeof(a[0]));//16
	//printf("%d\n", sizeof(a[0] + 1));//4
	//printf("%d\n", sizeof(*(a[0] + 1)));//4
	//printf("%d\n", sizeof(a + 1));//4 第二行的地址
	//printf("%d\n", sizeof(*(a + 1)));//16
	//printf("%d\n", sizeof(&a[0] + 1));//4
	//printf("%d\n", sizeof(*(&a[0] + 1)));//16
	//printf("%d\n", sizeof(*a));//16
	//printf("%d\n", sizeof(a[3]));//16


//	return 0;
//}


