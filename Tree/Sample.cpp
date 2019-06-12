#include <iostream>
using namespace std;


typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

//��� ����
BTreeNode* MakeBTreeNode()
{
	BTreeNode* ne = new BTreeNode();
	ne->left = NULL;
	ne->right = NULL;
	return ne;
}


BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

//��忡 �����͸� ����
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

//���� ����Ʈ���� �ּҰ� ��ȯ
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

//������ ����Ʈ���� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

//main ���� ����Ʈ���� sub ����
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

//main ������ ����Ʈ���� sub ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		delete main->right;

	main->right = sub;
}


typedef void VisitFuncPtr(BTData data);

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)		return;

	InorderTraverse(bt->left);
	cout <<  bt->data << "\n"; // ������ȸ
	InorderTraverse(bt->right);
}

void ShowData(int data)
{
	cout << data << " \n";
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr Funcptr)
{
	if (bt == NULL)		return;

	InorderTraverse(bt->left, Funcptr);
	Funcptr(bt->data);
	InorderTraverse(bt->right, Funcptr);
}





int main()
{
	BTreeNode * bt1 = MakeBTreeNode();       
	BTreeNode * bt2 = MakeBTreeNode();       
	BTreeNode * bt3 = MakeBTreeNode();       
	BTreeNode * bt4 = MakeBTreeNode();


	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);


	MakeLeftSubTree(bt1, bt2); 
	MakeRightSubTree(bt1, bt3); 
	MakeLeftSubTree(bt2, bt4);


	//InorderTraverse(bt1);
	InorderTraverse(bt1,ShowData);

	return 0;
}