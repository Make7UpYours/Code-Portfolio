/*William Freeman
  CS201L
  6/27/2013
  Lab 5-Filesystem Structure
  Description: Create a folder class which contains a pointer that is pointing
  to that folder's parent folder. The user picks a folder and that floder along
  with the folders's parents will be outputted.*/
#ifndef _FOLDER
#define _FOLDER
#include <string>

using std::string;

class Folder
{
public:
	//Default constructor
	Folder();
	//Initalizes values for member variables
	void Setup(const string& name, Folder* ptrParentFolder);
	//Returns m_ptrParentFolder for an instance of Folder class
	Folder* GetParentFolder();
	//Retuns m_name
	string GetName();
private:
	string m_name;
	Folder* m_ptrParentFolder;
};
#endif