/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --Transaction.cpp is the implementation file for the Transaction class--
  Class Desciption: Transaction contains the information pertaining to a 
  customer's transaction.*/
#include <cstdlib>
#include "Transaction.h"

/*Determines if the Transaction is to be a withdrawl or a deposit based
  upon the WITHDRAWL_PROB.*/
void Transaction::DetermineTransType()
{
	double randNum = double(rand()) / RAND_MAX;
	/*double(rand()) / RAND_MAX;
	  taken from Objects, Abstraction, Data Structures and Design using
	  C++ by Elliot B. Koffman & Paul A.T. Wolfgang.
	  Pg. 396.
	  Generates a double number between 0 - 1.*/
	if (randNum <= WITHDRAWAL_PROB)
	{
		m_withdrawal = true;
	}
	else
	{
		m_withdrawal = false; //Transaction is a deposit.
	}
}

/*Calls DetermineTransType() to determine the Transaction type.
  Returns the amount to add or subtract from the Customer's bank account.*/
double Transaction::RunTransaction()
{
	DetermineTransType();
	if (m_withdrawal)
	{
		//1 - MAX_WITHDRAWAL
		m_amount = 0 - double(rand() % MAX_WITHDRAWAL + 1);
		if (m_amount != -MAX_WITHDRAWAL)
		{
			m_amount -= double(rand()) / RAND_MAX; //Add change.
			/*double(rand()) / RAND_MAX;
			  taken from Objects, Abstraction, Data Structures and Design using
			  C++ by Elliot B. Koffman & Paul A.T. Wolfgang.
			  Pg. 396.
			  Generates a double number between 0 - 1.*/
		}
		return m_amount;
	}
	else
	{
		//1 - MAX_DEPOSIT
		m_amount = double(rand() % MAX_DEPOSIT + 1);
		if (m_amount != MAX_DEPOSIT)
		{
			m_amount += double(rand()) / RAND_MAX; //Add change.
			/*double(rand()) / RAND_MAX;
			  taken from Objects, Abstraction, Data Structures and Design using
			  C++ by Elliot B. Koffman & Paul A.T. Wolfgang.
			  Pg. 396.
			  Generates a double number between 0 - 1.*/
		}
		return m_amount;
	}
}

/*Assignment operator overloading.
  Ensures that the private member variables of class Transaction gets assigned
  properly.
  Code obtained from:
  Lecture notes from CS201 SM-13 class.*/
Transaction& Transaction::operator=(const Transaction& trans)
{
	if (this == &trans)
	{
		//Check for self assignment.
		return *this;
	}
	m_withdrawal = trans.m_withdrawal;
	m_amount = trans.m_amount;

	return *this;
}