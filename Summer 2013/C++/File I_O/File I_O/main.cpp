/*William Freeman
  CS201L
  6/18/2013
  File I/O: Read from student.txt and place the information in a 2D array.
  Then obtain input in terms of a number from the user and write to a file
  counting form 1 to the user's number.*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Variable used for the 2D array
enum fileInfo{NAME, ID, CLASS};

void read();
//Reads information from student.txt and places the infromation in
//a 2D array.

void write(int userChoice);
//Writes to a file counting from 1 to userChoice.
//Increasing by 1 each time.

int main()
{
	read();

	int num;
	cout << "Please enter a number: ";
	cin >> num;
	cout << endl;
	write(num);

	return 0;
}

void read()
{
	//Array to store infromation from student.txt
	string roster[20][3];
	ifstream inFile;
	inFile.open("student.txt");
	int index = 0;
	while(!inFile.eof())
	{
		inFile >> roster[index][NAME]; 
		inFile >> roster[index][ID];
		inFile >> roster[index][CLASS];
		index++;
	}
	inFile.close();
	for(int i = 0; i < 12; i++)
		cout << roster[i][NAME] << " " << roster[i][ID] << " " << roster[i][CLASS] << endl;
}


void write(int userChoice)
{
	ofstream outFile;
	outFile.open("output.txt");
	//Iterate from 1 - userChoice and output to file
	for (int index = 1; index <= userChoice; index++)
		outFile << index << " ";
	outFile.close();
}