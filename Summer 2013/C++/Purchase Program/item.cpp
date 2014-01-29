/*William Freeman
  CS201L
  7/08/2013
  Midterm 1 - Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total.*/
#include "item.h"

//Default constructor.
//Initalizes 0 values.
Item::Item()
{
	m_name = "";
	m_price = 0.00;
}

//Consructor with parameters.
//Initalizes member variables to the specific parameters.
Item::Item(string name, double price)
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