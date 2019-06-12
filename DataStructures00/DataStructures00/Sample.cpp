#include <iostream>
using namespace std;




int BSearct(int arr[], int len, int target)
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
			if (target < arr[mid]) //  
			{
				last = mid - 1;
			}
			else // target > arr[mid]
			{
				first = mid + 1;
			}
		}
	}
	return -1;
}


int main()
{
	int arr[9] = { 1,2,3,7,9,12,21,23,27 };

	int result = BSearct(arr, 9, 3);


	return 0;

}



//int Bsearch(int arr[], int len, int target)
//{
//	int first = 0;
//	int last = len - 1;
//
//	int mid;// = (first + last) / 2;
//
//	while (first <= last)
//	{
//		mid = (first + last) / 2;
//		if (target == arr[mid])
//		{
//			return mid;
//		}
//		else
//		{
//			if (target < arr[mid])
//			{
//				last mid - 1;
//			}
//			else
//			{
//
//			}
//
//
//		}
//
//
//	}
//
//
//
//
//}