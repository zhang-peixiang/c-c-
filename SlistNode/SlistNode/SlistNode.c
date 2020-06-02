#define _CRT_SECURE_NO_WARNINGS 1
#include "SlistNode.h"

SlistNode* BuySlistNode(SLDataType data)
{
	SlistNode* newNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}

	newNode->date = data;
	newNode->next = NULL;
	return newNode;
}



//尾插
void SlistPushBack(SlistNode** head, SLDataType data)
{
	assert(head);
	SlistNode* newNode = BuySlistNode(data);
	//空链表
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		//非空链表
		SlistNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//尾删
void SlistPopBack(SlistNode** head)
{
	//空链表
	if (*head == NULL)
	{
		return NULL;
	}
	else if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		//非空链表
		SlistNode* cur = *head;
		SlistNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		//删除最后一个节点
		free(cur);
	}
}

//头插
void SlistPushFront(SlistNode** head, SLDataType data)
{
	assert(head);
	SlistNode* newNode = BuySlistNode(data);
	newNode->next = *head;
	*head = newNode;

	//if (*head == NULL)
	//{
	//	*head = newNode;
	//}
	//else
	//{
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}


//头删
void SlistPopFront(SlistNode** head)
{
	assert(head);
	//空链表
	if (*head == NULL)
	{
		return NULL;
	}
	
	SlistNode* delNode = *head;
	*head = delNode->next;
	free(delNode);
}

//任意位置插入
void SlistInsert(SlistNode* pos, SLDataType data)
{
	if (pos == NULL)
	{
		return;
	}
	SlistNode* newNode = BuySlistNode(data);
	newNode->next = pos->next;
	pos->next = newNode;

}

//任意位置删除
void SlistErase(SlistNode* pos)
{
	if (pos == NULL || pos->next==NULL)
	{
		return;
	}
	SlistNode* delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

int SlistSize(SlistNode* head)
{
	int count = 0;
	SlistNode* cur = head;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int SlistEmpty(SlistNode* head)
{
	return head == NULL;
}

SlistNode* SlistFind(SlistNode* head, SLDataType data)
{
	SlistNode* cur = head;
	while (cur)
	{
		if (cur->date == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListDestroy(SlistNode** head)
{
	assert(head);
	while (*head)
	{
		SlistNode* delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}

void PrintSList(SlistNode* head)
{
	SlistNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

void TestSList3()
{
	SlistNode* listhead = NULL;
	SlistPushFront(&listhead, 1);
	SlistPushFront(&listhead, 2);
	SlistPushFront(&listhead, 3);
	SlistPushFront(&listhead, 4);
	SlistPushFront(&listhead, 5);
	PrintSList(listhead);

	SlistInsert(SlistFind(listhead,1), 0);
	PrintSList(listhead);

	SlistErase(SlistFind(listhead, 1));
	PrintSList(listhead);
}

void TestSList2()
{
	SlistNode* listhead = NULL;
	SlistPushFront(&listhead, 1);
	SlistPushFront(&listhead, 2);
	SlistPushFront(&listhead, 3);
	SlistPushFront(&listhead, 4);
	SlistPushFront(&listhead, 5);
	PrintSList(listhead);

	SlistPopFront(&listhead);
	SlistPopFront(&listhead);
	SlistPopFront(&listhead);
	SlistPopFront(&listhead);
	SlistPopFront(&listhead);
	SlistPopFront(&listhead);
	PrintSList(listhead);

}

void TestSList1()
{
	SlistNode* listhead = NULL;
	SlistPushBack(&listhead, 1);
	SlistPushBack(&listhead, 2);
	SlistPushBack(&listhead, 3);
	SlistPushBack(&listhead, 4);
	SlistPushBack(&listhead, 5);
	PrintSList(listhead);


	SlistPopBack(&listhead);
	SlistPopBack(&listhead);
	SlistPopBack(&listhead);
	SlistPopBack(&listhead);
	SlistPopBack(&listhead);
	SlistPopBack(&listhead);

	PrintSList(listhead);
}



void TestSList()
{
	//TestSList1();
	//TestSList2();
	TestSList3();

}