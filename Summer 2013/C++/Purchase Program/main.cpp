/*William Freeman
  CS201L
  7/08/2013
  Midterm 1 - Create an Item class that holds an item's name and price. Let the
  user choose an item item from the list to purschase. Output their total.*/
#include <iostream>

#include "item.h"

using std::cout;
using std::cin;
using std::endl;

void setItems(Item items[]);
//Assigns values to items that are constained within the array.
void showItems(Item items[]);
//Outputs the name and price of each Item contained within the array.
void purschaseItems(Item items[], Item purschased[], int choice, int& numItems, double& total);
//Based upon the user's selection, function adds the price of the item to the
//total and increments the number of items purschased.
//Adds the selected item to the purschased array.

int main()
{
	Item items[6], purschased[21];
	int choice = 0, numItems = 0;
	double total = 0.00;
	setItems(items);
	do
	{
		showItems(items);
		cout << "Enter the item number you would like to purschase: ";
		cin >> choice;
		purschaseItems(items, purschased, choice, numItems, total);
		//Do not allow the user to exceed the allocated space for purschased[].
		if (numItems == 20)
		{
			cout << "\nMaxium number of items purschased has been met\n"
				 << "Cannot purschase more at this time...\n";
			//Set choice = 7 in order to end loop and display their total for
			//the purschase.
			choice = 7;
			purschaseItems(items, purschased, choice, numItems, total);
		}
	} while (choice != 7);

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

void purschaseItems(Item items[], Item purschased[], int choice, int& numItems, double& total)
{
	// Case 1-6 are similar except the index #, can you use another method to optimize the code?
	switch(choice)
	{
	case 1:
		{
			cout << endl << items[0].getName() << " purschased\n\n";
			total += items[0].getPrice();
			purschased[numItems].setName(items[0].getName());
			purschased[numItems].setPrice(items[0].getPrice());
			numItems++;
			break;
		}
	case 2:
		{
			cout << endl << items[1].getName() << " purschased\n\n";
			total += items[1].getPrice();
			purschased[numItems].setName(items[1].getName());
			purschased[numItems].setPrice(items[1].getPrice());
			numItems++;
			break;
		}
	case 3:
		{
			cout << endl << items[2].getName() << " purschased\n\n";
			total += items[2].getPrice();
			purschased[numItems].setName(items[2].getName());
			purschased[numItems].setPrice(items[2].getPrice());
			numItems++;
			break;
		}
	case 4:
		{
			cout << endl << items[3].getName() << " purschased\n\n";
			total += items[3].getPrice();
			purschased[numItems].setName(items[3].getName());
			purschased[numItems].setPrice(items[3].getPrice());
			numItems++;
			break;
		}
	case 5:
		{
			cout << endl << items[4].getName() << " purschased\n\n";
			total += items[4].getPrice();
			purschased[numItems].setName(items[4].getName());
			purschased[numItems].setPrice(items[4].getPrice());
			numItems++;
			break;
		}
	case 6:
		{
			cout << endl << items[5].getName() << " purschased\n\n";
			total += items[5].getPrice();
			purschased[numItems].setName(items[5].getName());
			purschased[numItems].setPrice(items[5].getPrice());
			numItems++;
			break;
		}
	case 7:
		{
			cout << "\nItems pursched: " << numItems << endl;
			for (int index = 0; index < numItems; index++)
			{
				cout << index + 1 << ". " << purschased[index].getName()
					 << "\t$" << purschased[index].getPrice() << endl;
			}
			cout << "Total: $" << total << endl << endl;
			break;
		}
	default:
		{
			cout << "\nInvalid menu selection try again\n\n";
		}
	}
}