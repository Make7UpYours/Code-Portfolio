/*William Freeman
  CS201R
  7/15/2013
  Assignment 4 - Phonebook Application
  Description: Crate a phonebook program that will load in a list of people
  (first name, last name, phone number, and country) from a file, and enter
  them into the system. The user will then be able to view all entries or
  filter by country or last name.
  ----list.h is the header file for the template class List----*/
#ifndef _LIST
#define _LIST
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class List
{
public:
	//Default constructor.
	//Sets m_size to 0 and m_allocated to 10, creates a new m_list
	//dynamic array of size m_allocated.
	List();
	//Destructor.
	//Frees memory by deleting m_list.
	~List();
	//Checks to see if List is filled, then adds item if it is not already
	//in the List.
	void AddItem(T item);
	//Outputs all items contained within m_list.
	void OutputAll();
	//Returns m_size for an instance of List class.
	int GetSize();
	//Returns the item in m_list at the given index.
	T& GetItem(int index);
private:
	//Resizes m_list to a new size.
	//T* Resize();
	//Resize m_list (Crash fixed).
	void Resize();
	//Checks to see if item is already contained within m_list.
	bool IsAlreadyInList(const T& item);

	T* m_list;
	int m_size;
	int m_allocated;
};

//Default constructor.
//Sets m_size to 0 and m_allocated to 10, creates a new m_list
//dynamic array of size m_allocated.
template <typename T>
List<T>::List()
{
	m_size = 0;
	m_allocated = 10;
	m_list = new T[m_allocated];
}

//Destructor.
//Frees memory by deleting m_list.
template <typename T>
List<T>::~List()
{
	delete [] m_list;
}

//Checks to see if List is filled, then adds item if it is not already
//in the List.
template <typename T>
void List<T>::AddItem(T item)
{
	//List is filled up.
	if (m_size == m_allocated)
	{
		Resize();
	}
	//Do not allow for items that are not unique.
	if (!IsAlreadyInList(item))
	{
		m_list[m_size] = item;
		m_size++;
	}
}

//Outputs all items contained within m_list.
template<typename T>
void List<T>::OutputAll()
{
	for (int index = 0; index < m_size; index++)
	{
		cout << m_list[index] << endl;
	}
}

//Returns m_size for an instance of List class.
template<typename T>
int List<T>::GetSize()
{
	return m_size;
}

//Returns the item in m_list at the given index.
template<typename T>
T& List<T>::GetItem(int index)
{
	return m_list[index];
}

//Resizes m_list to a new size.
/*template<typename T>
T* List<T>::Resize()
{
	int oldSize = m_allocated;
	m_allocated += 10;
	//Copy m_list elements to a temp dynamic array.
	T* temp = new T[m_allocated];
	for (int index = 0; index < oldSize; index++)
	{
		temp[index] = m_list[index];
	}
	return temp;
}*/

//Resize m_list (Crash fixed).
template <typename T>
void List<T>::Resize()
{
	int oldSize = m_allocated;
	m_allocated += 10;
	//Copy m_list elements to a temp dynamic array.
	T* temp = new T[oldSize];
	for (int index = 0; index < oldSize; index++)
	{
		temp[index] = m_list[index];
	}
	delete [] m_list;
	//Copy temp elements into a new m_list dynamic array.
	m_list = new T[m_allocated];
	for (int index = 0; index < oldSize; index++)
	{
		m_list[index] = temp[index];
	}
	delete [] temp;
}

//Checks to see if item is already contained within m_list.
template<typename T>
bool List<T>::IsAlreadyInList(const T& item)
{
	for (int index = 0; index < m_size; index++)
	{
		if (m_list[index] == item)
		{
			//item found.
			return true;
		}
	}
	//item not found.
	return false;
}
#endif