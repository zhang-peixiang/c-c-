#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//СA��СB��������֡�СBÿ�δ�1,2,3�����ѡ��һ��,СA ÿ��Ҳ��1,2,3��ѡ��һ���¡�
//����һ���������������Ϸ���뷵�� СA �¶��˼��Σ�

//int game(int guess[],int guessSize,int answer[],int answerSize)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < guessSize; i++)
//	{
//		if (guess[i] == answer[i])
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int guess[3] = { 1, 1, 3 };
//	int answer[3] = { 1, 2, 3 };
//	int guessSize = sizeof(guess) / sizeof(guess[0]);
//	int answerSize = sizeof(answer) / sizeof(answer[0]);
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &guess[i]);
//	}
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &answer[i]);
//	}
//	int ret = 0;
//	ret = game(guess, guessSize, answer, answerSize);
//	printf("%d\n", ret);
//	return 0;
//}

//strcpy
//void my_strcpy(char des[],char source[])
//{
//	int i = 0;
//	while (1)
//	{
//		if (source[i] == '\0')
//		{
//			des[i] = source[i];
//			break;
//		}
//		des[i] = source[i];
//		i++;
//	}
//}
//
//
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "**********************************";
//	printf("%s\n", str2);
//	my_strcpy(str2, str1);
//	//strcpy(str2, str1);
//	printf("%s\n", str2);
//	return 0;
//}

//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
//���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
//char* reverseLeftWords(char* s, int n)
//{
//	int i = 0;
//	int sz = strlen(s);
//	for (i = 0; i < sz / 2; i++)//�Ƚ��ַ�������
//	{
//		char ret = *(s + i);
//		*(s + i) = *(s + sz - 1 - i);
//		*(s + sz - 1 - i) = ret;
//	}
//	for (i = 0; i < (sz - n) / 2; i++)//����sz-n֮ǰ���ַ���ʹ���Ϊ˳��
//	{
//		char ret = *(s + i);
//		*(s + i) = *(s + sz - 1 - n - i);
//		*(s + sz - 1 - n - i) = ret;
//	}
//	for (i = 0; i < n / 2; i++)//����sz-n֮����ַ���ʹ���Ϊ˳��
//	{
//		char ret = *(s + sz - n + i);
//		*(s + sz - n + i) = *(s + sz - 1 - i);
//		*(s + sz - 1 - i) = ret;
//	}
//
//	return s;
//}
//
//
//int main()
//{
//	char s[] = "lrloseumgh";
//	int n = 0;
//	scanf("%d", &n);
//	reverseLeftWords(s,n);
//	printf("%s\n", s);
//	return 0;
//}