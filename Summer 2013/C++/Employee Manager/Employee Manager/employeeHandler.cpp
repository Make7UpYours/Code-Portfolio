/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --employeeHandler.cpp is the implementation file for the EmployeeHandler class--*/
#include <iostream>
#include <string>
#include <fstream>

#include "employeeHandler.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ofstream;

//Default constructor.
//Initalizes m_employeeCount to 0 for an instance of EmployeeHandler class.
EmployeeHandler::EmployeeHandler()
{
	m_employeeCount = 0;
	m_lstSize = 5;
	m_lstEmployees = new Employee[m_lstSize];
}

//Destructor.
//Frees memory by deleting m_lstEmployees.
EmployeeHandler::~EmployeeHandler()
{
	delete []m_lstEmployees;
}

//Prompt user for all the information for an employee and call setup function
//for the current employee.
//Increment m_employeeCount by 1.
void EmployeeHandler::AddEmployee()
{
	//m_lstEmployees has filled up.
	if (m_employeeCount == m_lstSize)
	{
		m_lstEmployees = ResizeEmployeeLst();
		//ResizeEmployeeLst();
	}

	string first, last;
	float pay;
	cout << "\n------------\n" 
		 << "NEW EMPLOYEE\n"
		 << "------------\n"
		 << "\tFirst: ";
	cin >> first;
	cout << "\tLast: ";
	cin >> last;
	cout << "\tPay: $";
	cin >> pay;
	m_lstEmployees[m_employeeCount].Setup(first, last, pay);
	cout << "\nEMPLOYEE NUMBER: " << m_employeeCount << " ADDED\n\n";
	m_employeeCount++;
}

//Displays a list of all employees.
//Allows the user to choose one and edit the employee's information.
void EmployeeHandler::EditEmployee()
{
	//Do not allow user to edit employees when there are none to edit.
	if (m_employeeCount == 0)
	{
		cout << endl
			 << "THERE ARE NO EMPLOYEES TO EDIT\n\n";
		return;
	}

	int employeeSelection;
	employeeSelection = EmployeeSelection();
	string first, last;
	float pay;

	cout << "\n-------------\n" 
		 << "EDIT EMPLOYEE\n"
	     << "-------------\n"
		 << "\tFirst: ";
	cin >> first;
	cout << "\tLast: ";
	cin >> last;
	cout << "\tPay: ";
	cin >> pay;
	m_lstEmployees[employeeSelection].Setup(first, last, pay);
	cout << "\nEMPLOYEE NUMBER: " << employeeSelection << " MODIFIED\n\n";
}

//Displays a list of all employees.
//User chooses which employee to layoff.
void EmployeeHandler::LayoffEmployee()
{
	//Do not allow user to layoff employees when there are none to layoff.
	if (m_employeeCount == 0)
	{
		cout << endl
			 << "THERE ARE NO EMPLOYEES TO LAY OFF\n\n";
		return;
	}

	cout << "\n---------------\n" 
		 << "LAYOFF EMPLOYEE\n"
	     << "---------------\n";
	int employeeSelection;
	employeeSelection = EmployeeSelection();
	m_lstEmployees[employeeSelection].LayOff();
	cout << endl
		 << m_lstEmployees[employeeSelection].GetName() << " has been laid off.\n\n";
}

//Outputs all employees from 0 to the value of m_employeeCount.
void EmployeeHandler::DisplayEmployeeList() const
{
	cout << endl;
	//Let the user know there are no employees to view.
	if (m_employeeCount == 0)
	{
		cout << "YOU CURRENTLY DO NOT HAVE ANY EMPLOYEES\n\n";
		return;
	}

	cout << "---------\n"
		 << "EMPLOYEES\n"
		 << "---------\n";
	for (int index = 0; index < m_employeeCount; index++)
	{
		cout << index << ". ";
		m_lstEmployees[index].Output();
		cout << "------------------------------------------------\n";
	}
	cout << endl;
}

