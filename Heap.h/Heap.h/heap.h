#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define HDataType int 

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
}Heap;


void HeapInit(Heap* hp, int initCap);
void HeapCreate(Heap* hp, int* array, int size);
void HeapPush(Heap* hp, HDataType data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);




void TestHeap();