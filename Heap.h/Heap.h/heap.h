#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int HDataType;


//���뺯��ָ�� ���Կ��ƴ�����ѻ���С��
int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

int (*cmp)(HDataType Less, HDataType Greater);

typedef int(*CMP)(HDataType, HDataType);



typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP cmp;
}Heap;


void HeapInit(Heap* hp, int initCap,CMP cmp);
void HeapCreate(Heap* hp, int* array, int size,CMP cmp);
void HeapPush(Heap* hp, HDataType data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);




void TestHeap();