/*William Freeman, Andrew Schneider, Kingsley Kakie
CS303
11/5/2013
Project 2 (Programming 7 pg. 509) - Morse Code Project
Description: Store each letter of the alphabet in a node of a binary tree of
depth 4. The root node is at depth 0 and stores no letter. The left node at
depth 1 stores the letter e and the right node stores the letter t. See fig.
8.38 on pg. 510 for the remaining nodes.
To build the tree, read a file in which each line consists of a letter
followed by its code. The letters should be ordered by tree depth. To find
the position for a letter in the tree, scan the code and branch left for a
dot and branch right for a dash. Encode a message by replacing each letter by
its code symbol. Then decode the message using the Morse code tree. Make sure
you use a delimiter symbol between coded letters.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "MorseTree.h"

using namespace std;

//Functions
void PrintMorseTable();
/*Prints the table 8.11 from pg. 509 containg the Morse code for each letter
  of the alphabet.*/

int main()
{
	MorseTree mTree;

	int choice;
	string letter;
	string morse;
	string code;
	string junk;
	//prompt for and accept decision
	do
	{
		cout << "0. Quit." << endl;
		cout << "1. Encode a message to Morse Code." << endl;
		cout << "2. Decode Morse Code to a message." << endl;
		cout << "Your Choice: ";
		cin >> choice;
		getline(cin, junk); //Remove junk left in cin.
		if (choice < 0 || choice > 2)
			//Return an error if proper choice isn't made
			cout << "Invalid Choice!\n";
		switch (choice)
		{
		case 1:
			// Prompt for and accept the input - letter to encode
			cout << "\nEnter message to be translated into Morse Code  ";
			getline(cin, letter);
			code = mTree.Encode(letter);
			cout << endl;
			cout << "Your message in Morse Code is: " << code << endl << endl;
			break;
		case 2:
			PrintMorseTable();
			cout << "\nEnter the Morse code to be translated into a message\n"
				 << "(Seperate each letter by: " << mTree.GetDelimiter() << "): ";
			getline(cin, morse);
			cout << endl;
			string decodedMessage = mTree.Decode(morse);
			if (decodedMessage != "")
			{
				//An error has not occured.
				cout << "Your message is: " << decodedMessage << endl;
			}
			cout << endl;
			break;

		}
	} while (choice != 0);
	system("Pause");

	return 0;

}

void PrintMorseTable()
{
	cout << "a: ._\tb: _...\tc: _._.\td: _..\te: .\tf: .._.\n"
		 << "g: __.\th: ....\ti: ..\tj: .___\tk: _._\tl: ._..\n"
		 << "m: __\tn: _.\to: ___\tp: .__.\tq: __._\tr: ._.\n"
		 << "s: ...\tt: _\tu: .._\tv: ..._\tw:.__\tx: _.._\n"
		 << "y: _.__\tz: __..\n";
}