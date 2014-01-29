/*William Freeman
  CS201L
  7/02/2013
  Lab Assignment 6 - Museum
  Description: Create a list of all specimens in the museum each with attributes
  for the particular type of specimen using class inheritence.*/
#include <iostream>
#include <fstream>
#include <string>

#include "animal.h"
#include "human.h"
#include "bird.h"
#include "dog.h"

using std::cout;
using std::ifstream;
using std::endl;
using std::string;

//Reads in humans.txt, assigns variables to the appropriate values.
void LoadHumans();
//Displays humans array to the screen with all the appropriate attributes listed.
void DisplayHumans(Human humans[]);
//Reads in birds.txt, assigns variables to the appropriate values.
void LoadBirds();
//Displays birds array to the screen with all the appropriate atributes listed.
void DisplayBirds(Bird birds[]);
//Reads in dogs.txt, assigns variables to the appropriate values.
void LoadDogs();
//Displays dogs array to the screen with all the appropriate attributes listed.
void DisplayDogs(Dog dogs[]);

int main()
{
	
	cout << "The Little Museum Specimens:\n";
	cout << "Specimen list:\n";
	LoadHumans();
	LoadBirds();
	LoadDogs();
	return 0;
}

void LoadHumans()
{
	Human humans[3];
	ifstream inFile;
	string ethnic, language, buffer;
	double length, weight;
	char fileInput[100];
	int numHumans = 0;
	inFile.open("humans.txt");
	//Iterate through file and assign variables
	for (int index = 0; index < 3; index++)
	{
		inFile.getline(fileInput, 100);
		ethnic = string(fileInput);
		inFile.getline(fileInput, 100);
		language = string(fileInput);
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		length = atof(buffer.c_str());
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		weight = atof(buffer.c_str());
		humans[index].Setup(ethnic, language, weight, length);
		numHumans++;
	}
	cout << numHumans << " Humans\n";
	DisplayHumans(humans);
	inFile.close();
}

void DisplayHumans(Human humans[])
{
	cout << "HUMANS:";
	for (int index = 0; index < 3; index++)
	{
		cout << "\n\tHuman[" << index + 1 << "]:\n"
			 << "\tETHNICITY: " << humans[index].getEthnic() << endl
			 << "\tLANGUAGE: " << humans[index].getLanguage() << endl
			 << "\tWEIGHT: " << humans[index].getWeight() << " lbs\n"
			 << "\tHEIGHT: " << humans[index].getLength() << " cm\n";
	}
}

void LoadBirds()
{
	Bird birds[3];
	ifstream inFile;
	string name, foodHabit, buffer;
	double length, weight;
	bool canFly;
	char fileInput[100];
	int numBirds = 0;
	inFile.open("birds.txt");
	//Iterate through file and assign variables
	for (int index = 0; index < 3; index++)
	{
		inFile.getline(fileInput, 100);
		name = string(fileInput);
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		canFly = atoi(buffer.c_str());
		inFile.getline(fileInput, 100);
		foodHabit = string(fileInput);
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		length = atof(buffer.c_str());
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		weight = atof(buffer.c_str());
		birds[index].Setup(name, canFly, foodHabit, weight, length);
		numBirds++;
	}
	cout << numBirds << " Birds\n";
	DisplayBirds(birds);
	inFile.close();
}

void DisplayBirds(Bird birds[])
{
	cout << "BIRDS:";
	for (int index = 0; index < 3; index++)
	{
		cout << "\n\tBird[" << index + 1 << "]:\n"
			 << "\tNAME: " << birds[index].getName() << endl
			 << "\tFOOD HABIT: " << birds[index].getFoodHabit() << endl
			 << "\tWEIGHT: " << birds[index].getWeight() << " lbs\n"
			 << "\tLENGTH: " << birds[index].getLength() << " cm\n";
		if (birds[index].getCanFly())
		{
			cout << "\tCAN FLY: YES\n";
		}
		else
		{
			cout << "\tCAN FLY: NO\n";
		}
	}
}

void LoadDogs()
{
	Dog dogs[3];
	ifstream inFile;
	string breed, buffer;
	double length, weight, lifeSpan;
	char fileInput[100];
	int numDogs = 0;
	inFile.open("dogs.txt");
	//Iterate through file and assign variables
	for (int index = 0; index < 3; index++)
	{
		inFile.getline(fileInput, 100);
		breed = string(fileInput);
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		lifeSpan = atof(buffer.c_str());
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		length = atof(buffer.c_str());
		inFile.getline(fileInput, 100);
		buffer = string(fileInput);
		weight = atof(buffer.c_str());
		dogs[index].Setup(breed, lifeSpan, weight, length);
		numDogs++;
	}
	cout << numDogs << " Dogs\n";
	DisplayDogs(dogs);
	inFile.close();
}

void DisplayDogs(Dog dogs[])
{
	cout << "DOGS:";
	for (int index = 0; index < 3; index++)
	{
		cout << "\n\tDog[" << index + 1 << "]:\n"
			 << "\tBREED: " << dogs[index].getBreed() << endl
			 << "\tLIFE SPAN: " << dogs[index].getLifeSpan() << endl
			 << "\tWEIGHT: " << dogs[index].getWeight() << " lbs\n"
			 << "\tLENGTH: " << dogs[index].getLength() << " cm\n";
	}
}