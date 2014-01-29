/*William Freeman
  CS201L
  7/11/2013
  Lab Assignment 8 - Overloading Shopping
  Description: Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total. Now 
  keep track of the user's purschases using a dynamic array. An addition is 
  added to include operator overloading and friend functions.*/
#include <iostream>

#include "item.h"

using std::cout;
using std::endl;

//Default constructor.
//Initalizes 0 values.
Item::Item()
{
	m_name = "";
	m_price = 0.00;
}

//Consructor with parameters.
//Initalizes member variables to the specific parameters.
Item::Item(const string& name, double price)
{
	m_name = name;
	m_price = price;
}

//Assigns the parameter passed to the member variable m_name.
void Item::setName(string name)
{
	m_name = name;
}

//Returns the value of m_name for an instance of Item class.
string Item::getName() const
{
	return m_name;
}

//Assigns the parameter passed to the member variable m_price.
void Item::setPrice(double price)
{
	m_price = price;
}

//Returns the value of m_price for an instance of Item class.
double Item::getPrice() const
{
	return m_price;
}

//Prints an Item's name and price.
void print(Item& item)
{
	cout << "Item: " << item.m_name << ", Price: $" << item.m_price << endl;
}

//Prints an Item's name and price using << operator.
ostream& operator<<(ostream& out, Item& item)
{
	out << "Item: " << item.m_name << "  \t Price: $" << item.m_price << endl;
	return out;
}