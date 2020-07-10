#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
#include "Queue.h"

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
