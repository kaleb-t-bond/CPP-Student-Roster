#include <iostream>
#include <string>
#include <array>
using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"



//Function definitions

//Constructor
Roster::Roster(int amountOfStudents) {
	this->amountOfStudents = amountOfStudents;
	j = 0;

	for (i = 0; i < amountOfStudents; ++i) {
		classRosterArray[i] = new Student;
	}
}

//Destructor
Roster::~Roster() {
	for (i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}


//PARSE
void Roster::parse(string studentData) {

	//Declare variables for every entry
	string ID, first, last, mail;
	int years = 0, days1 = 0, days2 = 0, days3 = 0;

	if (j < amountOfStudents) {

		classRosterArray[j] = new Student();

		//Student ID
		i = studentData.find(",");
		ID = studentData.substr(0, i);
		classRosterArray[j]->SetStudentID(ID);

		//First name
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		first = studentData.substr(k, l);
		classRosterArray[j]->SetFirstName(first);

		//Last name
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		last = studentData.substr(k, l);
		classRosterArray[j]->SetLastName(last);

		//Electronic mail
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		mail = studentData.substr(k, l);
		classRosterArray[j]->SetEmailAddress(mail);

		//For integers: need to convert string to integer
		//Age
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		years = stoi(studentData.substr(k, l));
		classRosterArray[j]->SetAge(years);

		//Assign days1, days2, and days3, then set days
		//Day 1
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		days1 = stoi(studentData.substr(k, l));

		//Day 2
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		days2 = stoi(studentData.substr(k, l));

		//Day 3
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;
		days3 = stoi(studentData.substr(k, l));

		//Set days
		classRosterArray[j]->SetDaysInCourse(days1, days2, days3);

		//Finally, assign degree program
		k = i + 1;
		i = studentData.find(",", k);
		l = i - k;


		string degreeType = studentData.substr(k, l);
		if (degreeType == "NETWORK") {
			classRosterArray[j]->SetDegreeProgram(NETWORK);
		}
		else if (degreeType == "SOFTWARE") {
			classRosterArray[j]->SetDegreeProgram(SOFTWARE);
		}
		else if (degreeType == "SECURITY") {
			classRosterArray[j]->SetDegreeProgram(SECURITY);
		}
		else {
			cout << "No such degree program exists..." << endl;
		}


		++j;

	}
}


//Add function
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	//Input integers into an array
	int daysInCourse[3]{ daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[amountOfStudents] = new Student(studentID, firstName, lastName, emailAddress,
		age, daysInCourse, degreeProgram);

}


//Remove function
void Roster::remove(string studentID) {
	//Store a value 0 if ID does not match a student
	//Store a value of 1 if ID is found to match
	int match = 0;
	for (i = 0; i < amountOfStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			//If classRosterArray[i] is already nullptr, continue with loop
			continue;
		}
		else if (classRosterArray[i]->GetStudentID() == studentID) {
			match = 1;
			//If the input student id matches, remove it
			classRosterArray[i] = nullptr;
			break;
		}
	}
	if (match == 1) {
		cout << "The ID has been matched successfully and removed." << endl;
	}
	else if (match == 0) {
		cout << "There was no matching ID found..." << endl;
	}
}



//Print functions:
void Roster::printAll() {

	cout << "--STUDENT INFORMATION--" << endl;
	//Print all students in classRosterArray
	for (i = 0; i < amountOfStudents; ++i) {
		//Only print if classRosterArray at index i is NOT nullptr
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
		else {
			continue;
		}
	}
	cout << endl;
}


//Getter function to retrieve student id
string Roster::GetID(int currStudent) const {
	return classRosterArray[currStudent]->GetStudentID();
}

//Use student ID as a parameter
void Roster::printAverageDaysInCourse(string studentID) {

	for (i = 0; i < amountOfStudents; ++i) {
		if (studentID == classRosterArray[i]->GetStudentID()) {

			//Calculate average in a variable
			int averageDaysInCourse = ((classRosterArray[i]->GetDaysInCourse(0) +
				classRosterArray[i]->GetDaysInCourse(1) + classRosterArray[i]->GetDaysInCourse(2)) / 3);

			//Print result
			cout << "Student with ID: " << studentID << " takes " << averageDaysInCourse <<
				" days to complete a course on average." << endl;
		}
	}
}


void Roster::printInvalidEmails() {

	cout << "List of invalid email addresses: " << endl;

	for (i = 0; i < amountOfStudents; ++i) {
		string electronicMail = classRosterArray[i]->GetEmailAddress();

		//Make sure the email has a '@' and '.', but not a ' ' 
		if ((electronicMail.find('@') == string::npos) || (electronicMail.find('.') == string::npos)
			|| (electronicMail.find(' ') != string::npos)) {
			//If any of the criteria are not met, print
			cout << 
				"Student ID: " << classRosterArray[i]->GetStudentID() << " has invalid email address: " <<
				electronicMail << endl;
		}
	}
	cout << endl;
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	string degreeType;
	switch (degreeProgram) {

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

	cout << "List of students with " << degreeType << " degree program:" << endl;
	//Ensure there is at least one student with the degree program
	int studentsWithDegreeProgram = 0;

	for (i = 0; i < amountOfStudents; ++i) {
		//If the degree program matches, print it and increment studentsWithDegreeProgram
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
			++studentsWithDegreeProgram;
		}
	}
	if (amountOfStudents <= 0) {
		cout << "No students in degree program..." << endl;
	}
}