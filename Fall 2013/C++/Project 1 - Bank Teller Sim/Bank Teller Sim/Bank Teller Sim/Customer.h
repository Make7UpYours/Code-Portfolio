/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --Customer.h is the header file for the Customer class--
  Class Desciption: Customer contains the information about the customer
  that is waiting in line. Includes the customer's last name, first name,
  balance, and transaction.*/
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>
#include <cstdlib>
#include "Transaction.h"

using std::string;

class Customer
{
private:
	//Member variables
	string m_lastName;
	string m_firstName;
	double m_curBalance;
	int m_serveTime;
	Transaction m_transaction;

	//Static const variables
	static const int MAX_SERVE_TIME = 5;
	//Max time a Customer will take per Transaction.
public:
	//Constructors
	/*Default constructor.
	  Sets member variables to default values for an instance of class
	  Customer.*/
	Customer():
		m_lastName("Last"), m_firstName("First"), m_curBalance(0.0)
	{
		//1 - MAX_SERVE_TIME
		m_serveTime = rand() % MAX_SERVE_TIME + 1;
	}
	/*Sets the member variables to the values passed as parameters,
	  m_curBalance is set as a default value.
	  @param last - last name of Customer.
	  @param first - first name of Customer.*/
	Customer(string first, string last):
		m_lastName(last), m_firstName(first), m_curBalance(0.0)
	{
		//1 - MAX_SERVE_TIME
		m_serveTime = rand() % MAX_SERVE_TIME + 1;
	}
	/*Sets the member variables to the values passed as parameters.
	  @param last - last name of Customer.
	  @param first - first name of Customer.
	  @param bal - the current balance of Customer's account.*/
	Customer(string first, string last, double bal):
		m_lastName(last), m_firstName(first), m_curBalance(bal)
	{
		//1 - MAX_SERVE_TIME
		m_serveTime = rand() % MAX_SERVE_TIME + 1;
	}
		
	//Member functions
	/*Returns the value of m_curBalance for an instance of class
	  Customer.*/
	double GetCurBal() const
	{
		return m_curBalance;
	}
	/*Returns a concatenation of the Customer's name, in a last, first
	  format.*/
	string GetName() const
	{
		return m_lastName + ", " + m_firstName;
	}
	/*Returns the value of m_serveTime for an instance of class Customer.*/
	int GetServeTime() const
	{
		return m_serveTime;
	}
	/*Runs a Transaction for the Customer & updates the Customer's
	  current balance accordingly based upon the Transaction type.*/
	void MakeTransaction();
	
	//Operator overloads
	/*Assignment operator overloading.
	  Ensures that the private member variables of class Customer gets assigned
	  properly.
	  Code obtained from:
	  Lecture notes from CS201 SM-13 class.*/
	Customer& operator=(const Customer& cust);
}; //class Customer

#endif //_CUSTOMER_H
