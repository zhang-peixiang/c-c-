#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//模拟实现memmove
//void* my_memmove(void* dest, const void* sur, int num)
//{
//	int i = 0;
//	char* copy_sur = (char*)malloc(num*sizeof(char));
//	copy_sur = memcpy(copy_sur, sur, num);
//	for (i = 0; i < num; i++)
//	{
//		((char*)dest)[i] = ((char*)copy_sur)[i];
//	}
//	free(copy_sur);
//	return dest;
//}
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	char str1[] = "abcdef";
//	char* tmp = my_memmove(str1 + 2, str1, 3);
//	int* ret = my_memmove(arr1 + 2, arr1, 20);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	printf("%s\n", str1);
//	return 0;
//}

//模拟实现memcpy
//void* my_memcpy(void* dest,const void* sur,int num)
//{
//	assert(dest && sur);
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		((char*)dest)[i] = ((char*)sur)[i];
//	}
//	return dest;
//}
//int main()
//{
//	
//	char str1[] = "*********************";
//	char str2[] = "hello world";
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5 };
//	//char* ret = my_memcpy(str1, str2, sizeof(str2));
//	//int * ret = my_memcpy(arr1, arr2, sizeof(arr2));
//	int* tmp = memcpy(arr1, arr2, sizeof(arr2));
//	//printf("%s\n", ret);
//
//	return 0;
//}
//




//模拟实现strstr
//char* my_strstr(char* dest, char* sur)
//{
//	assert(dest);
//	assert(sur);
//	int len1 = strlen(dest);
//	int len2 = strlen(sur);
//	int i = 0;
//	if (len1 < len2)
//	{
//		return NULL;
//	}
//	else
//	{
//		for (i = 0; i < len1; i++)
//		{
//			int j = 0;
//			if (dest[i] == sur[j])
//			{
//				int a = i;
//				while (sur[j] == dest[a] &&sur[j] &&dest[a])
//				{
//					a++;
//					j++;
//				}
//				if (sur[j] == '\0')
//				{
//					return dest+i;
//				}
//			}
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char str1[] = "abc";
//	char str2[] = "abc";
//	char* ret = my_strstr(str1, str2);
//	printf("%s\n", ret);
//	return 0;
//}