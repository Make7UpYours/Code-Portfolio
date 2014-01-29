/*William Freeman
  CS201L
  7/18/2013
  Lab Assignment 10 - List Template
  Description: This lab consists of creating various template classes and their
  uses in the STL.*/
#include <iostream>

#include "money.h"

using std::cout;

//Default constructor.
//Initalizes default values for member variables.
Money::Money()
{
	m_amount = 0.00;
	m_unit = "dollar";
}

//Constructor with 1 parameter.
//Initalizes values for m_amount and default values for m_unit.
Money::Money(double amount)
{
	m_amount = amount;
	m_unit = "dollar";
}

//Constructor with 2 parameters.
//Initalizes values for m_amount and m_unit.
Money::Money(double amount, string unit)
{
	m_amount = amount;
	m_unit = unit;
}

//Returns the value of m_amount.
double Money::getValue()
{
	return m_amount;
}

//Returns the value of m_unit.
string Money::getUnit()
{
	return m_unit;
}

//Overloads the + operator.
//Checks to determine if the two money types are compatiable.
//Returns their sum if they are, -1 if not.
Money operator+(Money& m1, Money& m2)
{
	if (m1.m_unit == m2.m_unit)
	{
		return m1.m_amount + m2.m_amount;
	}
	else
	{
		cout << "Attempted to add two Money types of different units.\n"
			 << "The value of the sum is set to -1\n";
		return -1;
	}
}