/*William Freeman
  CS201L
  7/30/2013
  Final Exam - Student Records
  Description: Create a program that helps the school administration to
  maintain student records.*/
#ifndef _SORTED_LIST
#define _SORTED_LIST
#include "student.h"

class SortedList
{
private:
	Student* m_list;
	int m_size;
	int m_numOfStudents;

	//Increases the size of m_list & m_size by 5.
	//Creates a new temp_list and copies the values over from m_list.
	//Resizes m_list and them copies values back from temp_list.
	void IncreaseSize();
	//Sorts the Students contained within m_list by their id.
	//Uses a bubble sort method.
	void Sort() const;
	//Performs a recursive binary search.
	int Search(int min, int max, int item) const;
public:
	//Default constructor.
	//Initalizes m_size to 5 and m_numOfStudents to 0.
	//Creates a new m_list of Students of size 5.
	SortedList();
	//Consturctor.
	//Initalizes m_size to the parameter variable passed, m_numOfStudents to 0.
	//Creates a new m_list of Students of m_size.
	SortedList(int size);
	//Destructor.
	//Frees memory.
	~SortedList();
	//Returns the values contained within m_list.
	Student* GetSortedItems();
	//Returns the value of m_numOfStudents.
	int GetNumOfStudents() const;
	//Adds a new student to m_list.
	//If m_list is full, resizes m_list.
	//Sorts m_list after new student is added.
	void AddStudent(Student student);
	//Removes a Student from m_list at the index.
	void Remove(int index);
	//Searches through m_list and attempts to find a Student by the id of the Student.
	//Returns a default Student if not found, returns the Student in m_list if
	//the Student is found.
	Student SearchById(int id) const;
}; //SortedList

#endif //_SORTED_LIST