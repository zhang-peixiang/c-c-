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

//层序遍历用的是队列
void LevelOrder(BTNode* root);

BTNode* CopyBinTree(BTNode* root);

int GetNodeCount(BTNode* root);  //获取二叉树中节点的个数
int GetLeafNodeCount(BTNode* root); //获取二叉树中叶子节点的个数
int GetKLevelNodeCount(BTNode* root, unsigned int k); //获取二叉树中第K层节点的个数
BTNode* Find(BTNode* root, BTNDataType data); //找值为data的节点
int GetHeight(BTNode* root); //获取二叉树的高度
int BinaryTreeComplete(BTNode* root);//判断是否是完全二叉树

void DestroyTree(BTNode** root);



void TestBinTree();



#endif