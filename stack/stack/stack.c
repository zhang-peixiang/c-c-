#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void CheckCapacity(Stack* ps)
{
	/*
	1.判断容量，开辟新空间
	2.拷贝元素
	3.释放旧空间
	4.使用新空间
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

//初始化
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

//入栈：尾插
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = data;
	ps->size++;
}

//出栈：尾删
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}

	ps->size--;
}

//获取栈顶元素
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));

	return ps->array[ps->size - 1];
}

//获取栈中有效元素的个数
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->size;
}

//检测栈是否为空
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->size == 0;
}

//销毁栈
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