#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//杨辉三角
//void YangHui_Triangle(void)
//{
//	int i = 0;
//	int j = 0;
//	int arr[30][30] = { 1 };
//	for (i = 1; i <= 30; i++)
//	{
//		arr[i][1] = 1;
//		for (j = 2; j <= i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for (i = 1; i <= 30; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	YangHui_Triangle();
//	return 0;
//}



//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手

//int main()
//{
//	int muder[4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		muder[i] = 1;
//		if ((muder[0] != 1) +
//			(muder[2] == 1) +
//			(muder[3] == 1) +
//			(muder[3] != 1) == 3)
//		{
//			break;
//		}
//		muder[i] = 0;
//	}
//	putchar('A' + i);
//	return 0;
//}


//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);//输入钱数
//	int i = 1;
//	int sum = 0;
//	int j = money / i; //瓶子数
//	if (money <= 0)
//	{
//		printf("0\n");
//	}
//	else
//	{
//		while (j != 1)
//		{
//			int a = 0;
//			if (j % 2 == 1)
//			{
//				a = 1;
//			}
//			j = j / 2;
//			sum = sum + j;
//			j = j + a;
//		}
//		printf("%d\n", sum + money / i);
//	}
//	return 0;
//}
