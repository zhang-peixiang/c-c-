#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//小A和小B在玩猜数字。小B每次从1,2,3中随机选择一个,小A 每次也从1,2,3中选择一个猜。
//他们一共进行三次这个游戏，请返回 小A 猜对了几次？

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

//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
//char* reverseLeftWords(char* s, int n)
//{
//	int i = 0;
//	int sz = strlen(s);
//	for (i = 0; i < sz / 2; i++)//先将字符串逆置
//	{
//		char ret = *(s + i);
//		*(s + i) = *(s + sz - 1 - i);
//		*(s + sz - 1 - i) = ret;
//	}
//	for (i = 0; i < (sz - n) / 2; i++)//交换sz-n之前的字符，使其成为顺序
//	{
//		char ret = *(s + i);
//		*(s + i) = *(s + sz - 1 - n - i);
//		*(s + sz - 1 - n - i) = ret;
//	}
//	for (i = 0; i < n / 2; i++)//交换sz-n之后的字符，使其成为顺序
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