/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.*/
#include <iostream>

#include "employeeHandler.h";
#include "scheduleHandler.h";

using std::cout;
using std::endl;
using std::cin;

enum MenuOptions {QUIT, ADD_EMPLOYEE, EDIT_EMPLOYEE, LAYOFF_EMPLOYEE,
	VIEW_EMPLOYEE, UPDATE_SCHEDULE, CANCEL_SCHEDULE, VIEW_SCHEDULE,
	EXPORT_SCHEDULE_CSV, EXPORT_SCHEDULE_HTML, EXPORT_EMPLOYEES_CSV,
	EXPORT_EMPLOYEES_HTML};

void displayMainMenu();
//Displays the main menu for the Employee Manager Program.
void menuFuncCalls(int choice, bool& done, EmployeeHandler& employeeHandler,
				   ScheduleHandler& scheduleHandler);
//Calls the appropriate function calls or the appropriate member functions.

int main()
{
	int menuSelection;
	bool done = false;
	EmployeeHandler employeeManager;
	ScheduleHandler scheduleManager;
	do
	{
		//Display menu options for user
		displayMainMenu();
		cout << "What would you like to do? ";
		cin >> menuSelection;
		menuFuncCalls(menuSelection, done, employeeManager, scheduleManager);
	} while (done == false);
	return 0;
}

void displayMainMenu()
{
	cout << "BUSINESS MANAGEMENT SYSTEM!\n"
		 << "---------------------------\n"
		 << "EMPLOYEE OPTIONS\n"
		 << "---------------------------\n"
		 <<	ADD_EMPLOYEE << ". Add Employee\n"
		 << EDIT_EMPLOYEE << ". Edit Employee\n"
		 << LAYOFF_EMPLOYEE << ". Layoff Employee\n"
		 << VIEW_EMPLOYEE << ". View Employee List\n"
		 << "---------------------------\n"
		 << "SCHEDULING OPTIONS\n"
		 << "---------------------------\n"
		 << UPDATE_SCHEDULE << ". Update Schedule\n"
		 << CANCEL_SCHEDULE << ". Cancel Schedule\n"
		 << VIEW_SCHEDULE << ". View Shcedule\n"
		 << "---------------------------\n"
		 << "EXPORT OPTIONS\n"
		 << "---------------------------\n"
		 << EXPORT_SCHEDULE_CSV << ". Export Schedule to CSV\n"
		 << EXPORT_SCHEDULE_HTML << ". Export Schedule to HTML\n"
		 << EXPORT_EMPLOYEES_CSV << ". Export a list of Employees to CSV\n"
		 << EXPORT_EMPLOYEES_HTML << ". Export a list of Employees to HTML\n"
		 << "---------------------------\n"
		 << QUIT << ". Quit\n"
		 << "---------------------------\n";
}

void menuFuncCalls(int choice, bool& done, EmployeeHandler& employeeHandler,
				   ScheduleHandler& scheduleHandler)
{
	switch (choice)
	{
	case QUIT:
		{
			cout << "--------\n"
			     << "GOODBYE!\n"
				 << "--------\n";
			done = true;
			break;
		}
	case ADD_EMPLOYEE:
		{
			employeeHandler.AddEmployee();
			break;
		}
	case EDIT_EMPLOYEE:
		{
			employeeHandler.EditEmployee();
			break;
		}
	case LAYOFF_EMPLOYEE:
		{
			employeeHandler.LayoffEmployee();
			break;
		}
	case VIEW_EMPLOYEE:
		{
			employeeHandler.DisplayEmployeeList();
			break;
		}
	case UPDATE_SCHEDULE:
		{
			scheduleHandler.AddSchedule(employeeHandler);
			break;
		}
	case CANCEL_SCHEDULE:
		{
			scheduleHandler.CancelSchedule();
			break;
		}
	case VIEW_SCHEDULE:
		{
			scheduleHandler.DisplaySchedule();
			break;
		}
	case EXPORT_SCHEDULE_CSV:
		{
			scheduleHandler.ExportScheduleCSV();
			break;
		}
	case EXPORT_SCHEDULE_HTML:
		{
			scheduleHandler.ExportScheduleHTML();
			break;
		}
	case EXPORT_EMPLOYEES_CSV:
		{
			employeeHandler.ExportEmployeeCSV();
			break;
		}
	case EXPORT_EMPLOYEES_HTML:
		{
			employeeHandler.ExportEmployeeHTML();
			break;
		}
	default:
		cout << "\nNOT A VALID MENU SELECTION\n\n";
	}
}