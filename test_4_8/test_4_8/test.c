#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//写一个函数，可以逆序一个字符串的内容。

//void Reverse_Order(char arr[],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	char ret;
//	int i = 0;
//	while (left < right)
//	{
//		ret = arr[left];
//		arr[left] = arr[right];
//		arr[right] = ret;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int i = 0;
//	char arr[] = "abcdef";
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	Reverse_Order(arr,sz);
//	printf("%s\n", arr);
//	return 0;
//}

//使用指针
//void Reverse(char* str)
//{
//	char* left = str;
//	char* right = str + strlen(str) - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//
//	}
//}
//
//int main()
//{
//	char str[] = "hello world";
//	Reverse(str);
//	printf("%s", str);
//}


#include <stdlib.h>
//qsort用法
int cmp_float(const void* e1, const void* e2)
{
	if ((*(float*)e1 - *(float*)e2) > 0)
		return 1;
	else if ((*(float*)e1 - *(float*)e2) == 0)
		return 0;
	else
		return -1;
}

void test1()
{
	float f[] = { 9.8, 9.7, 9.5, 9.6, 9.3 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
	printf("\n");
}


int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}

void test2()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
struct stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1, const void* e2)
{
	return (strcmp(((struct stu*)e1)->name, ((struct stu*) e2)->name));
}
void test3()
{
	struct stu s[3] = { { "zhangsan", 22 }, { "lisi", 18 }, { "wangwu", 29 } };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}