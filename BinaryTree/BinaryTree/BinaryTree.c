#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
#include "Queue.h"

BTNode* BuyBinTreeNode(int data)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));

	if (root == NULL)
	{
		assert(0);
		return;
	}
	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}


BTNode* CreateBinTree(int array[], int size,int* index,int invalid)
{
	BTNode* root = NULL;
	if (*index < size && array[*index] != invalid)
	{
		//创建根节点
		root = BuyBinTreeNode(array[*index]);

		//创建根节点的左子树
		++(*index);
		root->left = CreateBinTree(array, size, index, invalid);

		//创建根节点的右子树
		++(*index);
		root->right = CreateBinTree(array, size, index,invalid);

	}
	return root;
}



//前序遍历
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//中序遍历
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}



//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	if (root == NULL)
		return;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		printf("%d ", cur->data);

		QueuePop(&q);

		if (cur->left)
		{
			QueuePush(&q, cur->left);
		}

		if (cur->right)
		{
			QueuePush(&q, cur->right);
		}
	}

	QueueDestroy(&q);
}

BTNode* CopyBinTree(BTNode* root)
{
	BTNode* newroot = NULL;

	if (root)
	{
		//拷贝根节点
		newroot = BuyBinTreeNode(root->data);

		//拷贝根节点的左子树
		newroot->left = CopyBinTree(root->left);


		//拷贝根节点的右子树
		newroot->right = CopyBinTree(root->right);

	}

	return newroot;
}


int GetNodeCount(BTNode* root) //获取二叉树中节点的个数
{
	
	if (root == NULL)
		return 0;

	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

int GetLeafNodeCount(BTNode* root)//获取二叉树中叶子节点的个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}


int GetKLevelNodeCount(BTNode* root, unsigned int k)//获取二叉树中第K层节点的个数
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;

	return GetKLevelNodeCount(root->left,k-1) + GetKLevelNodeCount(root->right,k-1);
}


BTNode* Find(BTNode* root, BTNDataType data) //找值为data的节点
{
	BTNode* ret = NULL;
	if (root == NULL)
		return NULL;
	if (root->data == data)
		return root;

	if (ret = Find(root->left, data))
		return ret;

	return Find(root->right, data);
}


int GetHeight(BTNode* root) //获取二叉树的高度
{
	int leftHeight = 0, rightHeight = 0;
	if (root == NULL)
		return 0;

	leftHeight = GetHeight(root->left);
	rightHeight = GetHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	
	int flag = 0;
	int ret = 0;
	//空树也是完全二叉树
	if (root == NULL)
		return 1;

	//非空
	//1.按照层序遍历规则找到第一个不饱和的节点
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);

		if (flag)
		{
			//flag 不为0 表示不饱和的节点已经找到，后面的节点不能又孩子
			if (cur->left || cur->right)
				break;
		}
		else
		{
			//找第一个不饱和的节点
			if (cur->left && cur->right)
			{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//cur只有左孩子
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				//cur只有右孩子
				break;
			}
			else
			{
				flag = 1;
			}
		}
		QueuePop(&q);
	}
	if (QueueEmpty(&q))
		ret = 1;
	QueueDestroy(&q);
	return ret;
}


void DestroyTree(BTNode** root)
{
	assert(root);

	if (*root)
	{
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}


void TestBinTree()
{
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int index = 0;
	BTNode* root = CreateBinTree(array, sizeof(array) / sizeof(array[0]), &index, -1);


	DestroyTree(&root);
}
