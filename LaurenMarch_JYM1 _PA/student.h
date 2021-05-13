#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


class Student
{
public:
	const static int daysInCourseArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int ageStudent;
	int daysInCourse[daysInCourseArraySize];
	DegreeProgram degree;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int ageStudent, int daysInCourse[], DegreeProgram degree);
	~Student();

	//getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegree();

	//setters
	void setID (string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int ageStudent);
	void setDays(int daysInCourse[]);
	void setDegree(DegreeProgram degree);

	static void printHeader();

	void print();




};

