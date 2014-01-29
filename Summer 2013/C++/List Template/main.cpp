/*William Freeman
  CS201L
  7/18/2013
  Lab Assignment 10 - List Template
  Description: This lab consists of creating various template classes and their
  uses in the STL.*/
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "money.h"

using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::list;

template <typename T>
T Add(T item1, T item2);
//Adds two items of type T together and returns their total.
void Sort();
//Loads in numbers from numbers.txt, and sorts them.
int main()
{
	//Warm Up
	cout << "Warm Up:\n";
	Money m1(10.5,"Euro"), m2(12.75);
	Money sum;
	sum = m1 + m2;
	cout << sum.getValue() << " " << sum.getUnit() << endl;
	Money m3(10.5);
	sum = m3 + m2;
	cout << sum.getValue() << " " << sum.getUnit() << endl << endl;

	//Exercise 1
	cout << "Exercise 1:\n";
	Sort();
	cout << endl;
	return 0;
}

template <typename T>
T Add(T item1, T item2)
{
	return item1 + item2;
}

void Sort()
{
	ifstream inFile;
	inFile.open("numbers.txt");
	list<int> numList;
	int num;
	//Read in numbers.
	while (inFile >> num)
	{
		numList.push_back(num);
	}
	//Output unsorted list.
	cout << "Unsorted List:\n";
	for (list<int>::iterator it = numList.begin();
		it != numList.end(); it++)
	{
		cout << *it << endl;
	}
	numList.sort();
	//Output sorted list.
	cout << "Sorted List:\n";
	for (list<int>::iterator it = numList.begin();
		it != numList.end(); it++)
	{
		cout << *it << endl;
	}
	inFile.close();
}