#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "roster.h"
#include "degree.h"


//Constructor by default
Student::Student() {
	id = "";
	fName = "";
	lName = "";
	email = "";
	yearsOld = 0;
	numDays[0] = 0;
	numDays[1] = 0;
	numDays[2] = 0;
	degreeProg = SECURITY;
}



//Constructor with parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse[], DegreeProgram degreeProgram) {
	id = studentID;
	fName = firstName;
	lName = lastName;
	email = emailAddress;
	yearsOld = age;
	numDays[0] = daysinCourse[0];
	numDays[1] = daysinCourse[1];
	numDays[2] = daysinCourse[2];
	degreeProg = degreeProgram;
}



//Function definitions
//Setter functions
void Student::SetStudentID(string studentId) {
	id = studentId;
}

void Student::SetFirstName(string firstName) {
	fName = firstName;
}

void Student::SetLastName(string lastName) {
	lName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
	email = emailAddress;
}

void Student::SetAge(int studentAge) {
	yearsOld = studentAge;
}

//Assign values to array numDays
void Student::SetDaysInCourse(int daysCourse1, int daysCourse2, int daysCourse3) {
	numDays[0] = daysCourse1;
	numDays[1] = daysCourse2;
	numDays[2] = daysCourse3;
}

void Student::SetDegreeProgram(DegreeProgram programType) {
	degreeProg = programType;
}


//Getter functions
string Student::GetStudentID() const {
	return id;
}

string Student::GetFirstName() const {
	return fName;
}

string Student::GetLastName() const {
	return lName;
}

string Student::GetEmailAddress() const {
	return email;
}

int Student::GetAge() const {
	return yearsOld;
}

int Student::GetDaysInCourse(int index) const {
	return numDays[index];
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeProg;
}



//Print function
void Student::Print() const {

	//Assign string to enum type
	string degreeType;
	switch (degreeProg) {

	case (SECURITY):
		degreeType = "SECURITY";
		break;

	case (NETWORK):
		degreeType = "NETWORK";
		break;

	case (SOFTWARE):
		degreeType = "SOFTWARE";
		break;
		
	default:
		degreeType = "INVALID TYPE";
		break;
	}
	/*
	if (degreeProg == SECURITY) {
		degreeType = "SECURITY";
	}
	else if (degreeProg == NETWORK) {
		degreeType = "NETWORK";
	}
	else if (degreeProg == SOFTWARE) {
		degreeType = "SOFTWARE";
	}
	else {
		degreeType = "INVALID DEGREE TYPE";
	}
	*/

	//Print information about student
	cout << GetStudentID() << "\t" <<
		"First Name: " << GetFirstName() << "\t" <<
		"Last Name: " << GetLastName() << "\t" <<
		"Age: " << GetAge() << "\t" <<
		"daysInCourse: {" << GetDaysInCourse(0) << ", " << GetDaysInCourse(1) << ", " << GetDaysInCourse(2) << "} " <<
		"Degree Program: " << degreeType << endl;

}