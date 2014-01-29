/*William Freeman
  CS201L
  7/09/2013
  Lab Assignment 7 - Dynamic Shopping
  Description: Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total. Now 
  keep track of the user's purschases using a dynamic array.*/
#include <iostream>

#include "item.h"

using std::cout;
using std::cin;
using std::endl;

void setItems(Item items[]);
//Assigns values to items that are constained within the array.
void showItems(Item items[]);
//Outputs the name and price of each Item contained within the array.
Item* purschaseItems(Item items[], Item* purschased, int choice, int& numItems, double& total);
//Based upon the user's selection, function adds the price of the item to the
//total and increments the number of items purschased.
//Adds the selected item to the purschased array.
//Returns a newly incremented array.

int main()
{
	Item items[6];
	int choice = 0, numItems = 0;
	double total = 0.00;
	Item* purschased = new Item[numItems + 1];
	setItems(items);
	do
	{
		showItems(items);
		cout << "Enter the item number you would like to purschase: ";
		cin >> choice;
		purschased = purschaseItems(items, purschased, choice, numItems, total);
	} while (choice != 7);

	delete []purschased;
	return 0;
}

void setItems(Item items[])
{
	items[0].setName("Laptop");
	items[0].setPrice(1250.00);
	items[1].setName("Printer");
	items[1].setPrice(499.99);
	items[2].setName("Desktop");
	items[2].setPrice(399.99);
	items[3].setName("Monitor");
	items[3].setPrice(125.50);
	items[4].setName("Keyboard");
	items[4].setPrice(45.00);
	items[5].setName("Mouse");
	items[5].setPrice(12.99);
}

void showItems(Item items[])
{
	cout << "#  Item name\tPrice\n";
	for (int index = 0; index < 6; index++)
	{
		cout << index + 1 << "  " << items[index].getName() << "\t$"
			 << items[index].getPrice() << endl;
	}
	cout << "7. Finish\n";
}

Item* purschaseItems(Item items[], Item* itemsPurschased, int choice, int& numItems, double& total)
{
	// Can you improve the code to omit mostly repeated codes?
	switch(choice)
	{
	case 1:
		{
			cout << endl << items[0].getName() << " purschased\n\n";
			total += items[0].getPrice();
			itemsPurschased[numItems].setName(items[0].getName());
			itemsPurschased[numItems].setPrice(items[0].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 2:
		{
			cout << endl << items[1].getName() << " purschased\n\n";
			total += items[1].getPrice();
			itemsPurschased[numItems].setName(items[1].getName());
			itemsPurschased[numItems].setPrice(items[1].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 3:
		{
			cout << endl << items[2].getName() << " purschased\n\n";
			total += items[2].getPrice();
			itemsPurschased[numItems].setName(items[2].getName());
			itemsPurschased[numItems].setPrice(items[2].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 4:
		{
			cout << endl << items[3].getName() << " purschased\n\n";
			total += items[3].getPrice();
			itemsPurschased[numItems].setName(items[3].getName());
			itemsPurschased[numItems].setPrice(items[3].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 5:
		{
			cout << endl << items[4].getName() << " purschased\n\n";
			total += items[4].getPrice();
			itemsPurschased[numItems].setName(items[4].getName());
			itemsPurschased[numItems].setPrice(items[4].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 6:
		{
			cout << endl << items[5].getName() << " purschased\n\n";
			total += items[5].getPrice();
			itemsPurschased[numItems].setName(items[5].getName());
			itemsPurschased[numItems].setPrice(items[5].getPrice());
			numItems++;
			//Increase the size of the dynamic array.
			Item* temp = new Item[numItems + 1];
			for (int index = 0; index < numItems; index++)
			{
				temp[index].setName(itemsPurschased[index].getName());
				temp[index].setPrice(itemsPurschased[index].getPrice());
			}
			return temp;
			break;
		}
	case 7:
		{
			cout << "\nItems pursched: " << numItems << endl;
			for (int index = 0; index < numItems; index++)
			{
				cout << index + 1 << ". " << itemsPurschased[index].getName()
					 << "\t$" << itemsPurschased[index].getPrice() << endl;
			}
			cout << "Total: $" << total << endl << endl;
			return itemsPurschased;
			break;
		}
	default:
		{
			cout << "\nInvalid menu selection try again\n\n";
			return itemsPurschased;
		}
	}
}