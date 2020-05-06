#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//模拟实现strncpy
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


//模拟实现strncat
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

//找单身狗
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
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
	int* singlenum = (int*)malloc(2 * sizeof(int));//开辟两个int大小的空间，存放只出现一次的数字
	if (singlenum != NULL)
	{
		qsort(arr, sz, sizeof(int), cmp);
		while (i < sz-1)//避免i+1越界访问
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
		if (i == sz - 1)//如果相等，最后一个数字没有和他相比较的数字，数组中一定只含有一个
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