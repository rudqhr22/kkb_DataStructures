#include <iostream>
using namespace std;


typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

//노드 생성
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

//노드에 데이터를 저장
void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

//왼쪽 서브트리의 주소값 반환
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

//오른쪽 서브트리의 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

//main 왼쫀 서브트리로 sub 연결
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

//main 오른쪽 서브트리로 sub 연결
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
	cout <<  bt->data << "\n"; // 중위순회
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