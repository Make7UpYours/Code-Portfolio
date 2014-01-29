/*William Freeman
  CS201L
  7/09/2013
  Lab Assignment 7 - Dynamic Shopping
  Description: Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total. Now 
  keep track of the user's purschases using a dynamic array.*/
#ifndef _ITEM
#define _ITEM
#include <string>

using std::string;

class Item
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Item();
	//Consructor with parameters.
	//Initalizes member variables to the specific parameters.
	Item(string name, double price);
	//Assigns the parameter passed to the member variable m_name.
	void setName(string name);
	//Returns the value of m_name for an instance of Item class.
	string getName() const;
	//Assigns the parameter passed to the member variable m_price.
	void setPrice(double price);
	//Returns the value of m_price for an instance of Item class.
	double getPrice() const;
private:
	string m_name;
	double m_price;
};
#endif