//Output a list of all employees and asks the user to enter the index of
//an employee they wish to modify.
int EmployeeHandler::EmployeeSelection() const
{
	int choice;
	DisplayEmployeeList();
	do
	{
		cout << "---------------\n"
			<< "Select employee: ";
		cin >> choice;
		if (choice < 0 || choice >= m_employeeCount)
		{
			cout << "\nINVALID EMPLOYEE SELECTION\n"
				 << "TRY AGAIN\n\n";
		}
		//Ensure that the user makes a propery selection.
	} while (choice < 0 || choice >= m_employeeCount);
	return choice;
}

//Returns a reference to an Employee at index.
Employee& EmployeeHandler::GetEmployee(int index)
{
	return m_lstEmployees[index];
}

//Returns m_employeeCount for an instance of EmployeeHandler.
int EmployeeHandler::GetEmployeeCount() const
{
	return m_employeeCount;
}

//Exports the list of employees as an HTML file.
void EmployeeHandler::ExportEmployeeHTML() const
{
	cout << "\n-----------------------\n"
		 << "EMPLOYEES EXPORTED HTML\n"
		 << "-----------------------\n\n";
	ofstream outfile;
	outfile.open("Employees.html");
	outfile << "<head><title>Employees</title>" << endl;
	outfile << "<style type='text/css'>" << endl;
	outfile << "table tr td { border: solid 1px #000000; width: 200px;";
	outfile << "background: #cccccc; }" << endl;
	outfile << "</style></head>" << endl;
	outfile << "<body><table>" << endl;
	outfile << "<tr><td>NAME</td><td>PAY($)</td><td>STATUS</td></tr>" << endl;
	for (int index = 0; index < m_employeeCount; index++)
	{
		outfile << "<tr>" << endl;
		outfile << "<td>" << m_lstEmployees[index].GetName() << "</td>\n";
		outfile << "<td>" << m_lstEmployees[index].GetPay() << "</td>\n";
		if (m_lstEmployees[index].GetIsActive())
		{
			outfile << "<td>CURRENT</td>\n";
		}
		else
		{
			outfile << "<td>FORMER</td>\n";
		}
		outfile << "</tr>\n";
	}
	outfile << "</table></body>" << endl;
	outfile.close();
}
//Exports the list of employees as a .csv file.
void EmployeeHandler::ExportEmployeeCSV() const
{
	cout << "\n----------------------\n"
		 << "EMPLOYEES EXPORTED CSV\n"
		 << "----------------------\n\n";
	ofstream outFile;
	outFile.open("Employees.csv");
	outFile << "LAST,FIRST,PAY($),STATUS\n";
	for (int index = 0; index < m_employeeCount; index++)
	{
		outFile << m_lstEmployees[index].GetName() << ","
			    << m_lstEmployees[index].GetPay() << ",";
		if (m_lstEmployees[index].GetIsActive())
		{
			outFile << "CURRENT\n";
		}
		else
		{
			outFile << "FORMER\n";
		}
	}
	outFile.close();
}

//Creates a temp array which copies m_lstEmployees and increases
//m_lstSize by 5.
//Returns the newly sized temp array.
Employee* EmployeeHandler::ResizeEmployeeLst()
{
	int oldSize = m_lstSize;
	m_lstSize += 5;
	//Create a new temp array of type Employee.
	Employee* temp = new Employee[m_lstSize];
	for (int index = 0; index < oldSize; index++)
	{
		temp[index] = m_lstEmployees[index];
	}
	return temp;
}

//Unstable version of ResizeEmployeeLst().
/*void EmployeeHandler::ResizeEmployeeLst()
{
	int oldSize = m_lstSize;
	m_lstSize += 5;
	//Create a new temp array of type Employee.
	Employee* temp = new Employee[m_lstSize];
	for (int index = 0; index < oldSize; index++)
	{
		temp[index] = m_lstEmployees[index];
	}
	delete []m_lstEmployees;
	//Copy data from temp.
	Employee* m_lstEmployees = new Employee[m_lstSize];
	for (int index = 0; index < oldSize; index++)
	{
		m_lstEmployees[index] = temp[index];
	}
	delete []temp;
}*/