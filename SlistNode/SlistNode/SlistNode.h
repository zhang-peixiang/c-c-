#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int SLDataType;

typedef struct SlistNode
{
	SLDataType date;
	struct SlistNode* next;
}SlistNode;


void SlistPushBack(SlistNode** head, SLDataType data);
void SlistPopBack(SlistNode** head);
void SlistPushFront(SlistNode** head, SLDataType data);
void SlistPopFront(SlistNode** head);

void SlistInsert(SlistNode* pos, SLDataType data);
void SlistErase(SlistNode* pos);

int SlistSize(SlistNode* head);
int SlistEmpty(SlistNode* head);

SlistNode* SlistFind(SlistNode* head, SLDataType data);

void SListDestroy(SlistNode** head);

///////////////////////////
void TestSList();