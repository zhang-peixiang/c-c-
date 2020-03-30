#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//2020-03-29_8-使用调试技巧(初阶)_作业

//模拟实现库函数strlen

//int my_strlen(const char* pa)
//{
//	int count = 0;
//	assert(pa != NULL);
//	while (*pa)
//	{
//		count++;
//		pa++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello world";
//	int len = 0;
//	len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//模拟实现库函数strcpy

//char* my_strcpy(char* dest, const char* str)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//	while (*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "###########";
//	char arr2[] = "hello";
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}



//调整奇数偶数顺序
void change_seq(int arr[], int sz)
{
	int ret = 0;
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		//从左到右找第一个偶数
		while (left < right&&arr[left] % 2 == 1)
		{
			left++;
		}
		//从右到左找第一个奇数
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		//交换奇数、偶数
		if (left < right)
		{
			ret = arr[left];
			arr[left] = arr[right];
			arr[right] = ret;

		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	change_seq(arr,sz);
	for (i = 0; i < sz - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}