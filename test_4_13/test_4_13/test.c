#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//int cmpWords(char* s1,char* s2)
//{
//	int i = 0;
//	int j = 0;
//	int sz = strlen(s1);
//	if (strcmp(s1, s2) == 0)//�Ƚ������ַ���
//	{
//		return 1;
//	}
//	
//	for (j = 1; j < sz; j++)
//	{
//		int n = 1;//ÿ���������תһ���ַ� ����abcdef ��һ��bcdefa �ڶ���edefab ��������
//		for (i = 0; i < sz / 2; i++)//�Ƚ��ַ�������
//		{
//			char ret = *(s1 + i);
//			*(s1 + i) = *(s1 + sz - 1 - i);
//			*(s1 + sz - 1 - i) = ret;
//		}
//		for (i = 0; i < (sz - n) / 2; i++)//����sz-n֮ǰ���ַ���ʹ���Ϊ˳��
//		{
//			char ret = *(s1 + i);
//			*(s1 + i) = *(s1 + sz - 1 - n - i);
//			*(s1 + sz - 1 - n - i) = ret;
//		}
//		for (i = 0; i < n / 2; i++)//����sz-n֮����ַ���ʹ���Ϊ˳��
//		{
//			char ret = *(s1 + sz - n + i);
//			*(s1 + sz - n + i) = *(s1 + sz - 1 - i);
//			*(s1 + sz - 1 - i) = ret;
//		}
//		printf("%s\n", s1);
//		if (strcmp(s1, s2) == 0)//�Ƚ������ַ���
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


//���Ͼ���
//void findnum(int arr[][4], int x, int y, int n)
//{
//	int a = 0;
//	int i = 0;
//	int j = 0;
//	for (a = 0; a < y; a++)
//	{
//		if (arr[x-1][j] < n)//�ж�n�Ƿ������һ��
//		{
//			for (j = 0; j < y; j++)
//			{
//				if (arr[x-1][j] == n)
//				{
//					printf("�ҵ���\n");
//					break;
//				}
//			}
//			break;
//		}
//		else if (arr[i][j]<n&&arr[i + 1][j]>n)//�ж�n�Ƿ���ĳһ�к�ĳһ��+1 ֮��
//		{
//			for (j = 0; j<y; j++)
//			{
//				if (arr[i][j] == n)
//				{
//					printf("�ҵ���\n");
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
//			printf("�ҵ���\n");
//			break;
//		}
//		else
//			{
//				i++;
//			}
//		}
//	
//	printf("�Ҳ���");
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