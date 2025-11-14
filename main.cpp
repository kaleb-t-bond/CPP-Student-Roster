#include <iostream>
#include <string>
#include <array>
using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"

int main(){


	
	//Initial data
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Kaleb,Bond ,kbon108@wgu.edu,30,14,45,21,SOFTWARE"
	};

	int i;


	//First to print
	cout << "Course Title: C 867" << endl;
	cout << "Programming language used: C++" << endl;
	cout << "WGU student ID: 010878096" << endl;
	cout << "Name: Kaleb Bond" << endl;


	//Instance of Roster called classRoster
	Roster * classRoster = new Roster(5);


	//Parse data
	for (i = 0; i < 5; ++i) {
		classRoster->parse(studentData[i]);
	}

	//Print all
	classRoster->printAll();

	//Print invalid emails
	classRoster->printInvalidEmails();

	
	//Loop through classRosterArray for each element
	for (i = 0; i < 5; ++i) {
		classRoster->printAverageDaysInCourse(classRoster->GetID(i));
	}
	cout << endl;
	

	//Follow psuedocode instructions
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster->remove("A3");
	cout << endl;

	classRoster->printAll();

	//Message should appear saying the student id was not found
	classRoster->remove("A3");
	cout << endl;

	//Implement destruction...
	cout << "Deleting data..." << endl;
	classRoster->~Roster();
	delete classRoster;





	return 0;
}