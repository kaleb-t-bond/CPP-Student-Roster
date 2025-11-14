#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <array>

using namespace std;

class Roster {

public:

	static const int numStudents = 5;
	Student* classRosterArray[numStudents];

	//Looping
	int i;
	int j;

	//For parsing
	int k; //Position after the comma
	int l; //length

	
	//Constructor for class
	int amountOfStudents;
	Roster(int amountOfStudents);

	//Destructor
	~Roster();

    //Function for classRosterArray to get student id
	string GetID(int currStudent) const;

	//Parse, add, and remove functions
	void parse(string studentData);

	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysinCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(string studentID);


	//Print functions
	//Loop through all students in classRosterArray and call the print() function for each student.
	void printAll();

	//Print the student's average number of days in 3 courses.
	//Student is identified by studentID.
	void printAverageDaysInCourse(string studentID);

	//Print invalid emails. Valid emails must contain an '@' and '.' with no spaces ' '.
	void printInvalidEmails();

	//Print out student information for a degree program specified by an enumerated data type
	void printByDegreeProgram(DegreeProgram degreeProgram);


};




#endif

