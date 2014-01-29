/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --scheduleHandler.cpp is the implementation file for the ScheduleHandler class--*/
#include <iostream>
#include <fstream>

#include "scheduleHandler.h"

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;

//Default constructor.
//Initalizes all elements in m_lstSchedule.
ScheduleHandler::ScheduleHandler()
{
	//Iterate through m_lstSchedule.
	//Calling the setup function for each hour within a day.
	for (int index = 0; index < 24; index++)
	{
		m_lstSchedule[index].Setup(index);
	}
}

//Iterates through m_lstSchedule and calls the Output function.
void ScheduleHandler::DisplaySchedule() const
{
	cout << "\n--------\n" 
		 << "SCHEDULE\n"
	     << "--------\n";
		for (int index = 0; index < 24; index++)
	{
		cout << "[" << index << "]\t";
		m_lstSchedule[index].Output();
	}
	cout << endl;
}

//User selects the hour they wish to assign an employee to.
//Then selects the employee to assign for that hour,
//Assigns the employee for that time slot in the schedule.
void ScheduleHandler::AddSchedule(EmployeeHandler& employeeHandler)
{
	//The user has not added any employees yet.
	if (employeeHandler.GetEmployeeCount() == 0)
	{
		cout << "\nYOU MUST ADD EMPLOYEES IN ORDER TO UPDATE THE SCHEDULE\n\n";
		return;
	}

	bool allLaidOff = true;
	//Iterate through the list of employees and attempt to find one that is active
	for (int index = 0; index < employeeHandler.GetEmployeeCount(); index++)
	{
		//Atleast one employee is active.
		if (employeeHandler.GetEmployee(index).GetIsActive())
		{
			allLaidOff = false;
			break; //No need to continue searching
		}
	}
	if (allLaidOff)
	{
		cout << "\nALL OF YOUR EMPLOYEES ARE NO LONGER WITH YOU\n"
			 << "ADD NEW EMPLOYEES\n\n";
		return;
	}

	cout << "\n-------------\n"
		 << "EDIT SCHEDULE\n"
		 << "-------------\n";
	int hourChoice, employeeChoice;
	hourChoice = ScheduleSelection();
	do
	{
		//User selects which employee to assign for that time slot.
		employeeChoice = employeeHandler.EmployeeSelection();
		//Employee that the user has selected is currently unemployeed.
		if (!(employeeHandler.GetEmployee(employeeChoice).GetIsActive()))
		{
			cout << "\nTHE EMPLOYEE YOU HAVE SELECTED IS NO LONGER EMPLOYEED.\n"
				 << "TRY AGAIN\n\n";
		}
	} while(!(employeeHandler.GetEmployee(employeeChoice).GetIsActive()));
	Employee& refEmployee = employeeHandler.GetEmployee(employeeChoice);
	m_lstSchedule[hourChoice].AssignEmployee(&refEmployee);
	cout << endl << employeeHandler.GetEmployee(employeeChoice).GetName()
		 << " added to the selected time slot.\n\n";
}

//Prompts user to select an hour which will be reset.
void ScheduleHandler::CancelSchedule()
{
	bool emptySchedule = true;
	//Iterate through the schedule to determine if the schedule is empty.
	for (int index = 0; index < 24; index++)
	{
		//An employee is assigned to that time slot.
		if (m_lstSchedule[index].GetIsSet())
		{
			emptySchedule = false;
			break; //No longer need to keep searching.
		}
	}
	if (emptySchedule)
	{
		cout << "\nYOUR SCHEDULE IS ALREADY EMPTY\n\n";
		return;
	}

	int hourChoice;
	cout << "\n---------------\n"
		 << "CANCEL SCHEDULE\n"
		 << "---------------\n";
	do
	{
		hourChoice = ScheduleSelection();
		//Keep looping & display error message until the user selects
		//a nonempty time slot.
		if (!(m_lstSchedule[hourChoice].GetIsSet()))
		{
			cout << "\nTHE SELECTED TIME SLOT IS ALREADY EMPTY\n"
				 << "TRY AGAIN\n";
		}
	} while (!(m_lstSchedule[hourChoice].GetIsSet()));
	m_lstSchedule[hourChoice].Reset();
}

//Exports the schedule as a .csv file
void ScheduleHandler::ExportScheduleCSV() const
{
	cout << "\n---------------------\n"
		 << "SCHEDULE EXPORTED CSV\n"
		 << "---------------------\n\n";
	ofstream outFile;
	outFile.open("Schedule.csv");
	outFile << "HOUR,EMPLOYEE_LAST,EMPLOYEE_FIRST" << endl;
	for (int index = 0; index < 24; index++)
	{
		outFile << index << ":00," << m_lstSchedule[index].GetEmployeeName()
				<< endl;
	}
	outFile.close();
}

//Exports the schedule as an HTML file
void ScheduleHandler::ExportScheduleHTML() const
{
	cout << "\n----------------------\n"
		 << "SCHEDULE EXPORTED HTML\n"
		 << "----------------------\n\n";
	ofstream outfile;
	outfile.open("Schedule.html");
	outfile << "<head><title>Schedule</title>" << endl;
	outfile << "<style type='text/css'>" << endl;
	outfile << "table tr td { border: solid 1px #000000; width: 200px;";
	outfile << "background: #cccccc; }" << endl;
	outfile << "</style></head>" << endl;
	outfile << "<body><table>" << endl;
	outfile << "<tr><td>HOUR</td><td>EMPLOYEE</td></tr>" << endl;
	for ( int i = 0; i < 24; i++ )
	{
		outfile << "<tr>" << endl;
		outfile << "<td>" << i << ":00</td>" << endl;
		outfile << "<td>";
		outfile << m_lstSchedule[i].GetEmployeeName();
		outfile << "</td>" << endl;
		outfile << "</tr>" << endl;
	}
	outfile << "</table></body>" << endl;
	outfile.close();
}

//Outputs the schedule to user and asks for an hour selection.
//Returns their selection.
int ScheduleHandler::ScheduleSelection() const
{
	int choice;
	do
	{
		DisplaySchedule();
		cout << "Enter hour selection: ";
		cin >> choice;
		//Keep looping & display error message until user picks a valid
		//time slot.
		if (choice < 0 || choice >= 24)
		{
			cout << "\nINVALID TIME SLOT CHOICE\n"
				 << "TRY AGAIN\n";
		}
	} while(choice < 0 || choice >= 24);
	return choice;
}