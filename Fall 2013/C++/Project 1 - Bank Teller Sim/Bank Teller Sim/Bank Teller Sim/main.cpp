/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.*/
#include <iostream>
#include "BankTellerSim.h"

using std::cout;
using std::cin;

const int MIN_NUM_CUSTOMERS = 5;
//Min number of customers that the simulation must serve.

void DetermineServed(int& num);
/*Prompts the user to enter the number of customers they would like to serve
  before the simulation ends.
  @Param num - The number of customers to be served.*/

int main()
{
	int custServed;
	BankTellerSim bankSim;
	DetermineServed(custServed);
	bankSim.RunSim(custServed);
	
    return 0;
}

void DetermineServed(int& num)
{
	//Greeting.
	cout << "Bank Teller Simulation:\n";
	cout << "Simulates customers in line at a bank, but instead of first-come,\n";
	cout << "first-serve, this bank uses the philosophy of\n";
	cout << "last-in, first-served when dealing with customers.\n\n";
	do
	{
		//Prompt user.
		cout << "Enter the number of customers you would like to serve before\n";
		cout << "the simulation ends (must be more than 4 customers): ";
		cin >> num;
		if (num < MIN_NUM_CUSTOMERS)
		{
			//Bad input.
			cout << "\nInvalid number of customers to serve entered.\n\n";
		}	 
	} while (num < MIN_NUM_CUSTOMERS);
}