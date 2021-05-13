#pragma once
#include "student.h"

class Roster 
{
private:
	int iterator = -1;
	const static int numStudents = 5;
	

public:
	Student* classRosterArray[numStudents];
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
	
	void printAverageDaysInCourse(string studentID); 

	void printInvalidEmails();
	
	void printByDegreeProgram(DegreeProgram degree);
	
	~Roster();


};