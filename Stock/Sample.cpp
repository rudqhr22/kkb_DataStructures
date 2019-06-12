#include <iostream>
using namespace std;


typedef int Data;


typedef struct arrayStack
{
	Data stackArr[100];
	int topIndex;

}ArrayStack;

typedef ArrayStack Stack;


void Stackinit(Stack* pstack)
{
	pstack->topIndex = -1; // �������
}

int IsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1)return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;

}

//���°� �ƴ϶�, topIndex�� �ٿ����鼭 -1�� �ɋ����� �д´�
Data SPop(Stack* pstack)
{
	int rIdx;
	if (IsEmpty(pstack))
	{
		cout << "Stack NULL " << endl;
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];  //
}

Data SPeek(Stack* pstack)
{
	if (IsEmpty(pstack))
	{
		cout << "Stack NULL " << endl;
	}
	return pstack->stackArr[pstack->topIndex];
}

int main()
{

	Stack stack;
	Stackinit(&stack);

	SPush(&stack,1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!IsEmpty(&stack))
		cout <<  SPop(&stack) << endl;


	return 0;
}