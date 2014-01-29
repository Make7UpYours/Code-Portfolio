/*William Freeman
  CS201L
  7/11/2013
  Lab Assignment 8 - Overloading Shopping
  Description: Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total. Now 
  keep track of the user's purschases using a dynamic array. An addition is 
  added to include operator overloading and friend functions.*/
#include <iostream>
#include <fstream>

#include "item.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ifstream;

int getNumItemsInFile();
//Counts the number of items contained within the text file.
//Returns the number of items stored within the file.
void setItems(Item items[], int totalItems);
//Assigns values to items that are constained within the array.
void showItems(Item items[], int totalItems);
//Outputs the name and price of each Item contained within the array.
Item* purschaseItems(Item items[], Item* purschased, int choice, int& numItems, double& total,
					int totalItems);
//Based upon the user's selection, function adds the price of the item to the
//total and increments the number of items purschased.
//Adds the selected item to the purschased array.
//Returns a newly incremented array.
void operator>>(istream& in, Item& item);
//Overloads the >> operator which allows use of >> to read in all information
//for an Item class.

int main()
{
	int totalItems, choice = 0, numItems = 0;
	//Determine how many items are contained within the text file.
	totalItems = getNumItemsInFile();
	Item* items = new Item[totalItems];
	double total = 0.00;
	Item* purschased = new Item[numItems + 1];
	setItems(items, totalItems);
	do
	{
		showItems(items, totalItems);
		cout << "Enter the item number you would like to purschase: ";
		cin >> choice;
		purschased = purschaseItems(items, purschased, choice, numItems, total, totalItems);
	} while (choice != totalItems + 1);

	delete []items;
	delete []purschased;
	return 0;
}

int getNumItemsInFile()
{
	ifstream inFile;
	Item buffer;
	int numItems = 0;
	inFile.open("items.txt");
	while (!inFile.eof())
	{
		inFile >> buffer;
		numItems++;
	}
	inFile.close();
	return numItems;
}

void setItems(Item items[], int totalItems)
{
	ifstream inFile;
	inFile.open("items.txt");
	for (int index = 0; index < totalItems; index++)
	{
		inFile >> items[index];
	}
	inFile.close();
}

void showItems(Item items[], int totalItems)
{
	for (int index = 0; index < totalItems; index++)
	{
		cout << index + 1 << ". " << items[index];
	}
	cout << totalItems + 1 << ". Check Out\n";
}

Item* purschaseItems(Item items[], Item* itemsPurschased, int choice, int& numItems, double& total,
					int totalItems)
{
	if (choice > 0 && choice <= totalItems)
	{
		//choice is 1 greater than the items index
		int itemIndex = choice - 1;
		cout << endl << items[itemIndex].getName() << " purschased\n\n";
		total += items[itemIndex].getPrice();
		itemsPurschased[numItems].setName(items[itemIndex].getName());
		itemsPurschased[numItems].setPrice(items[itemIndex].getPrice());
		numItems++;
		//Increase the size of the dynamic array.
		Item* temp = new Item[numItems + 1];
		for (int index = 0; index < numItems; index++)
		{
			temp[index].setName(itemsPurschased[index].getName());
			temp[index].setPrice(itemsPurschased[index].getPrice());
		}
		return temp;
	}
	else if (choice == totalItems + 1)
	{//User decided to checkout.
		cout << "\nItems pursched: " << numItems << endl;
		for (int index = 0; index < numItems; index++)
		{
			cout << index + 1 << ". " << itemsPurschased[index].getName()
				<< "\t$" << itemsPurschased[index].getPrice() << endl;
		}
		cout << "Total: $" << total << endl << endl;
		return itemsPurschased;
	}
	else
	{//Invalid Input
		cout << "\nInvalid menu selection try again\n\n";
		return itemsPurschased;
	}
}

void operator>>(istream& in, Item& item)
{
	string name;
	in >> name;
	double price;
	in >> price;
	item.setName(name);
	item.setPrice(price);
}