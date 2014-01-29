/*William Freeman
  CS201L
  7/25/2013
  Lab Assignment 12 - Bubble Sort*/
#include <iostream>

using std::cout;
using std::endl;

const int ARRAY_SIZE = 15;

void PrintArr(int arr[]);
//Prints the variables stored in arr[].
void BubbleSort(int arr[]);
//Sorts the arr[].
void RevBubbleSort(int arr[]);
//Sorts the arr[] in reverse order.

int main()
{
	int nums[ARRAY_SIZE] = {5, 0, 1, 3, 7, 9, 8, 4, 2, 6, 6, 9, 3, 5, 1};
	cout << "UNSORTED:\n";
	PrintArr(nums);
	cout << endl;

	BubbleSort(nums);
	cout << "SORTED:\n";
	PrintArr(nums);
	cout << endl;

	RevBubbleSort(nums);
	cout << "SORTED(REVERSED):\n";
	PrintArr(nums);
	cout << endl;

	return 0;
}

void PrintArr(int arr[])
{
	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		cout << arr[index] << " ";
	}
}

void BubbleSort(int arr[])
{
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE - 1; j++)
		{
			if (arr[j] > arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void RevBubbleSort(int arr[])
{
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}