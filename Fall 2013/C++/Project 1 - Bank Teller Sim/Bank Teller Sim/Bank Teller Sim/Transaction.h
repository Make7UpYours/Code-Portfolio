/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --Transaction.h is the header file for the Transaction class--
  Class Desciption: Transaction contains the information pertaining to a 
  customer's transaction.*/
#ifndef _TRANSACTION_H
#define _TRANSACTION_H

class Transaction
{
private:
	//Member variables
	bool m_withdrawal;
	double m_amount;
	
	//Static & const member variables
	static const int MAX_WITHDRAWAL = 500; //Max amount allowed to withdrawal.
	static const int MAX_DEPOSIT = 5000; //Max amount allowed to deposit.
	const double WITHDRAWAL_PROB; //Probability for a withdrawal.

	//Member functions
	/*Determines if the Transaction is to be a withdrawl or a deposit based
	  upon the WITHDRAWL_PROB.*/
	void DetermineTransType();
public:
	//Constructors
	/*Default constructor.
	  Initalizes member variables to default values for an instance of
	  class Transaction.*/
	Transaction():
		m_withdrawal(false), m_amount(0.0), WITHDRAWAL_PROB(0.25) {}
	
	//Member functions
	/*Calls DetermineTransType() to determine the Transaction type.
	  Returns the amount to add or subtract from the Customer's bank account.*/
	double RunTransaction();
	
	//Operator overloads
	/*Assignment operator overloading.
	  Ensures that the private member variables of class Transaction gets 
	  assigned properly.
	  Code obtained from:
	  Lecture notes from CS201 SM-13 class.*/
	Transaction& operator=(const Transaction& trans);
}; //class Transaction
  
#endif //_TRANSACTION_H

