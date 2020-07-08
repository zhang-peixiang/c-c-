#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

//初始化堆
void HeapInit(Heap* hp, int initCap)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType)*initCap);
	if (hp->array == NULL)
	{
		assert(0);
		return;
	}

	hp->capacity = initCap;
	hp->size = 0;
}

void Swap(HDataType* left, HDataType* right)
{
	HDataType tmp = *left;
	*left = *right;
	*right = tmp;
}

void AdjustDown(HDataType* array, int size, int parent)
{
	//用child标记parent的较小的孩子--默认先标记parent的左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找到parent两个孩子中较小的孩子
		if (child + 1 < size && array[child + 1] < array[child])
		{
			child += 1;
		}
		//parent较小的孩子已经找到
		//检测parnt是否满足堆的性质

		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}


//用数组中的元素创建堆
void HeapCreate(Heap* hp, HDataType* array, int size)
{
	int root = 0;
	//1.先将数组中的元素放在堆结构中
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	//2.进行调整
	for (root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}
void CheckCapacity(Heap* hp)
{
	if (hp->size == hp->capacity)
	{
		HDataType* tmp = (HDataType*)malloc(sizeof(HDataType)*hp->size * 2);

		if (tmp != NULL)
		{
			hp->array = tmp;
			hp->capacity = hp->size * 2;
		}
	}
}

void AdjustUP(HDataType* array, int size, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap* hp, HDataType data)
{
	//0.检测是否需要扩容
	CheckCapacity(hp);

	//1.将新元素插入到数组的末尾，即：将心元素插入到完全二叉树的最后
	hp->array[hp->size++] = data;

	//2.新元素插入后，可能会破坏堆的性质
	AdjustUP(hp->array, hp->size, hp->size - 1);

}
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	 
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;

	AdjustDown(hp->array, hp->size, 0);
}


HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}


void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}



void TestHeap()
{
	int array[] = { 3, 6, 9, 1, 5, 3, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}