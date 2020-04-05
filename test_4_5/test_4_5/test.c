#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
////A选手说：B第二，我第三；
////B选手说：我第二，E第四；
////C选手说：我第一，D第二；
////D选手说：C最后，我第三；
////E选手说：我第四，A第一；
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//
//int checkData(int* arr)
//{
//	int a[6] = { 0 };
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		if (a[arr[i]])
//		{
//			return 0;
//		}
//		a[arr[i]] = 1;
//	}
//	return 1;
//}
//
//int main()
//{
//	int arr[5] = { 0 };
//	int i = 1;
//	for (arr[0] = 1; arr[0] <= 5; arr[0]++)
//	{
//		for (arr[1] = 1; arr[1] <= 5; arr[1]++)
//		{
//			for (arr[2] = 1; arr[2] <= 5; arr[2]++)
//			{
//				for (arr[3] = 1; arr[3] <= 5; arr[3]++)
//				{
//					for (arr[4] = 1; arr[4] <= 5; arr[4]++)
//					{
//						if (((arr[1] == 2) + (arr[0] == 3) == 1) &&
//							((arr[1] == 2) + (arr[4] == 4) == 1) &&
//							((arr[2] == 1) + (arr[3] == 2) == 1) &&
//							((arr[2] == 5) + (arr[3] == 3) == 1) &&
//							((arr[4] == 4) + (arr[0] == 1) == 1) &&
//							checkData(arr))
//						{
//							for (i = 0; i < 5; i++)
//							{
//								printf("%d ", arr[i]);
//							}
//						}
//
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//


