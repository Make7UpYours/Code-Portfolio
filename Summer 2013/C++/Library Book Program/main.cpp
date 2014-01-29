/*William Freeman
  CS201L
  6/20/2013
  Lab 3 - Library Checkout Program
  Description: Create a program that will read through a list of books in a text
  file and determine is the book has been checked out for the day by comparing 
  with a text file containing checked out books.*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "LibraryBook.h"

int initializeBooks(LibraryBook bookArr[]);
//Reads through books.txt and sets the apporiate values for LibraryBooks
//in bookArr[]. Returns the number of books that the library has.

void checkOut(LibraryBook bookArr[], int booksInLib);
//Reads through isbns.txt and determines whether or not a book in bookArr[]
//is currently checked out.

void reportCheckedOut(LibraryBook bookArr[], int booksInLib);
//Writes a report to the file checkedout.txt of all the books that are currently
//checked out.

int main()
{
	int numOfBooks;
	LibraryBook books[20];

	numOfBooks = initializeBooks(books);
	checkOut(books, numOfBooks);
	reportCheckedOut(books, numOfBooks);
	
	cout << "Test Complete\n";
	system("PAUSE");
	return 0;
}

int initializeBooks(LibraryBook bookArr[])
{
	ifstream inFile;
	inFile.open("books.txt");
	int index = 0;
	string title, author, ISBN;
	char fileInput[100];
	//Iterate through each line in the books.txt file and set the values per line
	//to their respected books in bookArr[]
	while (!inFile.eof())
	{
		inFile.getline(fileInput,100);
		title = string(fileInput);
		bookArr[index].setTitle(title);
		inFile.getline(fileInput,100);
		author = string(fileInput);
		bookArr[index].setAuthor(author);
		inFile.getline(fileInput,100);
		ISBN = string(fileInput);
		bookArr[index].setISBN(ISBN);
		index++;
	}
	inFile.close();
	return index;
}

void checkOut(LibraryBook bookArr[], int booksInLib)
{
	ifstream inFile;
	inFile.open("isbns.txt");
	string fileISBN, bookISBN;
	char fileInput[100];
	//Read through the ISBNs contained within isbns.txt
	while(!inFile.eof())
	{
		inFile.getline(fileInput,100);
		fileISBN = string(fileInput);
		//Iterate through books in bookArr[] and check for matching ISBN
		for (int index = 0; index < booksInLib; index++)
		{
			bookISBN = bookArr[index].getISBN();
			if (fileISBN == bookISBN)
			{
				//book is being checked in
				if (bookArr[index].isCheckedOut())
					bookArr[index].checkIn();
				else //book is being chekced out
					bookArr[index].checkOut();
			}
		}
	}
	inFile.close();
}
	
void reportCheckedOut(LibraryBook bookArr[], int booksInLib)
{
	ofstream outFile;
	outFile.open("checkedout.txt");
	outFile << "Title \t Author \t ISBN\n";
	for (int index = 0; index < booksInLib; index++)
	{
		//Write to report a list of checked out books
		if (bookArr[index].isCheckedOut())
			outFile << bookArr[index].getTitle() << " \t "
				    << bookArr[index].getAuthor() << " \t "
					<< bookArr[index].getISBN() << endl;
	}
	outFile.close();
}