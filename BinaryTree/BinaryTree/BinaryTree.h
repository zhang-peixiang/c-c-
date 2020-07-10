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

//层序遍历用的是队列
void LevelOrder(BTNode* root);


int GetNodeCount(BTNode* root);  //获取二叉树中节点的个数
int GetLeafNodeCount(BTNode* root); //获取二叉树中叶子节点的个数
int GetKLevelNodeCount(BTNode* root, unsigned int k); //获取二叉树中第K层节点的个数
BTNode* Find(BTNode* root, BTNDataType data); //找值为data的节点
int GetHeight(BTNode* root); //获取二叉树的高度


void DestroyTree(BTNode** root);