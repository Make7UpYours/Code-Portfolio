/*William Freeman
  CS201L
  6/20/2013
  LibraryBook class header file*/
#ifndef _LIBRARYBOOK
#define _LIBRARYBOOK

#include <string>
using namespace std;

class LibraryBook
{
public:
	LibraryBook();
	//Constructor: Initializes isCheckedOut to false, and string values to empty.
	void checkIn();
	//Sets checkedOut to false, only if checkedOut is true
	//otherwise outputs an error message.
	void checkOut();
	//Sets checkedOut to true, only if checkedOut is false
	//otherwise outputs an error message.
	void setTitle(string bookTitle);
	//Allows the user to set the title of type LibraryBook by passing param
	//bookTitle.
	void setAuthor(string bookAuthor);
	//Allows the user to set the author of type LibraryBook by passing param
	//bookAuthor.
	void setISBN(string bookISBN);
	//Allows the user to set the ISBN of type LibraryBook by passing param
	//bookISBN.
	bool isCheckedOut() const;
	//Checks to determine is the book is currently checked out
	string getTitle() const;
	//Returns the value of title of LibraryBook
	string getAuthor() const;
	//Returns the value of author of LibraryBook
	string getISBN() const;
	//Returns the value of ISBN of LibraryBook

private:
	bool checkedOut;
	string title;
	string author;
	string ISBN;

};
#endif