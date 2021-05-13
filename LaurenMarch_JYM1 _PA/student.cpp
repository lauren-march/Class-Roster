#include "student.h"


Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->ageStudent = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
	this->degree = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int ageStudent, int daysInCourse[], DegreeProgram degree) 
{

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->ageStudent = ageStudent;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degree = degree;
}

Student::~Student(){}

	//getter methods
	string Student::getID() {
		return this->studentID = studentID; 
	}
	string Student::getFirstName() {
		return this->firstName = firstName; 
	}
	string Student::getLastName() {
		return this->lastName = lastName; 
	}
	string Student::getEmail() {
		return this->emailAddress = emailAddress; 
	}
	int Student::getAge() {
		return this->ageStudent = ageStudent; 
	}
	int* Student::getDays() {
		return daysInCourse; 
	}
	DegreeProgram Student::getDegree() {
		return this->degree; 
	}

	//setter methods
	void Student::setID(string studentID) {
		this->studentID = studentID;
	}
	void Student::setFirstName(string firstName) {
		this->firstName = firstName;
	}
	void Student::setLastName(string lastName) {
		this->lastName = lastName;
	}
	void Student::setEmail(string emailAddress) {
		this->emailAddress = emailAddress;
	}
	void Student::setAge(int ageStudent) {
		this->ageStudent = ageStudent;
	}
	void Student::setDays(int daysInCourse[]) {
		for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	}
	void Student::setDegree(DegreeProgram deg) {
		this->degree = deg;
	}

	//header
	void Student::printHeader() {

		cout << "Student ID \t First Name \t Last Name \t Email \t Age \t Days in Course \t Degree Program" << std::endl;
	}

	void Student::print() {

		cout << this->getID() << '\t';
		cout << this->getFirstName() << '\t';
		cout << this->getLastName() << '\t';
		cout << this->getEmail() << '\t';
		cout << this->getAge() << '\t';
		cout << this->getDays()[0]<< ",";
		cout << this->getDays()[1] << ",";
		cout << this->getDays()[2] << '\t';
		cout << degreeProgramStrings[this->getDegree()] << std::endl;
	}