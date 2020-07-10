#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

QNode* BuyNode(int data)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		assert(0);
		return NULL;
	}

	newnode->val = data;
	newnode->next = NULL;

	return newnode;
}

//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//�����
void QueuePush(Queue* q, QDataType val)
{
	assert(q);

	QNode* newnode = BuyNode(val);
	q->rear->next = newnode;
	q->rear = newnode;
	q->_size++;
}

//������
void QueuePop(Queue* q)
{
	QNode* DelNode = NULL;
	if (QueueEmpty(q))
		return;

	DelNode = q->head->next;
	q->head->next = DelNode->next;
	free(DelNode);

	if (q->head->next == NULL)
	{
		q->rear = q->head;
	}
	q->_size--;
}

//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}


//��ȡ��������ЧԪ�صĸ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

//��ȡ��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

//����������ͷ�ڵ�ĵ�����
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->head;
	while (cur)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}

	q->head = NULL;
	q->rear = NULL;
	q->_size = 0;
}