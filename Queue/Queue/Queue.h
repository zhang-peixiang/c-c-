#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//队列底层使用链表中节点的结构
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;


typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size;  //记录队列中有效元素的个数
}Queue;


//初始化队列
void QueueInit(Queue* q);

//入队列
void QueuePush(Queue* q, QDataType val);

//出队列
void QueuePop(Queue* q);

//检测队列是否为空
int QueueEmpty(Queue* q);


//获取队列中有效元素的个数
int QueueSize(Queue* q);

//获取队头元素
QDataType QueueFront(Queue* q);

//获取队尾元素
QDataType QueueBack(Queue* q);

//销毁链表：带头节点的单链表
void QueueDestroy(Queue* q);


///////////////////
void test();