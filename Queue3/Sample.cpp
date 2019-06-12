#include <iostream>
using namespace std;

typedef char HData; typedef int Priority;

typedef struct _heapElem 
{
	Priority pr;   // 값이 작을수록 높은 우선순위     
	HData data; 
} HeapElem; 

typedef struct _heap 
{ 
	int numOfData;     
	HeapElem heapArr[10]; 
} Heap;


void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
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
	return GetRChildIndex(idx) +1;
}

//두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHipriChildIDX(Heap * ph, int idx)
{
	//자식 노드가 존재하지 않는다면,  
	//numOfData는 마지막 노드의 고유번호이니,
	//자식 노드의 값이 이보다 크면 존재하지 않는 자식 노드이다. 
	if (GetLChildIndex(idx > ph->numOfData))
	{
		return 0;
	}
	
	//자식 노드가 왼쪽 자식 노드 하나만 존재한다면, 
	//자식 노드가 하나 존재하면 이는 왼쪽 자식 노드이다. 완전 이진 트리 이므로
	else if (GetLChildIndex(idx == ph->numOfData))
	{
		return GetLChildIndex(idx);
	}

	//자식 노드가 둘다 존재한다면, 
	else
	{
		//오른쪽 자식 노드의 우선순위가 높다면
		if (ph->heapArr[GetLChildIndex(idx)].pr > ph->heapArr[GetRChildIndex(idx)].pr)
		{
			return GetRChildIndex(idx);   //오른쪽 자식 노드의 인덱스 값 반환
		}
		else
		{
			return GetLChildIndex(idx);   //왼쪽 자식 노드의 인덱스 값 반환
		}
	}
}


HData HDelete(Heap * ph)  
{
	HData retData = (ph->heapArr[1]).data;           //반환을 위해서 삭제할 데이터 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData];   //힙의 <마지막 노드> 저장

	// 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다.
	int parentIdx = 1;  //루트 노드가 위치해야할 인덱스 값 저장
	int childIdx;

	//루트 노드의 우선수위가 높은 자식 노드를 시작으로 반복문 시작
	while (childIdx = GetHipriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)        //마지막 노드와 우선순위 비교
			break;                                          //마지막 노드의 우선순위가 높으면 반복문 탈출

		//마지막 노드보다 우선순위 높으니, 비교대상 노드의 위치를 한 레벨 올림
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;                               //마지막 노드가 저장될 위치정보를 한 레벨 내림
	}
	//반복문 탈출하면 parentIdx에는 마지막 노드의 위치정보가 저장됨
	ph->heapArr[parentIdx] = lastElem;           //마지막 노드 최종 저장
	ph->numOfData -= 1;                          //총 데이터 수 -1
	return retData;
}


void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;		//새 노드가 저장될 인덱스 값을 idx 저장
	HeapElem nelem = { pr, data };		//새 노드의 생성 및 초기화

	while (idx != 1)					//새노드가 루트노드까지 while
	{
		//새노드의 우선순위가 높다면
		if (pr < (ph->heapArr[GetParentIndex(idx)].pr))       
		{
			//부모 노드를 한레벨 내림, (실제로 내림)
			ph->heapArr[idx] = ph->heapArr[GetParentIndex(idx)];

			//새 노드를 한 레벨 올림, (실제로는 인덱스 값만 갱신)
			idx = GetParentIndex(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = nelem; //새 노드를 배열에 저장
	ph->numOfData += 1;       //총 데이터수 +1
}


int main()
{





	return 0;
}