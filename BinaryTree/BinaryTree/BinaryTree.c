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


BTNode* CreateBinTree(int array[], int size,int index,int invalid)
{
	BTNode* root = NULL;
	if (index < size && array[index] != '#')
	{
		//�������ڵ�
		root = BuyBinTreeNode(array[index]);

		//�������ڵ��������
		root->left = CreateBinTree(array, size, ++index,invalid);

		//�������ڵ��������
		root->right = CreateBinTree(array, size, ++index,invalid);

	}
	return root;
}



//ǰ�����
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//�������
void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

//�������
void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}



//�������
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
		//�������ڵ�
		newroot = BuyBinTreeNode(root->data);

		//�������ڵ��������
		newroot->left = CopyBinTree(root->left);


		//�������ڵ��������
		newroot->right = CopyBinTree(root->right);

	}

	return newroot;
}


int GetNodeCount(BTNode* root) //��ȡ�������нڵ�ĸ���
{
	
	if (root == NULL)
		return 0;

	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

int GetLeafNodeCount(BTNode* root)//��ȡ��������Ҷ�ӽڵ�ĸ���
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}


int GetKLevelNodeCount(BTNode* root, unsigned int k)//��ȡ�������е�K��ڵ�ĸ���
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;

	return GetKLevelNodeCount(root->left,k-1) + GetKLevelNodeCount(root->right,k-1);
}


BTNode* Find(BTNode* root, BTNDataType data) //��ֵΪdata�Ľڵ�
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


int GetHeight(BTNode* root) //��ȡ�������ĸ߶�
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
	//����Ҳ����ȫ������
	if (root == NULL)
		return 1;

	//�ǿ�
	//1.���ղ�����������ҵ���һ�������͵Ľڵ�
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);

		if (flag)
		{
			//flag ��Ϊ0 ��ʾ�����͵Ľڵ��Ѿ��ҵ�������Ľڵ㲻���ֺ���
			if (cur->left || cur->right)
				break;
		}
		else
		{
			//�ҵ�һ�������͵Ľڵ�
			if (cur->left && cur->right)
			{
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//curֻ������
				QueuePush(&q, cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				//curֻ���Һ���
				break;
			}
			else
			{
				flag = 1;
			}
			QueuePop(&q);
		}
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
