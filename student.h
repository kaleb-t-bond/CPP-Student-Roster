#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;



class Student {

private:
	string id;
	string fName;
	string lName;
	string email;
	int yearsOld;
	int numDays[3]; 
	DegreeProgram degreeProg;


public:
	//Constructors
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysinCourse[], DegreeProgram degreeProgram);

	//Create mutator functions
	void SetStudentID(string studentId); //Setter for student ID
	void SetFirstName(string firstName); //Setter for first name
	void SetLastName(string lastName); //Setter for last name
	void SetEmailAddress(string emailAddress); //Setter for email address
	void SetAge(int studentAge); //Setter for age
	//FIXME
	void SetDaysInCourse(int daysCourse1, int daysCourse2, int daysCourse3); //Setter for array of number of days to complete each course 
	void SetDegreeProgram(DegreeProgram programType); //Setter for degree program 

	//Create accessor functions
	string GetStudentID() const; //Getter for student ID
	string GetFirstName() const; //Getter for first name
	string GetLastName() const; //Getter for last name
	string GetEmailAddress() const; //Getter for email address
	int GetAge() const; //Getter for age
	//FIXME
	int GetDaysInCourse(int index) const; //Getter for number of days to complete each course //FIXME return array?
	DegreeProgram GetDegreeProgram() const; //Getter for degree program FIXME: Return value likely incorrect


	//Print function
	void Print() const;
};

#endif

