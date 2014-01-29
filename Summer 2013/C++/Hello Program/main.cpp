/*William Freeman
  CS201L
  Assignment 1 - Hello Program
  6/13/2013*/
#include <iostream>
#include <string>
using namespace std;

void Hello();
//Function obtains the user's name and tells them hello

int main()
{
	Hello();
	//Pause system in order to read output
	system( "PAUSE" );
	return 0;
}

void Hello()
{
	string username;
	//Prompt for name
	cout << "What is your name?\n";
	cin >> username;
	//Greet user
	cout << "Hello " << username << endl;
}