#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//ģ��ʵ��strcat
void my_strcat(char* dest, char* src)
{
	assert(dest  && src);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
}
int main()
{
	char str1[30] = "hello";
	char str2[] = "world";
	my_strcat(str1, str2);
	printf("%s\n", str1);
	return 0;
}

//ģ��ʵ��strcmp
//int my_strcmp(char* str1,char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == 0)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//int main()
//{
//	char str1[] = "abddef";
//	char str2[] = "abcdef";
//	int ret = 0;
//	ret = my_strcmp(str1, str2);
//	if (ret > 0)
//	{
//		printf("str1 > str2\n");
//	}
//	else if (ret == 0)
//	{
//		printf("str1 = str2\n");
//	}
//	else
//	{
//		printf("str1 < str2\n");
//	}
//	return 0;
//}


//ģ��ʵ��strcpy
//void my_strcpy(char* des, char* sour)
//{
//	while (*des++ = *sour++)//��sour��ֵ��һ��ֵ��des����sour��'\0'������des��ʱ��ѭ������
//	{
//		;
//	}
//}
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "bit";
//	my_strcpy(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}


//ģ��ʵ��strlen
//int my_strlen(char* str)
//{
//	assert(str);
//	int count = 0;
//	while(*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char str[] = "hello world";
//	int ret = 0;
//	ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}