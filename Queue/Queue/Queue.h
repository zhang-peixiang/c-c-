#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//���еײ�ʹ�������нڵ�Ľṹ
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;


typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size;  //��¼��������ЧԪ�صĸ���
}Queue;


//��ʼ������
void QueueInit(Queue* q);

//�����
void QueuePush(Queue* q, QDataType val);

//������
void QueuePop(Queue* q);

//�������Ƿ�Ϊ��
int QueueEmpty(Queue* q);


//��ȡ��������ЧԪ�صĸ���
int QueueSize(Queue* q);

//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q);

//��ȡ��βԪ��
QDataType QueueBack(Queue* q);

//����������ͷ�ڵ�ĵ�����
void QueueDestroy(Queue* q);


///////////////////
void test();