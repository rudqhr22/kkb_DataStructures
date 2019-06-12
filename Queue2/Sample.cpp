#include <iostream>
using namespace std;

#define QUE_LEN 100
typedef int  Data;

//hjkhjkhjk

typedef struct _node
{
	Data data;
	struct _node * next;
}Node;

typedef struct _cQueue //////
{
	Node* _F;
	Node* _R;
	/////////////////////////////////////////////////////////////
} LQueue;

typedef LQueue Queue;

void Test(){}

int NextIndex(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void QueueInit(Queue * pq)
{
	pq->_F = 0;
	pq->_R = 0;
}

int QIsEmpty(Queue * pq)
{
	if (pq->_F == NULL)
		return true;
	else
		return false;
}

void Enqueue(Queue * pq, Data data)
{
	Node* newNode = new Node;
	
	newNode->next = NULL;
	newNode->data = data;


	if (QIsEmpty(pq))
	{
		pq->_F = newNode;
		pq->_R = newNode;
	}
	else 
	{
		pq->_R->next = newNode;
		pq->_R = newNode;

	}
}

Data Dequeue(Queue * pq)
{
	Node* delNode;  //삭제할 노드를 저장할 노드
	Data rData;     //반환할 데이터

	
	if (QIsEmpty(pq))
	{
		cout << "Dequeue Error"<<endl;
	}
	//삭제하기 전에 데이터를 저장한다
	delNode = pq->_F;
	rData = pq->_F->data;

	
	pq->_F = pq->_F->next;
	delete delNode;

	return rData;
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		cout << "Error" << endl;
	}

	return pq->_F->data;
}


int main()
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);


	while (!QIsEmpty(&q))
		cout << Dequeue(&q) << endl;

	return 0;
}






int main2()
{
	int first;
	int last;

	int target;

	int arr[10];

	while (first <= last)
	{
		int mid = (first + last) / 2;

		if (target==arr[mid])
		{
			return mid;
		}
		else
		{
			if (target <= arr[mid])
			{
				last = mid + 1;

			}
			else
			{
				first = mid - 1;
			}
		}
	}





}