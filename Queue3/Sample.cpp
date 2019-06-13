#include <iostream>
using namespace std;

typedef char HData; 
typedef int Priority;
typedef int PriorityComp(HData d1, HData d2);

//typedef struct _heapElem 
//{
//	Priority pr;   // 값이 작을수록 높은 우선순위     
//	HData data; 
//} HeapElem; 

typedef struct _heap 
{ 
	PriorityComp * Comp;
	int numOfData;     
	HData heapArr[10]; 
} Heap;


void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->Comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return true;
	else
		return false;
}

int GetParentIndex(int idx)
{
	return idx / 2;
}

int GetLChildIndex(int idx)
{
	return idx * 2;
}

int GetRChildIndex(int idx)
{
	return GetLChildIndex(idx) +1;
}

//두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHipriChildIDX(Heap * ph, int idx)
{
	if (GetLChildIndex(idx > ph->numOfData))
	{
		return 0;
	}
	else if (GetLChildIndex(idx == ph->numOfData))
	{
		return GetLChildIndex(idx);
	}
	else
	{
		if (ph->Comp( ph->heapArr[GetLChildIndex(idx)], 
						ph->heapArr[GetRChildIndex(idx)]) <0)
		{
			return GetRChildIndex(idx);   
		}
		else
		{
			return GetLChildIndex(idx);  
		}
	}
}


HData HDelete(Heap * ph)  
{
	HData retData = ph->heapArr[1];           //반환을 위해서 삭제할 데이터 저장
	HData lastElem = ph->heapArr[ph->numOfData];   //힙의 <마지막 노드> 저장

	int parentIdx = 1;  //루트 노드가 위치해야할 인덱스 값 저장
	int childIdx;

	while (childIdx = GetHipriChildIDX(ph, parentIdx))
	{
		//if (lastElem.pr <= ph->heapArr[childIdx].pr)        
		//	break;                                          

		if (ph->Comp(lastElem , ph->heapArr[childIdx]) >=0)
			break;


		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;                               //마지막 노드가 저장될 위치정보를 한 레벨 내림
	}
	//반복문 탈출하면 parentIdx에는 마지막 노드의 위치정보가 저장됨
	ph->heapArr[parentIdx] = lastElem;           //마지막 노드 최종 저장
	ph->numOfData -= 1;                          //총 데이터 수 -1
	return retData;
}


void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData + 1;		//새 노드가 저장될 인덱스 값을 idx 저장

	while (idx != 1)				
	{
		//새노드의 우선순위가 높다면
		if (ph->Comp (data , ph->heapArr[GetParentIndex(idx)]) >0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIndex(idx)];

			idx = GetParentIndex(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = data; //새 노드를 배열에 저장
	ph->numOfData += 1;       //총 데이터수 +1
}


int DataPriorrity(char ch1, char ch2)
{
	return ch2 - ch1;
}


int main()
{
	Heap heap;
	HeapInit(&heap , DataPriorrity);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	cout << HDelete(&heap) << "\n";

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	cout << HDelete(&heap) << "\n";

	while (!HIsEmpty(&heap))
	{
		cout << HDelete(&heap) << "\n";
	}

	return 0;
}