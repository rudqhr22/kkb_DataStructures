#include <iostream>
using namespace std;

//
//void RecursionFunction(int icnt)
//{
//	if (icnt < 0)  return;
//
//	cout << "Àç±Í È£Ãâ: " << icnt << endl;
//	
//	RecursionFunction(icnt -1);
//}
//
//
//int FactorialFunc(int inum)
//{
//	if (inum == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return inum * FactorialFunc(inum - 1);
//	}
//}
//
//
//int Fibofunc(int inum)
//{
//	if (inum == 1)
//	{
//		return 0;
//	}
//	
//	else if (inum == 2)
//	{
//
//		return 1;
//	}
//	
//	else
//	{
//		return Fibofunc(inum - 1) + Fibofunc(inum - 2);
//	}
//
//}
//
//int BSearchRecur(int arr[], int first, int last, int target)
//{
//	int mid;
//
//	if (first > last)
//		return -1;
//
//	mid = (first + last) / 2;
//
//	if (target == arr[mid])
//	{
//		return mid;
//	}
//	else
//	{
//		if (target < arr[mid])
//		{
//			return BSearchRecur(arr, first, mid - 1, target);
//		}
//		else
//		{
//			return BSearchRecur(arr, mid+1, last, target);
//		}
//	}
//}
//
//


int Bsearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == arr[mid])
		{
			return mid; 
		}
		else
		{
			if (target < arr[mid])
			{
				last = mid - 1;
				
			}
			else
			{
				first = mid + 1;
			}
		}

	}
	return -1;
}


int Factirol(int icnt)
{
	if (icnt == 0) return 1;
	else
	{
		return icnt * Factirol(icnt - 1);
	}
}

int BSearch(int arr[], int first,int last, int target)
{

	if (first > last)
		return -1;

	int mid = (first + last) / 2;


	if (target == arr[mid])
	{
		return mid;
	}
	else
	{
		if (target < arr[mid])
		{
			return BSearch(arr, first, mid - 1, target);
		}
		else
		{
			return BSearch(arr, mid+1, last, target);
		}
	}
	return -1;
}



int BSearch(int arr[], int first, int last, int target)
{

	if (first > last) return -1;

	int mid = (first + last) / 2;
	if (target == arr[mid])
	{

	}



}


int main()
{
	int arr[9] = { 1,2,3,7,9,12,21,23,27 };

	int result = Bsearch(arr, 9, 3);

	//RecursionFunction(11);

	//cout << FactorialFunc(1) <<endl;
	//cout << FactorialFunc(3) << endl;
	//cout << FactorialFunc(4) << endl;
	//cout << FactorialFunc(5) << endl;
	//cout << FactorialFunc(6) << endl;
	//cout << FactorialFunc(7) << endl;

	//for (int i = 1; i < 15; i++)
	//{
	//	cout << Fibofunc(i) << ", ";
	//}






	return 0;
}