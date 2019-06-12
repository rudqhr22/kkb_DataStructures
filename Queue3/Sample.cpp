#include <iostream>
using namespace std;

typedef char HData; typedef int Priority;

typedef struct _heapElem 
{
	Priority pr;   // ���� �������� ���� �켱����     
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

//�� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
int GetHipriChildIDX(Heap * ph, int idx)
{
	//�ڽ� ��尡 �������� �ʴ´ٸ�,  
	//numOfData�� ������ ����� ������ȣ�̴�,
	//�ڽ� ����� ���� �̺��� ũ�� �������� �ʴ� �ڽ� ����̴�. 
	if (GetLChildIndex(idx > ph->numOfData))
	{
		return 0;
	}
	
	//�ڽ� ��尡 ���� �ڽ� ��� �ϳ��� �����Ѵٸ�, 
	//�ڽ� ��尡 �ϳ� �����ϸ� �̴� ���� �ڽ� ����̴�. ���� ���� Ʈ�� �̹Ƿ�
	else if (GetLChildIndex(idx == ph->numOfData))
	{
		return GetLChildIndex(idx);
	}

	//�ڽ� ��尡 �Ѵ� �����Ѵٸ�, 
	else
	{
		//������ �ڽ� ����� �켱������ ���ٸ�
		if (ph->heapArr[GetLChildIndex(idx)].pr > ph->heapArr[GetRChildIndex(idx)].pr)
		{
			return GetRChildIndex(idx);   //������ �ڽ� ����� �ε��� �� ��ȯ
		}
		else
		{
			return GetLChildIndex(idx);   //���� �ڽ� ����� �ε��� �� ��ȯ
		}
	}
}


HData HDelete(Heap * ph)  
{
	HData retData = (ph->heapArr[1]).data;           //��ȯ�� ���ؼ� ������ ������ ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];   //���� <������ ���> ����

	// �Ʒ��� ���� parentIdx���� ������ ��尡 ����� ��ġ������ ����.
	int parentIdx = 1;  //��Ʈ ��尡 ��ġ�ؾ��� �ε��� �� ����
	int childIdx;

	//��Ʈ ����� �켱������ ���� �ڽ� ��带 �������� �ݺ��� ����
	while (childIdx = GetHipriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)        //������ ���� �켱���� ��
			break;                                          //������ ����� �켱������ ������ �ݺ��� Ż��

		//������ ��庸�� �켱���� ������, �񱳴�� ����� ��ġ�� �� ���� �ø�
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;                               //������ ��尡 ����� ��ġ������ �� ���� ����
	}
	//�ݺ��� Ż���ϸ� parentIdx���� ������ ����� ��ġ������ �����
	ph->heapArr[parentIdx] = lastElem;           //������ ��� ���� ����
	ph->numOfData -= 1;                          //�� ������ �� -1
	return retData;
}


void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;		//�� ��尡 ����� �ε��� ���� idx ����
	HeapElem nelem = { pr, data };		//�� ����� ���� �� �ʱ�ȭ

	while (idx != 1)					//����尡 ��Ʈ������ while
	{
		//������� �켱������ ���ٸ�
		if (pr < (ph->heapArr[GetParentIndex(idx)].pr))       
		{
			//�θ� ��带 �ѷ��� ����, (������ ����)
			ph->heapArr[idx] = ph->heapArr[GetParentIndex(idx)];

			//�� ��带 �� ���� �ø�, (�����δ� �ε��� ���� ����)
			idx = GetParentIndex(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = nelem; //�� ��带 �迭�� ����
	ph->numOfData += 1;       //�� �����ͼ� +1
}


int main()
{





	return 0;
}