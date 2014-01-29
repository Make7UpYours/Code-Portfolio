/*William Freeman
  CS201R
  6/28/2013
  Assignment 3 - Employee Manager
  Description: An employee management and scheduling application. The user will
  be able to add, update, and lay-off employees, as well as update and clear out
  the schedule. They will also be able to export the schedule to a CSV or HTML
  file.
  --scheduleHandler.h is the header file for the ScheduleHandler class--*/
#ifndef _SCHEDULE_HANDLER
#define _SCHEDULE_HANDLER
#include <string>

#include "schedule.h"
#include "employeeHandler.h"

using std::string;

class ScheduleHandler
{
public:
	//Default constructor.
	//Initalizes all elements in m_lstSchedule.
	ScheduleHandler();
	//Iterates through m_lstSchedule and calls the Output function.
	void DisplaySchedule() const;
	//User selects the hour they wish to assign an employee to.
	//Then selects the employee to assign for that hour,
	//Assigns the employee for that time slot in the schedule.
	void AddSchedule(EmployeeHandler& employeeHandler);
	//Prompts user to select an hour which will be reset.
	void CancelSchedule();
	//Exports the schedule as a .csv file.
	void ExportScheduleCSV() const;
	//Exports the schedule as an HTML file.
	void ExportScheduleHTML() const;
	//Outputs the schedule to user and asks for an hour selection.
	//Returns their selection.
	int ScheduleSelection() const;
private:
	Schedule m_lstSchedule[24];
};
#endif