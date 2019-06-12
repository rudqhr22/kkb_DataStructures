#include <iostream>
using namespace std;


const int Listsize = 16;

typedef int LData;

typedef  struct __ArratList
{
	LData arr[Listsize];
	int numOfData;
	int curPosition;
} ArrayList;

typedef struct _node
{
	int data;  //���� ������
	struct _node * next;   //���� ��带 ����ų ������  
} Node;


typedef struct _linkedList
{
	Node* head;
	Node* cur;
	Node* before;

	int numOfData;
	int(*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

int WhoIsPrecede(LData d1, LData d2)    // typedef int LData; 
{
	if (d1 < d2)
		return 0;     // d1�� ���� ������ �ռ���. 
	else
		return 1;     // d2�� ���� ������ �ռ��ų� ����. 
}


void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

//�ʱ�ȭ
void ListInit(List* pList)
{
	pList->head = new Node();
	pList->head->next = NULL;
	pList->comp = NULL;
	pList->numOfData = 0;
}


void FInsert(List* pList, LData data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->next = pList->head->next;
	pList->head->next = newNode;

	(pList->numOfData)++;
}

void SInsert(List* pList, LData data)
{
	Node* newNode = new Node();
	Node* pred = pList->head;
	newNode->data = data;

	// �� ��尡 �� ��ġ�� ã�� ���� �ݺ���
	while (pred->next != NULL && 
		pList->comp(data, pred->next->data) != 0)  // �� ����� ��(data)�� ���� ��� �� �� ������(pred->next->data)�� ���ؼ� data�� �� ũ��
	{
		pred = pred->next; // ���� ���� �̵�
	}

	newNode->next = pred->next; 
	pred->next = newNode; 
	(pList->numOfData)++;

}

void ListInsert(List* pList, LData data)
{
	if (pList->comp == NULL)    //���ı���
		FInsert(pList, data);
	else
		SInsert(pList, data);
}




int LFirst(List* pList, LData* pdata)
{
	if (pList->head->next == NULL)   //���̳�尡 ���̶�� ��ȯ�� �����Ͱ� ����
		return false;
	 
	pList->before = pList->head;     //before�� ���� ��带 ����ű��
	pList->cur = pList->head->next;  //cur�� ù ���� ��带 ����Ű�� ��

	*pdata = pList->cur->data;
	return true;
}

int LNext(List* pList, LData* pdata)
{
	if (pList->head->next == NULL)   //���̳�尡 ���̶�� ��ȯ�� �����Ͱ� ����
		return false;

	pList->before = pList->cur;     //cur�� ����Ű�� ���� befor�� ����Ŵ
	pList->cur = pList->cur->next;  //cur�� �� ���� ��带 ����Ŵ

	*pdata = pList->cur->data;
	return true;
}

LData LRemove(List* pList)
{
	Node* rpos = pList->cur;
	LData rdata = rpos->data;


	pList->before->next = pList->cur->next;
	pList->cur = pList->before;


	delete rpos;
	(pList->numOfData)--;

	return rdata;
}

int main()
{
	List myList;

	

	SetSortRule(&myList , WhoIsPrecede);

}