#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//ģ��ʵ��strncpy
//char* my_strncpy(char* dest, char* sour, int count)
//{
//	assert(*dest && *sour);
//	char* str = dest;
//	while (count && (*dest++ = *sour++))
//	{
//		count--;
//	}
//	if (count != 0)
//	{
//		while (--count)
//		{
//			*dest++ = '\0';
//		}
//	}
//	return str;
//}
//int main()
//{
//	char str1[] = "******************";
//	char str2[] = "hello world";
//	char* str = my_strncpy(str1, str2, 14);
//	printf("%s\n", str1);
//	printf("%s\n", str);
//	return 0;
//}


//ģ��ʵ��strncat
//char* my_strncat(char* dest, char* sour, int count)
//{
//	char* str = dest;
//	int i = 0;
//	while (*dest)
//	{
//		dest++;
//	}
//	for (i = 0; i < count && *sour; i++)
//	{
//		*dest++ = *sour++;
//	}
//	*dest = '\0';
//	return str;
//}
//int main()
//{
//	char str1[20] = "abcde\0******";
//	char str2[] = "ccc";
//	char str = strncat(str1, str2, 5);
//	//char* str = my_strncat(str1, str2, 2);
//	printf("%s\n", str1);
//	return 0;
//}

//�ҵ���
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
int cmp(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return *(int*)e1 - *(int*)e2;
}
int* find_singlenum(int* arr, int sz)
{
	assert(arr);
	int i = 0;
	int j = 0;
	int* singlenum = (int*)malloc(2 * sizeof(int));//��������int��С�Ŀռ䣬���ֻ����һ�ε�����
	if (singlenum != NULL)
	{
		qsort(arr, sz, sizeof(int), cmp);
		while (i < sz-1)//����i+1Խ�����
		{
			if (arr[i] != arr[i + 1])
			{
				singlenum[j] = arr[i];
				i++;
				j++;
			}
			else
			{
				i += 2;
			}
		}
		if (i == sz - 1)//�����ȣ����һ������û�к�����Ƚϵ����֣�������һ��ֻ����һ��
		{
			singlenum[j] = arr[i];
		}
	}
	return singlenum;
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 3, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* ret = find_singlenum(arr, sz);
	for (i = 0; i < 2; i++)
	{
		printf("%d\n", ret[i]);
	}
	return 0;
}