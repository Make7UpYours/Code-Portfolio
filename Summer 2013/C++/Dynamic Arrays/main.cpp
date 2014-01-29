/*William Freeman
  CS201L
  7/09/2013
  Assignment 7 - Dynamic Arrays
  Description: Create a dynamic array that reads through a list of integers
  and gets the size set according to the list.*/
#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;
using std::endl;
using std::cin;

void readFile(ifstream& inFile, int arr[], int size);
//Reads through the file and assigns values for the arr[].
int search(int arr[], int size);
//Prompts the user to give a value to search for.
//Returns the index of the value if it is found, returns -1 if not.

int main()
{
	ifstream inFile;
	inFile.open("numbers.txt");
	int size, buffer;
	inFile >> size;
	int* d_array = new int[size];
	readFile(inFile, d_array, size);
	inFile.close();

	int numIndex;
	numIndex = search(d_array, size);
	if (numIndex != -1)
	{
		cout << "Index: " << numIndex << endl;
	}
	else
	{
		cout << "Value doesn't exist.\n";
	}

	delete []d_array;
	return 0;
}

void readFile(ifstream& inFile, int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		inFile >> arr[index];
	}
}

int search(int arr[], int size)
{
	int value;
	cout << "Search a value: ";
	cin >> value;
	for (int index = 0; index < size; index++)
	{
		if (value == arr[index])
		{
			return index;
		}
	}
	return -1;
}