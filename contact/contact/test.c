#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void menu()
{
	printf("*********************************\n");
	printf("*****  1.add       2.del    *****\n");
	printf("*****  3.search    4.modify *****\n");
	printf("*****  5.show      6.sort   *****\n");
	printf("*******0.exit               *****\n");
	printf("*********************************\n");

}

int main()
{
	int input = 0;
	struct contact con;
	//��ʼ���ṹ��
	Initcontact(&con);
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Addcontact(&con);
			break;
		case 2:
			Delcontact(&con);
			break;
		case 3:
			Searchcontact(&con);
			break;
		case 4:
			Modifyconst(&con);
			break;
		case 5:
			Showcontact(&con);
			break;
		case 6:
			Sortcontact(&con);
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}