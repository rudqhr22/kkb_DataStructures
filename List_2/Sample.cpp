#include <iostream>
using namespace std;


const int Listsize = 16;

typedef int LData;

typedef struct _node
{
	int data;  //���� ������
	struct _node * next;   //���� ��带 ����ų ������  
	struct _node * precv;  //���� ��带 ����ų ������  

} Node;


typedef struct _linkedList
{
	Node* tail;
	Node* cur;
	Node* before;

	int numOfData;

}LinkedList;


typedef struct _dblinkedList
{
	Node* head;
	Node* cur;
	int numOfData;

}_dblinkedList;

typedef _dblinkedList List;


//�ʱ�ȭ
void ListInit(List* pList)
{
	pList->head = NULL;
	pList->numOfData = 0;
}


void LInsert(List* pList, LData data)
{
	Node* newNode = new Node();
	newNode->data = data;

	newNode->next = pList->head;

	if (pList->head != NULL) 
	{   //(1/2)
		pList->head->precv = newNode;
	}

	//��� �̵�(2/2)
	newNode->precv = NULL;
	pList->head = newNode;
	
	(pList->numOfData)++;
}





void LInsertTail(List* pList, LData data)
{
	Node* newNode = new Node();
	newNode->data = data;

	if (pList->tail == NULL)
	{
		//pList->tail = newNode;
		//newNode->next = newNode;

		pList->tail = newNode;
		newNode->next = newNode;

	}
	else
	{
		newNode->next = pList->tail->next;
		pList->tail->next = newNode;
		pList->tail = newNode;

	}
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
	if (pList->head == NULL)   
		return false;

	pList->cur = pList->head;  

	*pdata = pList->cur->data;
	return true;
}

int LNext(List* pList, LData* pdata)
{
	if (pList->head == NULL)
		return false;

	pList->cur = pList->cur->next; 

	*pdata = pList->cur->data;
	return true;
}

int LPreviout(List* pList, LData* pdata)
{
	if (pList->head == NULL)
		return false;

	pList->cur = pList->cur->precv;

	*pdata = pList->cur->data;
	return true;
}

LData LRemove(List* pList)
{
	Node* rpos = pList->cur;
	LData rdata = rpos->data;

	//������ ��带 tail�� ����Ų�ٸ�
	if (rpos == pList->tail)
	{
		//�׸��� ������ �����
		if (pList->tail == pList->tail->next) //2
		{
			pList->tail == NULL;
		}
		else
		{
			pList->tail = pList->before;	   //1
		}
	}

	//�ܼ� ���Ḯ��Ʈ�� ������ �ڵ�
	pList->before->next = pList->cur->next;
	pList->cur = pList->before;

	delete rpos;
	(pList->numOfData)--;
	return rdata;
}

int main()
{
	List myList;



	

}