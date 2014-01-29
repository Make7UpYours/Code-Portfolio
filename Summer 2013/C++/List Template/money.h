/*William Freeman
  CS201L
  7/18/2013
  Lab Assignment 10 - List Template
  Description: This lab consists of creating various template classes and their
  uses in the STL.*/
#ifndef _MONEY
#define _MONEY
#include <string>

using std::string;

class Money
{
private:
	double m_amount;
	string m_unit;
public:
	//Default constructor.
	//Initalizes default values for member variables.
	Money();
	//Constructor with 1 parameter.
	//Initalizes values for m_amount and default values for m_unit.
	Money(double amount);
	//Constructor with 2 parameters.
	//Initalizes values for m_amount and m_unit.
	Money(double amount, string unit);
	//Returns the value of m_amount.
	double getValue();
	//Returns the value of m_unit.
	string getUnit();
	//Overloads the + operator.
	//Checks to determine if the two money types are compatiable.
	//Returns their sum if they are, -1 if not.
	friend Money operator+(Money& m1, Money& m2);
};
#endif //_MONEY