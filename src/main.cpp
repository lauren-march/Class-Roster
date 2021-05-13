#include "roster.h"

int main() {

	//Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming Applications C867, C++, 001421111, Lauren March." << std::endl << std::endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Lauren,March,lmarc30@wgu.edu,28,22,45,30,SOFTWARE"
	};
		
	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Complete Student Roster" << std::endl;
	roster.printAll();
	cout << std::endl << std::endl;
	
	cout << "List of invalid emails:" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl << std::endl;
	
	cout << "Average number of days in three courses for a student: " << std::endl;
	for (int i = 0; i < numStudents; i++) {
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
	}
	cout << std::endl;

	cout << "Students with SOFTWARE degree: " << std::endl;
	roster.printByDegreeProgram(SOFTWARE);
	cout << std::endl;
	
	cout << "Removing student ID # A3:" << std::endl;
	roster.removeStudent("A3");
	cout << std::endl;

	cout << "Updated student roster: " << std::endl;
	roster.printAll();
	cout << std::endl;

	cout << "Removing student ID # A3:" << std::endl;
	roster.removeStudent("A3");
	cout << std::endl;

	system("pause");
	return 0;





	

}