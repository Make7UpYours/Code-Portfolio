/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --Customer.cpp is the implementation file for the Customer class--
  Class Desciption: Customer contains the information about the customer
  that is waiting in line. Includes the customer's last name, first name,
  balance, and transaction.*/
#include "Customer.h"

/*Runs a Transaction for the Customer & updates the Customer's
  current balance accordingly based upon the Transaction type.*/
void Customer::MakeTransaction()
{
	double transAmount;
	do
	{
		transAmount = m_transaction.RunTransaction();
	} while ((m_curBalance + transAmount) < 0); //Prevent a negative balance.
	m_curBalance += transAmount;
}

/*Assignment operator overloading.
  Ensures that the private member variables of class Transaction gets assigned
  properly.
  Code obtained from:
  Lecture notes from CS201 SM-13 class.*/
Customer& Customer::operator=(const Customer& cust)
{
	if (this == &cust)
	{
		//Check for self-assignment.
		return *this;
	}
	m_lastName = cust.m_lastName;
	m_firstName = cust.m_firstName;
	m_curBalance = cust.m_curBalance;
	m_serveTime = cust.m_serveTime;
	m_transaction = cust.m_transaction;

	return *this;
}