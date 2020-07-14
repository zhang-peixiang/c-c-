#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef	 _BinaryTree_
#define  _BinaryTree_

typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType data;
}BTNode;

BTNode* CreateBinTree(int array[], int size,int* index,int invalid);

void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

//��������õ��Ƕ���
void LevelOrder(BTNode* root);

BTNode* CopyBinTree(BTNode* root);

int GetNodeCount(BTNode* root);  //��ȡ�������нڵ�ĸ���
int GetLeafNodeCount(BTNode* root); //��ȡ��������Ҷ�ӽڵ�ĸ���
int GetKLevelNodeCount(BTNode* root, unsigned int k); //��ȡ�������е�K��ڵ�ĸ���
BTNode* Find(BTNode* root, BTNDataType data); //��ֵΪdata�Ľڵ�
int GetHeight(BTNode* root); //��ȡ�������ĸ߶�
int BinaryTreeComplete(BTNode* root);//�ж��Ƿ�����ȫ������

void DestroyTree(BTNode** root);



void TestBinTree();



#endif