#include <iostream>
using namespace std;


typedef int Data;


typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack
{
	Node* head;

}ListStack;

typedef ListStack Stack;


void Stackinit(Stack* pstack)
{
	pstack->head = NULL; // 비어있음
}

int IsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (IsEmpty(pstack))
	{
		cout << NULL << endl;
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	delete rnode;

}

Data SPeek(Stack* pstack)
{
	if (IsEmpty(pstack))
	{
		cout << "Stack NULL " << endl;
	}

	return pstack->head->data;
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