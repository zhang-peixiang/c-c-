#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

static int FindByname(struct contact* ps, char name[max_name])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//�Ҳ�������-1
}

void Initcontact(struct contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

void Addcontact(struct contact* ps)
{
	printf("������������>");
	scanf("%s", ps->date[ps->size].name);
	printf("���������䣺>");
	scanf("%d", &(ps->date[ps->size].age));
	printf("�������Ա�>");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��>");
	scanf("%s", ps->date[ps->size].tel);
	printf("�������ַ��>");
	scanf("%s", ps->date[ps->size].addr);

	printf("��ӳɹ�\n");
	ps->size++;
}


void Showcontact(const struct contact* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tel,
				ps->date[i].addr);
		}
	}
}

void Delcontact(struct contact* ps)
{
	char name[max_name];
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("�����ڸ���ϵ��\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


void Searchcontact(const struct contact* ps)
{
	char name[max_name];
	printf("������Ҫ���ҵ�����:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("�����ڸ���ϵ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tel,
			ps->date[ret].addr);
	}
}

void Modifyconst(struct contact* ps)
{
	char name[max_name];
	printf("��������Ҫ�޸ĵ�����:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("�����ڸ���ϵ��\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->date[ret].name);
		printf("���������䣺>");
		scanf("%d", &(ps->date[ret].age));
		printf("�������Ա�>");
		scanf("%s", ps->date[ret].sex);
		printf("������绰��>");
		scanf("%s", ps->date[ret].tel);
		printf("�������ַ��>");
		scanf("%s", ps->date[ret].addr);

		printf("�޸ĳɹ�\n");
	}
}
int CmpByname(const void* e1, const void* e2)
{
	return strcmp(((struct peopleinfo*)e1)->name, ((struct peopleinfo*)e2)->name);
}
void Sortcontact(struct contact* ps)
{
	qsort(ps->date, ps->size, sizeof(ps->date[0]), CmpByname);
	printf("����ɹ�\n");
}