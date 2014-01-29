/*William Freeman
  CS201L
  6/20/2013
  LibraryBook class defination file.*/
#include <iostream>
#include <string>
using namespace std;

#include "LibraryBook.h"

//Constructor: Initializes isCheckedOut to false, and string values to empty.
LibraryBook::LibraryBook()
{
	checkedOut = false;
	title = "";
	author = "";
	ISBN = "";
}

//Sets checkedOut to false, only if checkedOut is true
//otherwise outputs an error message.
void LibraryBook::checkIn()
{
	if (checkedOut == true)
		checkedOut = false;
	else
		cout << "Error: Attempted to check in a "
		     << "book that is already checked in\n";
}

//Sets checkedOut to true, only if checkedOut is false
//otherwise outputs an error message.
void LibraryBook::checkOut()
{
	if (checkedOut == false)
		checkedOut = true;
	else
		cout << "Error: Attempted to check in a "
		     << " book that is already checked out\n";
}

//Allows the user to set the title of type LibraryBook by passing param
//bookTitle.
void LibraryBook::setTitle(string bookTitle)
{
	title = bookTitle;
}

//Allows the user to set the author of type LibraryBook by passing param
//bookAuthor.
void LibraryBook::setAuthor(string bookAuthor)
{
	author = bookAuthor;
}

//Allows the user to set the ISBN of type LibraryBook by passing param
//bookISBN.
void LibraryBook::setISBN(string bookISBN)
{
	ISBN = bookISBN;
}

//Checks to determine is the book is currently checked out
bool LibraryBook::isCheckedOut() const
{
	return checkedOut;
}

//Returns the value of title of LibraryBook
string LibraryBook::getTitle() const
{
	return title;
}

//Returns the value of author of LibraryBook
string LibraryBook::getAuthor() const
{
	return author;
}

//Returns the value of ISBN of LibraryBook
string LibraryBook::getISBN() const
{
	return ISBN;
}