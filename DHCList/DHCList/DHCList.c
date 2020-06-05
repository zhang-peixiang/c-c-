#define _CRT_SECURE_NO_WARNINGS 1
#include "DHCList.h"

DHCLNode* BuyNode(DLDataTypt data)
{
	DHCLNode* newnode = (DHCLNode*)malloc(sizeof(struct DHCListNode));
	if (newnode == NULL)
	{
		assert(0);
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

DHCLNode* DHCListInit()
{
	DHCLNode* newnode = BuyNode(0);
	if (newnode == NULL)
	{
		return NULL;
	}
	newnode->next = newnode;
	newnode->prev = newnode;

	return newnode;
}
void DHCListPushBack(DHCLNode* pHead, DLDataTypt data)
{
	assert(pHead);
	DHCListInsert(pHead, data);
}
void DHCListPopBack(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
	{
		return;
	}

	DHCListErase(pHead->prev);
}
void DHCListPushFront(DHCLNode* pHead, DLDataTypt data)
{
	assert(pHead);

	DHCListInsert(pHead->next, data);
}
void DHCListPopFront(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
	{
		return;
	}

	DHCListErase(pHead->next);

}
void DHCListInsert(DHCLNode* pos, DLDataTypt data)
{
	DHCLNode* newnode = BuyNode(data);

	newnode->next = pos;
	newnode->prev = pos->prev;
	newnode->prev->next = newnode;
	pos->prev = newnode;
}
void DHCListErase(DHCLNode* pos)
{
	DHCLNode* pre = pos->prev;
	DHCLNode* next = pos->next;

	pre->next = next;
	next->prev = pre;
	free(pos);
}
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataTypt data)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
int DHCListSize(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	int count = 0;
	while (cur != pHead)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int DHCListEmpty(DHCLNode* pHead)
{
	assert(pHead);
	return pHead == NULL;
}
void DHCListClear(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	DHCLNode* next = NULL;
	while (cur != pHead)
	{
		next = cur->next;
		pHead->next = next;
		next->prev = pHead;

		free(cur);
		cur = next;
	}
	pHead->next = pHead;
	pHead->prev = pHead;
}
void DHCListDestroy(DHCLNode** pHead)
{
	assert(pHead);
	DHCListClear(*pHead);

	free(*pHead);
	*pHead = NULL;
}


/////////////////////
void PrintDHCList(DHCLNode* head)
{
	DHCLNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void TestDHCList()
{
	DHCLNode* head = DHCListInit();

	DHCListPushBack(head, 1);
	DHCListPushBack(head, 2);
	DHCListPushBack(head, 3);
	DHCListPushBack(head, 4);
	DHCListPushBack(head, 5);
	PrintDHCList(head);

	DHCListPushFront(head, 0);
	PrintDHCList(head);

	DHCListPopBack(head);
	DHCListPopFront(head);
	PrintDHCList(head);
}