#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void CheckCapacity(Stack* ps)
{
	/*
	1.�ж������������¿ռ�
	2.����Ԫ��
	3.�ͷžɿռ�
	4.ʹ���¿ռ�
	*/
	if (ps->size == ps->capacity)
	{
		SDataType* tmp = (SDataType*)malloc(sizeof(SDataType)* 2 * ps->size);
		if (tmp == NULL)
		{
			assert(0);
			return;
		}
		memcpy(tmp, ps->array, sizeof(SDataType)*ps->size);

		free(ps->array);

		ps->array = tmp;
		ps->capacity = ps->size * 2;
	}
}

//��ʼ��
void StackInit(Stack* ps)
{
	assert(ps);

	ps->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	if (ps->array == NULL)
	{
		assert(0);
		return;
	}
	ps->capacity = 10;
	ps->size = 0;
}

//��ջ��β��
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}

//��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}

	ps->size--;
}

//��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));

	return ps->array[ps->size - 1];
}

//��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->size;
}

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->size == 0;
}

//����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
	
}

////////////////////////

void PrintStack(Stack* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
		printf("%d ", ps->array[i]);
	printf("\n");
}


void test()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	PrintStack(&s);

	StackPop(&s);
	PrintStack(&s);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));

	StackDestroy(&s);
}