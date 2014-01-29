/*William Freeman
  CS201L
  7/11/2013
  Lab Assignment 8 - Overloading Shopping
  Description: Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total. Now 
  keep track of the user's purschases using a dynamic array. An addition is 
  added to include operator overloading and friend functions.*/
#ifndef _ITEM
#define _ITEM
#include <string>
#include <fstream>

using std::string;
using std::ostream;

class Item
{
public:
	//Default constructor.
	//Initalizes 0 values.
	Item();
	//Consructor with parameters.
	//Initalizes member variables to the specific parameters.
	Item(const string& name, double price);
	//Assigns the parameter passed to the member variable m_name.
	void setName(string name);
	//Returns the value of m_name for an instance of Item class.
	string getName() const;
	//Assigns the parameter passed to the member variable m_price.
	void setPrice(double price);
	//Returns the value of m_price for an instance of Item class.
	double getPrice() const;
	//Prints an Item's name and price.
	friend void print(Item& item);
	//Prints an Item's name and price using << operator.
	friend ostream& operator<<(ostream& out, Item& item);
private:
	string m_name;
	double m_price;
};
#endif