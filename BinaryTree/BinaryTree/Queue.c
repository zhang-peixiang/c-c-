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

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//入队列
void QueuePush(Queue* q, QDataType val)
{
	assert(q);

	QNode* newnode = BuyNode(val);
	q->rear->next = newnode;
	q->rear = newnode;
	q->_size++;
}

//出队列
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

//检测队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_size == 0;
}


//获取队列中有效元素的个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//获取队头元素
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

//销毁链表：带头节点的单链表
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