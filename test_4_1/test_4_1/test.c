#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�������
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



//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭������

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


//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);//����Ǯ��
//	int i = 1;
//	int sum = 0;
//	int j = money / i; //ƿ����
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
