#include <iostream>
using namespace std;

#define QUE_LEN 100
typedef int  Data;

typedef struct _cQueue
{
	int _F;
	int _R;
	Data qArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;


int NextIndex(int pos)
{
	if (pos ==QUE_LEN - 1) 
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
	if (pq->_F == pq->_R)
		return true;
	else
		return false;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextIndex(pq->_R) == pq->_F) // R 이 F와 같으면 NULL
	{
		cout << "Error" << endl;
	}
	//아니라면 R+1로 더해서 이동하고, 배열에 값을 넣는다.
	pq->_R = NextIndex(pq->_R); 
	pq->qArr[pq->_R] = data;
}

Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		cout << "Error" << endl;
	}

	pq->_F = NextIndex(pq->_F);

	return pq->qArr[pq->_F];
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		cout << "Error" << endl;
	}
	pq->_F = NextIndex(pq->_F);

	return pq->qArr[NextIndex(pq->_F)];
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