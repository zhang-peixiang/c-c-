#define _CRT_SECURE_NO_WARNINGS 1

typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType* data;
}BTNode;



void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);

//��������õ��Ƕ���
void LevelOrder(BTNode* root);


int GetNodeCount(BTNode* root);  //��ȡ�������нڵ�ĸ���
int GetLeafNodeCount(BTNode* root); //��ȡ��������Ҷ�ӽڵ�ĸ���
int GetKLevelNodeCount(BTNode* root, unsigned int k); //��ȡ�������е�K��ڵ�ĸ���
BTNode* Find(BTNode* root, BTNDataType data); //��ֵΪdata�Ľڵ�
int GetHeight(BTNode* root); //��ȡ�������ĸ߶�


void DestroyTree(BTNode** root);