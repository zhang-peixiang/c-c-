#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//初始化
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	if (initCapacity <= 3)
	{
		s->capacity = 3;
	}
	s->array = (SDataType*)malloc(initCapacity*sizeof(SDataType));
	if (s->array == NULL)
	{
		return;
	}
	s->capacity = initCapacity;
	s->size = 0;
}
void check_capacity(SeqList* s)
{
	if (s->size == s->capacity)
	{
		int newcapacity = 2 * (s->capacity);
		SDataType* tmp = (SDataType*)realloc(s->array, newcapacity*sizeof(SDataType));
		if (tmp != NULL)
		{
			s->array = tmp;
		}
		s->capacity = newcapacity;
	}
}


// 尾插
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//判断容量
	check_capacity(s);

	//插入数据
	s->array[s->size] = data;
	s->size++;
}

// 尾删
void SeqListPopBack(SeqList* s)
{
	assert(s);
	if (SeqListEmpty(s) == 0)
		return;
	s->size--;
}


// 头插
void SeqListPushFront(SeqList* s, SDataType data)
{
	assert(s);
	//判断容量
	check_capacity(s);

	//插入数据
	int i = 0;
	for (i = s->size-1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->size++;
}

// 头删
void SeqListPopFront(SeqList* s)
{
	assert(s);
	int i = 0;
	if (SeqListEmpty(s) == 0)
		return;
	for (i = 0; i < s->size-1; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->size--;
}

// 任意位置插入
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	int i = 0;

	//判断该位置是否大于0或小于等于size
	if (pos<0 || pos > s->size)
	{
		return;
	}

	//判断容量
	check_capacity(s);

	//插入数据
	for (i = s->size - 1; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = data;
	s->size++;
}

// 任意位置删除
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	int i = pos;
	if (pos < 0 || pos >= s->size)
	{
		return;
	}
	for (i = pos; i < s->size-1; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->size--;
}

// 获取顺序表中有效元素个数
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

// 获取顺序表的容量
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

// 检测顺序表是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	if (s->size == 0)
	{
		return 0;
	}
	return 1;
}

// 查找值为data的元素是否在顺序表中，如果在返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		if (s->array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

// 清空
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}
// 销毁
void SeqListDestroy(SeqList* s)
{
	assert(s);
	if (s->array != 0)
	{
		free(s->array);
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
	
}



///////////////////////////////////
//测试
void Seqlist_print(SeqList* s)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%d ", s->array[i]);
	}
	printf("\n");
}

void test1()
{
	SeqList s;
	SeqListInit(&s, 3);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	Seqlist_print(&s);

	//SeqListPopBack(&s);
	//SeqListPushFront(&s, 3);
	//SeqListPopFront(&s);
	//SeqListInsert(&s, 3, 9);
	//SeqListErase(&s, 4);
	/*int ret = SeqListFind(&s, 3);
	printf("%d\n", ret);*/

	Seqlist_print(&s);
	SeqListClear(&s);
	SeqListDestroy(&s);
}