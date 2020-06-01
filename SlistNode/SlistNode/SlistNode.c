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



//β��
void SlistPshBack(SlistNode** head, SLDataType data)
{
	assert(head);
	SlistNode* newNode = BuySlistNode(data);
	//������
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		//�ǿ�����
		SlistNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//βɾ
void SlistPopBack(SlistNode** head)
{
	//������
	if (*head == NULL)
	{
		return NULL;
	}
	else
	{
		//�ǿ�����
		SlistNode* cur = *head;
		SlistNode* prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		//ɾ�����һ���ڵ�
		free(cur);
	}
}

//ͷ��
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
void SlistPopFront(SlistNode** head)
{
	assert(head);
	//������
	if (*head == NULL)
	{
		return NULL;
	}
	
	SlistNode* delNode = *head;
	*head = delNode->next;
	free(delNode);
}

void SlistInsert(SlistNode* pos, SLDataType data);
void SlistErase(SlistNode* pos);

int SlistSize(SlistNode* head);
int SlistEmpty(SlistNode* head);

SlistNode* SistFind(SlistNode* head, SLDataType data);

void SListDestroy(SlistNode** head);