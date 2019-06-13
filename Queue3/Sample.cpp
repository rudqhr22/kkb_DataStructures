#include <iostream>
using namespace std;

typedef char HData; 
typedef int Priority;
typedef int PriorityComp(HData d1, HData d2);

//typedef struct _heapElem 
//{
//	Priority pr;   // ���� �������� ���� �켱����     
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

//�� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
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
	HData retData = ph->heapArr[1];           //��ȯ�� ���ؼ� ������ ������ ����
	HData lastElem = ph->heapArr[ph->numOfData];   //���� <������ ���> ����

	int parentIdx = 1;  //��Ʈ ��尡 ��ġ�ؾ��� �ε��� �� ����
	int childIdx;

	while (childIdx = GetHipriChildIDX(ph, parentIdx))
	{
		//if (lastElem.pr <= ph->heapArr[childIdx].pr)        
		//	break;                                          

		if (ph->Comp(lastElem , ph->heapArr[childIdx]) >=0)
			break;


		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;                               //������ ��尡 ����� ��ġ������ �� ���� ����
	}
	//�ݺ��� Ż���ϸ� parentIdx���� ������ ����� ��ġ������ �����
	ph->heapArr[parentIdx] = lastElem;           //������ ��� ���� ����
	ph->numOfData -= 1;                          //�� ������ �� -1
	return retData;
}


void HInsert(Heap * ph, HData data)
{
	int idx = ph->numOfData + 1;		//�� ��尡 ����� �ε��� ���� idx ����

	while (idx != 1)				
	{
		//������� �켱������ ���ٸ�
		if (ph->Comp (data , ph->heapArr[GetParentIndex(idx)]) >0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIndex(idx)];

			idx = GetParentIndex(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = data; //�� ��带 �迭�� ����
	ph->numOfData += 1;       //�� �����ͼ� +1
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