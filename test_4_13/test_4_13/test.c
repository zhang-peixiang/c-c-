#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//int cmpWords(char* s1,char* s2)
//{
//	int i = 0;
//	int j = 0;
//	int sz = strlen(s1);
//	if (strcmp(s1, s2) == 0)//比较俩个字符串
//	{
//		return 1;
//	}
//	
//	for (j = 1; j < sz; j++)
//	{
//		int n = 1;//每次向后面旋转一个字符 比如abcdef 第一次bcdefa 第二次edefab ····
//		for (i = 0; i < sz / 2; i++)//先将字符串逆置
//		{
//			char ret = *(s1 + i);
//			*(s1 + i) = *(s1 + sz - 1 - i);
//			*(s1 + sz - 1 - i) = ret;
//		}
//		for (i = 0; i < (sz - n) / 2; i++)//交换sz-n之前的字符，使其成为顺序
//		{
//			char ret = *(s1 + i);
//			*(s1 + i) = *(s1 + sz - 1 - n - i);
//			*(s1 + sz - 1 - n - i) = ret;
//		}
//		for (i = 0; i < n / 2; i++)//交换sz-n之后的字符，使其成为顺序
//		{
//			char ret = *(s1 + sz - n + i);
//			*(s1 + sz - n + i) = *(s1 + sz - 1 - i);
//			*(s1 + sz - 1 - i) = ret;
//		}
//		printf("%s\n", s1);
//		if (strcmp(s1, s2) == 0)//比较俩个字符串
//		{
//			return 1;
//		}
//		
//	}
//	return 0;
//}
//
//int main()
//{
//	char s1[] = "abcdef";
//	char s2[] = "bcdefa";
//	int ret = cmpWords(s1, s2);
//	printf("%d\n", ret);
//	return 0;
//}


//杨氏矩阵
//void findnum(int arr[][4], int x, int y, int n)
//{
//	int a = 0;
//	int i = 0;
//	int j = 0;
//	for (a = 0; a < y; a++)
//	{
//		if (arr[x-1][j] < n)//判断n是否在最后一行
//		{
//			for (j = 0; j < y; j++)
//			{
//				if (arr[x-1][j] == n)
//				{
//					printf("找到了\n");
//					break;
//				}
//			}
//			break;
//		}
//		else if (arr[i][j]<n&&arr[i + 1][j]>n)//判断n是否在某一行和某一行+1 之间
//		{
//			for (j = 0; j<y; j++)
//			{
//				if (arr[i][j] == n)
//				{
//					printf("找到了\n");
//					break;
//				}
//			}
//			break;
//		}
//		else if (arr[i][j] > n)
//			{
//				i--;
//			}
//		else if (arr[i][j] == n)
//		{
//			printf("找到了\n");
//			break;
//		}
//		else
//			{
//				i++;
//			}
//		}
//	
//	printf("找不到");
//}
//
//int main()
//{
//	int arr[3][4] = { { 1, 2, 4, 5 },
//					{ 6, 7, 8, 9 },
//					{ 10, 11, 12, 13 } };
//	int n = 0;
//	scanf("%d", &n);
//	findnum(arr, 3, 4, n);
//	return 0;
//}