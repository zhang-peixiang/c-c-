#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1000
#define max_name 20
#define max_sex 5
#define max_tel 12
#define max_addr 20

struct peopleinfo
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tel[max_tel];
	char addr[max_addr];
};

struct contact
{
	struct peopleinfo date[max];
	int size;
};

void Initcontact(struct contact* ps);
void Addcontact(struct contact* ps);
void Showcontact(const struct contact* ps);
void Delcontact(struct contact* ps);
void Searchcontact(const struct contact* ps);
void Modifyconst(struct contact* ps);
void Sortcontact(struct contact* ps);




