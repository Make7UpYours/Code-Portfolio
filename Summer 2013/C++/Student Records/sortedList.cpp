/*William Freeman
  CS201L
  7/30/2013
  Final Exam - Student Records
  Description: Create a program that helps the school administration to
  maintain student records.*/
#include <iostream>

#include "sortedList.h"
#include "student.h"

using std::cout;
using std::endl;

//Default constructor.
//Initalizes m_size to 5 and m_numOfStudents to 0.
//Creates a new m_list of Students of size 5.
SortedList::SortedList()
{
	m_size = 5;
	m_numOfStudents = 0;
	m_list = new Student[m_size];
}

//Consturctor.
//Initalizes m_size to the parameter variable passed, m_numOfStudents to 0.
//Creates a new m_list of Students of m_size.
SortedList::SortedList(int size)
{
	m_size = size;
	m_numOfStudents = 0;
	m_list = new Student[m_size];
}

//Destructor.
//Frees memory.
SortedList::~SortedList()
{
	delete [] m_list;
}

//Returns the values contained within m_list.
Student* SortedList::GetSortedItems()
{
	return m_list;
}

//Returns the value of m_numOfStudents.
int SortedList::GetNumOfStudents() const
{
	return m_numOfStudents;
}

//Adds a new student to m_list.
//If m_list is full, resizes m_list.
//Sorts m_list after new student is added.
void SortedList::AddStudent(Student student)
{
	if (m_numOfStudents == m_size)
	{
		//m_list is full.
		IncreaseSize();
	}

	m_list[m_numOfStudents] = student;
	m_numOfStudents++;
	Sort();
}

//Removes a Student from m_list at the index.
void SortedList::Remove(int index)
{
	if (index < 0 || index >= m_numOfStudents)
	{
		cout << "\nAttempted to remove a Student at an invalid index of: "
			 << index << endl << endl;
		return;
	}
	for (int i = index; i < m_numOfStudents - 1; i++)
	{
		m_list[i] = m_list[i + 1];
	}
	m_numOfStudents--;
}

//Searches through m_list and attempts to find a Student by the id of the Student.
//Returns a default Student if not found, returns the Student in m_list if
//the Student is found.
Student SortedList::SearchById(int id) const
{
	int index = Search(0, m_numOfStudents, id);

	if (index == -1)
	{
		//Id not found.
		cout << "\nStudent id: " << id << " was not found in the list of students.\n"
			 << "SearchById() is returning a NULL student value.\n\n";
		Student NULLStudent;
		return NULLStudent;
	}
	else
	{
		return m_list[index];
	}
}

//Increases the size of m_list & m_size by 5.
//Creates a new temp_list and copies the values over from m_list.
//Resizes m_list and them copies values back from temp_list.
void SortedList::IncreaseSize()
{
	int oldSize = m_size;
	m_size += 5;
	Student* temp_list = new Student[m_size];
	for (int index = 0; index < oldSize; index++)
	{
		temp_list[index] = m_list[index];
	}
	delete [] m_list;
	m_list = new Student[m_size];
	for (int index = 0; index < oldSize; index++)
	{
		m_list[index] = temp_list[index];
	}
	delete [] temp_list;
}

//Sorts the Students contained within m_list by their id.
//Uses a bubble sort method.
void SortedList::Sort() const
{
	for (int i = 0; i < m_numOfStudents - 1; i++)
	{
		for (int j = 1; j < m_numOfStudents; j++)
		{
			if ( m_list[i].m_id > m_list[j].m_id)
			{
				//Swap values
				Student temp;
				temp = m_list[i];
				m_list[i] = m_list[j];
				m_list[j] = temp;
			}
		}
	}
}

//Performs a recursive binary search.
int SortedList::Search(int min, int max, int item) const
{
	if (max < min)
	{
		//item not found.
		return -1;
	}
	else
	{
		//Find the mid-point.
		int mid = (min + max) / 2;
		if (m_list[mid].m_id > item)		
		{
			//Search lower half.
			return Search(min, mid - 1, item);
		}
		else if (m_list[mid].m_id < item)
		{
			//Search upper half.
			return Search(mid + 1, max, item);
		}
		else
		{
			//item found.
			return mid;
		}
	}
}