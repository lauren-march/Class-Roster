#pragma once
#include "student.h"

class Roster 
{
private:
	int iterator = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);
	void add(string studID,
		string fName,
		string lName,
		string emailAdd,
		int ageStud,
		int days1,
		int days2,
		int days3,
		DegreeProgram deg);
	
	void removeStudent(string studentID);
	
	void printAll();
	
	void printAverageDaysInCourse(); 

	void printInvalidEmails();
	
	void printByDegreeProgram(DegreeProgram degree);
	
	~Roster();


};