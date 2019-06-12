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
	pstack->topIndex = -1; // 비어있음
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

//빼는게 아니라, topIndex를 줄여가면서 -1이 될떄까지 읽는다
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