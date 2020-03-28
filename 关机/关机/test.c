#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("你的电脑将在一分钟之内关机，如果你输入：“我是猪”，可取消关机\n 请输入：");
	scanf("%s", &input);
	if (strcmp(input, "我是猪") == 0)
		system("shutdown -a");
	else
		goto again;
	return 0;
}