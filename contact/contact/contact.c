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

	return -1;//找不到返回-1
}

void Initcontact(struct contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}

void Addcontact(struct contact* ps)
{
	printf("请输入姓名：>");
	scanf("%s", ps->date[ps->size].name);
	printf("请输入年龄：>");
	scanf("%d", &(ps->date[ps->size].age));
	printf("请输入性别：>");
	scanf("%s", ps->date[ps->size].sex);
	printf("请输入电话：>");
	scanf("%s", ps->date[ps->size].tel);
	printf("请输入地址：>");
	scanf("%s", ps->date[ps->size].addr);

	printf("添加成功\n");
	ps->size++;
}


void Showcontact(const struct contact* ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


void Searchcontact(const struct contact* ps)
{
	char name[max_name];
	printf("请输入要查找的名字:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入需要修改的姓名:>");
	scanf("%s", name);
	int ret = FindByname(ps, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", ps->date[ret].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入性别：>");
		scanf("%s", ps->date[ret].sex);
		printf("请输入电话：>");
		scanf("%s", ps->date[ret].tel);
		printf("请输入地址：>");
		scanf("%s", ps->date[ret].addr);

		printf("修改成功\n");
	}
}
int CmpByname(const void* e1, const void* e2)
{
	return strcmp(((struct peopleinfo*)e1)->name, ((struct peopleinfo*)e2)->name);
}
void Sortcontact(struct contact* ps)
{
	qsort(ps->date, ps->size, sizeof(ps->date[0]), CmpByname);
	printf("排序成功\n");
}