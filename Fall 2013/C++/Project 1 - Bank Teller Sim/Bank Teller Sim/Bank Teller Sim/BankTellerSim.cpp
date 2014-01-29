/*William Freeman
  CS303
  9/26/2013
  Project 1 - Bank Teller Simulation
  Description: Create a program that simulates a bank teller serving customers
  which are stored in a stack. The teller will serve the last customer that 
  arrives first. Customers are allowed to withdrawal or deposit when they are
  being served. The user specifies how many customers they would like served
  before the simulation ends.
  --BankTellerSim.cpp is the implementation file for the BankTellerSim class--
  Class Desciption: BankTellerSim controls the main portion of the simulation.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "BankTellerSim.h"

using std::cout;
using std::endl;
using std::rand;
using std::ifstream;

/*Generates a random double between 0 - 1 and determines if a Customer will 
  join the wait line.*/
void BankTellerSim::AddCustomer()
{
	double randNum = double(rand()) / RAND_MAX;
	/*double(rand()) / RAND_MAX;
	  taken from Objects, Abstraction, Data Structures and Design using
	  C++ by Elliot B. Koffman & Paul A.T. Wolfgang.
	  Pg. 396.
	  Generates a double number between 0 - 1.*/
	if (randNum <= ARRIVAL_PROB) //Customer joins the line.
	{
		//Obtain the required info for a Customer.
		string first = SelectFirstName();
		string last = SelectLastName();
		//0 - MAX_STARTING_BAL - 1
		double startingBal = rand() % MAX_STARTING_BAL;
		Customer cust(first, last, startingBal);
		m_waitLine.push(cust);
	}
}

/*Outputs the total number of Customers that are left wiating in line along
  with the name of the next customer to be served.*/
void BankTellerSim::OutputWaitLine() const
{
	if (m_waitLine.empty())
	{
		//No Customers in line.
		cout << "---------------------------------\n"
			 << "Currently the wait line is empty.\n";
	}
	else
	{
		cout << "---------------------------------\n"
			 << "Number of customers in line: " << m_waitLine.size() << endl
			 << "Next customer up is: " << m_waitLine.top().GetName() << endl;
	}
}

/*Fills the vectors, m_firstNameList & m_lastNameList with names from the txt
  files that contain these names.*/
void BankTellerSim::LoadNames()
{
	ifstream inFile;
	//Load in first names.
	inFile.open("FirstNames.txt");
	string name;
	cout << name << endl;
	while (inFile >> name)
	{
		m_firstNameList.push_back(name);
	}
	inFile.close();
	//Load in last names.
	inFile.open("LastNames.txt");
	while (inFile >> name)
	{
		m_lastNameList.push_back(name);
	}
	inFile.close();
}

/*Generates a random int between 0 - m_firstNameList.size() - 1.
  Returns a random name from m_firstNameList.*/
string BankTellerSim::SelectFirstName() const
{
	int randIndex = rand() % m_firstNameList.size();
	return m_firstNameList[randIndex];
}

/*Generates a random int between 0 - m_lastNameList.size() - 1.
  Returns a random name from m_lastNameList.*/
string BankTellerSim::SelectLastName() const
{
	int randIndex = rand() % m_lastNameList.size();
	return m_lastNameList[randIndex];
}

/*Serves the next Customer in line. Determines the amount of Transactions that
  Customer will make. Takes into account the amout of time that Customer takes
  per Transaction and calls AddCustomer() during each time tick.*/
void BankTellerSim::ServeCustomer()
{
	int numTransactions;
	Customer cust;
	cust = m_waitLine.top();
	m_waitLine.pop();
	//1 - MAX_TRANSACTIONS
	numTransactions = rand() % MAX_TRANSACTIONS + 1;
	//Customer might make multiple Transactions.
	for (int trans = 0; trans < numTransactions; trans++)
	{
		double startBal = cust.GetCurBal(); //Obtain the initial balance.
		int serveTime = cust.GetServeTime();
		cust.MakeTransaction();
		double endBal = cust.GetCurBal(); //Obtain balance after Transaction.
		ReportTransaction(cust, startBal, endBal);
		//Time the Customer takes per Transaction.
		for (int time = 0; time < serveTime; time++)
		{
			//Customer has a chance to show up during Transaction.
			AddCustomer();
		}
	}
	m_custServed++;
}

/*Creates a report of each and every Transaction made in a .csv file.
  Includes details about the Transaction in the format:
  LAST,FIRST,START_BAL,TRANS_TYPE,TRANS_AMT,CUR_BAL.*/
void BankTellerSim::ReportTransaction(Customer& cust, double startBal, 
									  double endBal)
{
	if (startBal > endBal)
	{
		//Transaction was a withdrawal.
		m_report << cust.GetName() << ",$" << startBal << ",Withdrawal,$"
				 << startBal - endBal << ",$" << cust.GetCurBal() << endl;
	}
	else
	{
		//Transaction is a deposit.
		m_report << cust.GetName() << ",$" << startBal << ",Deposit,$"
				 << endBal - startBal << ",$" << cust.GetCurBal() << endl;
	}
}

/*Runs the Bank Teller Simulation until the specified number of customers 
  have been served.
  @param num - the number of Customers to be served before the simulation
  ends.*/
void BankTellerSim::RunSim(int num)
{
	srand(time(NULL));
	do
	{
		if (m_waitLine.empty())
		{
			//Teller is waiting for Customers, cannot serve them.
			AddCustomer();
		}
		else
		{
			ServeCustomer();
			if (m_custServed % 5 == 0)
			{
				//Output every 5 customers served.
				OutputWaitLine();
			}
		}
	//Stop once the requested amout of Customers have been served.
	} while(m_custServed < num);
	cout << endl << "A report of all transactions have been sent to"
		 << "\"Transaction Report.txt\"\n";
	m_report.close();
}