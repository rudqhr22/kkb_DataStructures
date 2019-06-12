#include <iostream>
using namespace std;


const int Listsize = 16;

typedef int LData;

typedef struct _node
{
	int data;  //현재 데이터
	struct _node * next;   //다음 노드를 가르킬 포인터  
	struct _node * precv;  //이전 노드를 가르킬 포인터  

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


//초기화
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

	//헤드 이동(2/2)
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

	// 새 노드가 들어갈 위치를 찾기 위한 반복문
	while (pred->next != NULL &&
		pList->comp(data, pred->next->data) != 0)  // 새 노드의 값(data)과 더미 노드 다 음 데이터(pred->next->data)를 비교해서 data가 더 크다
	{
		pred = pred->next; // 다음 노드로 이동
	}

	newNode->next = pred->next;
	pred->next = newNode;
	(pList->numOfData)++;

}

void ListInsert(List* pList, LData data)
{
	if (pList->comp == NULL)    //정렬기준
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

	//삭제할 노드를 tail이 가리킨다면
	if (rpos == pList->tail)
	{
		//그리고 마지막 노드라면
		if (pList->tail == pList->tail->next) //2
		{
			pList->tail == NULL;
		}
		else
		{
			pList->tail = pList->before;	   //1
		}
	}

	//단순 연결리스트와 동일한 코드
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