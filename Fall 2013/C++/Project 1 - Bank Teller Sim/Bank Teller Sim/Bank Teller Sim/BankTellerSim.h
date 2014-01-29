/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --BankTellerSim.h is the header file for the BankTellerSim class--
  Class Desciption: BankTellerSim controls the main portion of the simulation.*/
#ifndef _BANK_TELLER_SIM_H
#define _BANK_TELLER_SIM_H
#include <stack>
#include <vector>
#include <fstream>
#include "Customer.h"

using std::stack;
using std::vector;
using std::ofstream;
using std::endl;

class BankTellerSim
{
private:
	//Member variables
	stack<Customer> m_waitLine;
	int m_custServed;
	vector<string> m_firstNameList;
	vector<string> m_lastNameList;
	ofstream m_report;
	
	//Static & const variables
	//Max num of transactions allowed per Customer.
	static const int MAX_TRANSACTIONS = 3;
	//Max starting balance allowed for a Customer + 1.
	static const int MAX_STARTING_BAL = 10001;
	const double ARRIVAL_PROB; //Arrival rate of Customers.
	
	//Member functions
	/*Generates a random double between 0 - 1 and determines if a Customer will 
	  join the wait line.*/
	void AddCustomer();
	/*Outputs the total number of Customers that are left wiating in line along
	  with the name of the next customer to be served.*/
	void OutputWaitLine() const;
	/*Fills the vectors, m_firstNameList & m_lastNameList with names from the txt
	files that contain these names.*/
	void LoadNames();
	/*Generates a random int between 0 - m_firstNameList.size() - 1.
	  Returns a random name from m_firstNameList.*/
	string SelectFirstName() const;
	/*Generates a random int between 0 - m_lastNameList.size() - 1.
	  Returns a random name from m_lastNameList.*/
	string SelectLastName()const;
	/*Serves the next Customer in line. Determines the amount of Transactions that
	  Customer will make. Takes into account the amout of time that Customer takes
	  per Transaction and calls AddCustomer() during each time tick.*/
	void ServeCustomer();
	/*Creates a report of each and every Transaction made in a .csv file.
      Includes details about the Transaction in the format:
	  LAST,FIRST,START_BAL,TRANS_TYPE,TRANS_AMT,CUR_BAL.*/
	void ReportTransaction(Customer& cust, double startBal, double endBal);
public:
	//Constructors
	/*Default constructor.
	  Initalizes member variables to default values for an instance of class
	  BankTellerSim. Also loads in the list of names for Customers from the files
	  FirstNames.txt & LastNames.txt.
	  Creates the header to a .csv report file.*/
	BankTellerSim():
		m_custServed(0), ARRIVAL_PROB(0.15)
	{
		LoadNames();
		m_report.open("Transaction Report.csv");
		m_report << "LAST,FIRST,START_BAL,TRANS_TYPE,TRANS_AMT,CUR_BAL" << endl;
	}
		
	//Member functions
	/*Runs the Bank Teller Simulation until the specified number of customers 
	  have been served.
	  @param num - the number of Customers to be served before the simulation
	  ends.*/
	void RunSim(int num);
}; //class BankTellerSim
  
#endif //_BANK_TELLER_SIM_H
  
