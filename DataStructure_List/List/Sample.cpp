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
	int data;  //현재 데이터
	struct _node * next;   //다음 노드를 가르킬 포인터  
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
		return 0;     // d1이 정렬 순서상 앞선다. 
	else
		return 1;     // d2가 정렬 순서상 앞서거나 같다. 
}


void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

//초기화
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
	if (pList->head->next == NULL)   //더미노드가 널이라면 반환할 데이터가 없다
		return false;
	 
	pList->before = pList->head;     //before는 더미 노드를 가리킥함
	pList->cur = pList->head->next;  //cur은 첫 번쨰 노드를 가리키게 함

	*pdata = pList->cur->data;
	return true;
}

int LNext(List* pList, LData* pdata)
{
	if (pList->head->next == NULL)   //더미노드가 널이라면 반환할 데이터가 없다
		return false;

	pList->before = pList->cur;     //cur이 가리키던 것을 befor가 가리킴
	pList->cur = pList->cur->next;  //cur은 그 다음 노드를 가리킴

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