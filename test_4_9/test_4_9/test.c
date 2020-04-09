#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

////只排整形的冒泡排序
//void bubble_sort(int arr[],int sz)
//{
//	int i = 0;
//	
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
//

////用冒泡法实现qsort
//void swap(char* e1, char* e2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		int ret = 0;
//		ret = *e1;
//		*e1 = *e2;
//		*e2 = ret;
//		e1++;
//		e2++;
//	}
//}
//bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1; j++)
//		{
//			if (cmp((char*)base + j*width,(char*)base + (j + 1)*width)>0)
//			{
//				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			}
//		}
//	}
//}
//
//
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return ((*(int*)e1) - (*(int*)e2));
//}
//
//void test1()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int cmp_float(const void* e1, const void* e2)
//{
//	if ((*(float*)e1)>(*(float*)e2))
//		return 1;
//	else if ((*(float*)e1)== (*(float*)e2))
//		return 0;
//	else
//		return -1;
//}
//void test2()
//{
//	float f[] = { 9.0, 8.0, 8.7, 6.8, 6.5, 4.0, 3.0, 2.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	bubble_sort(f, sz, sizeof(f[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_struct_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//test3()
//{
//	struct stu s[3] = { { "zhangsan", 34 }, { "lisi", 25 }, { "wangwu", 28 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), cmp_struct_by_name);
//}
//
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}
//
