#include "roster.h"
#include <string>



void Roster::parse(string studentData)
{


	int i = studentData.find(",");
	string studentID = studentData.substr(0, i);

	int j = i + 1;
	i = studentData.find(",", j);
	string firstName = studentData.substr(j, i - j);

	j = i + 1;
	i = studentData.find(",", j);
	string lastName = studentData.substr(j, i - j);

	j = i + 1;
	i = studentData.find(",", j);
	string emailAddress = studentData.substr(j, i - j);

	j = i + 1;
	i = studentData.find(",", j);
	int ageStudent = stod(studentData.substr(j, i - j));

	j = i + 1;
	i = studentData.find(",", j);
	int days1 = stod(studentData.substr(j, i - j));

	j = i + 1;
	i = studentData.find(",", j);
	int days2 = stod(studentData.substr(j, i - j));

	j = i + 1;
	i = studentData.find(",", j);
	int days3 = stod(studentData.substr(j, i - j));

	DegreeProgram degree;
	//DegreeProgram degree = SECURITY;
	if (studentData.at(studentData.size() - 1) == 'K') {
		
		degree = NETWORK;
	}
	else if (studentData.at(studentData.size() - 1) == 'Y') {

		degree = SECURITY;
	}
	else if (studentData.at(studentData.size() - 1) == 'E') {

		degree = SOFTWARE;
	}
		

	add(studentID, firstName, lastName, emailAddress, ageStudent, days1, days2, days3, degree);
	
}

	void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
		int ageStudent, int daysCourse1, int daysCourse2, int daysCourse3, DegreeProgram degree) 
	{
		int daysCourse[3] = { daysCourse1,daysCourse2,daysCourse3 };
		classRosterArray[++iterator] = new Student(studentID, firstName, lastName, emailAddress, 
			ageStudent, daysCourse, degree);

	}

	void Roster::printAll()
	{
		cout << "Student ID \t First Name \t Last Name \t Email \t Age \t Days in Course \t Degree Program" << std::endl;
		for (int i = 0; i <= Roster::iterator; i++) classRosterArray[i]->print();

	
	}
	void Roster::printByDegreeProgram(DegreeProgram degree)
	{
		
		for (int i = 0; i <= Roster::iterator; i++)
		{
				if (Roster::classRosterArray[i]->getDegree() == degree) classRosterArray[i]->print();
			
		}
		cout << std::endl;

	}

	void Roster::printInvalidEmails()
	{
		bool any = false;
		for (int i = 0; i <= Roster::iterator; i++) 
		{
			string emailAddressInvalid = (classRosterArray[i]->getEmail());
			if (emailAddressInvalid.find(' ') != string::npos || (emailAddressInvalid.find('@') == string::npos || emailAddressInvalid.find('.') == string::npos))
			{
				cout << emailAddressInvalid << std::endl;
			}

		}
		
	}

	void Roster::printAverageDaysInCourse(string studentID)
	{
		for (int i = 0; i <= Roster::iterator; i++) {
			if (classRosterArray[i]->getID() == studentID) {

				cout << classRosterArray[i]->getID() << ": ";
				cout << (classRosterArray[i]->getDays()[0]
					+ classRosterArray[i]->getDays()[1]
					+ classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
			}

		}

		
		
	}

	
	void Roster::removeStudent(string studentID)
	{
		bool removedStud = false;
		for (int i = 0; i <= Roster::iterator; i++)
		{
			if (classRosterArray[i]->getID() == studentID)
			{
				removedStud = true;
				if (i < numStudents - 1)
				{
					Student* temp = classRosterArray[i];
					classRosterArray[i] = classRosterArray[numStudents - 2];
					classRosterArray[i + 1] = classRosterArray[numStudents - 1];
					classRosterArray[numStudents - 1] = temp;
				}
				Roster::iterator--;
			}
		}
		if (removedStud)
		{
			cout << studentID << " removed from roster." << std::endl << std::endl;
			
		}
		else cout << studentID << " student ID not found!" << std::endl << std::endl;
	}

	Roster::~Roster()
	{
		cout << "DESTRUCTOR EXECUTED!" << std::endl << std::endl;
		for (int i = 0; i < numStudents; i++)
		{
			cout << "Destroying student ID#" << i + 1 << std::endl;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}

