/*William Freeman
  CS201L
  7/23/2013
  Lab Assignment 11 - Recursion*/
#include <iostream>

using std::cout;
using std::endl;

void printMultiples(int givenNum, int multiplier);
//Outputs the multiples of givenNum starting with givenNum * multiplier.
//Subtracts 1 from multiplier each iteration until multiplier == 1.
void revPrintMultiples(int givenNum, int multiplier);
//Outputs the multiples of givenNum in the opposite order of printMultiples().
double factorial(double num);
//Calculates the factorial of the num passed in the parameter list.
//Returns the value of the factorial.
double revFactorial(double endNum, double start);
//Reverses the order of factorial().
//Start should be equal to 1 & endNum is the factorial that is being calculated.

int main()
{
	//Exercise 1
	cout << "Exercise 1\n";
	printMultiples(12, 10);
	cout << endl;
	revPrintMultiples(12, 1);
	//Exercise 2
	cout << endl << "Exercise 2\n";
	double total;
	total = factorial(10);
	cout << total << endl;
	total = revFactorial(10, 1);
	cout << total << endl;
	return 0;
}

void printMultiples(int givenNum, int multiplier)
{
	if (multiplier <= 1)
	{
		cout << givenNum * multiplier << endl;
		return;
	}
	else
	{
		cout << givenNum * multiplier << endl;
		printMultiples(givenNum, multiplier - 1);
	}
}

void revPrintMultiples(int givenNum, int multiplier)
{
	if (multiplier >= 10)
	{
		cout << givenNum * multiplier << endl;
	}
	else
	{
		cout << givenNum * multiplier << endl;
		revPrintMultiples(givenNum, multiplier + 1);
	}
}

double factorial(double num)
{
	if (num == 1)
	{
		cout << num << " = ";
		return num;
	}
	else
	{
		cout << num << " * ";
		return num * factorial(num - 1);
	}
}

double revFactorial(double endNum, double start)
{
	if (start == endNum)
	{
		cout << start << " = ";
		return start;
	}
	else
	{
		cout << start << " * ";
		return start * revFactorial(endNum, start + 1);
	}
}