#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
////����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
////δ��ɣ���ͷ�ͽ�β�Ŀո�Ҳ����ֱ仯��δʵ�ֱ�����ͷ�ͽ�β�Ŀո񲻱�
//void reverse_word(char str[], int sz)
//{
//	int i = 0;
//	int left = 0;
//	int right = sz - 1;
//	int count = 0;
//	int j = 0;
//	while (left < right)
//	{
//		char ret = str[left];
//		str[left] = str[right];
//		str[right] = ret;
//		left++;
//		right--;
//	}
//
//	for (i = 0; i < sz; i++)
	//{
//		if (str[i] == ' ')
//		{
//			int a = 0;
//			count++;
//			if (j == i - 1)//ɾ�����ʼ�Ķ���ո�
//			{
//
//				int b = 0;
//				b = i;
//				while (1)
//				{
//					str[b] = str[b + 1];
//
//					if (str[b + 1] == '\0')
//						break;
//					b++;
//				}
//				i -= 1;
//			}
//			else if (count == 1)//���������ĵ�һ������˳��
//			{
//				while (a<i - 1 - a)
//				{
//					char ret = str[a];
//					str[a] = str[i - 1 - a];
//					str[i - a - 1] = ret;
//					a++;
//				}
//			}
//			else//�����м䵥�ʵ�˳��
//			{
//				for (a = 0; j + 1 + a < i - 1 - a; a++)
//				{
//					char ret = str[j + 1 + a];
//					str[j + 1 + a] = str[i - 1 - a];
//					str[i - 1 - a] = ret;
//				}
//			}
//			j = i;
//		}
//	}
//	while (j + 1 < sz - 1)//�������һ�����ʵ�˳��
//	{
//		char ret = str[j + 1];
//		str[j + 1] = str[sz - 1];
//		str[sz - 1] = ret;
//		j++;
//		sz--;
//	}
//}
//
//int main()
//{
//	char str[] = "  hello world!  ";
//	int sz = strlen(str);
//	reverse_word(str,sz);
//	printf("%s", str);
//	return 0;
//}


//����һ���������� nums�����㷵������ λ��Ϊ ż�� �����ֵĸ�����
int findNumbers(int* nums, int numsSize)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < numsSize; i++)
	{
		int j = 0;
			while (*nums>9)
			{
				(*nums) = (*nums)/ 10;
				j++;
			}
			if (j % 2 != 0&&j!=0)
			{
				count++;
			}
		nums++;
	}
	return count;
}
int main()
{
	int nums[] = { 12, 345, 2, 6, 7896 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int count = findNumbers(nums, sz);
	printf("%d\n", count);
	return 0;
}