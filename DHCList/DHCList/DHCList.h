#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLDataTypt;

typedef struct DHCListNode
{
	DLDataTypt data;
	struct DHCListNode* next;
	struct DHCListNode* prev;
}DHCLNode;


DHCLNode* DHCListInit();

void DHCListPushBack(DHCLNode* pHead, DLDataTypt data);
void DHCListPopBack(DHCLNode* pHead);
void DHCListPushFront(DHCLNode* pHead, DLDataTypt data);
void DHCListPopFront(DHCLNode* pHead);
void DHCListInsert(DHCLNode* pos, DLDataTypt data);
void DHCListErase(DHCLNode* pos);
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataTypt data);
int DHCListSize(DHCLNode* pHead);
int DHCListEmpty(DHCLNode* pHead);
void DHCListClear(DHCLNode* pHead);
void DHCListDestroy(DHCLNode** pHead);

void TestDHCList();