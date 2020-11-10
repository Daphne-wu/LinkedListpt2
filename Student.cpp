#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student() {
	firstName = new char();
	lastName = new char();
	id = 0;
	gpa = 0.0;
}

Student::~Student() {
	delete firstName;
	delete lastName;
}

char* Student::getFirst() {
	return firstName;
}
char* Student::getLast() {
	return lastName;
}
int Student::getID() {
	return id;
}
float Student::getGPA() {
	return gpa;
}
void Student::setFirst(char* first) {
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);
}
void Student::setLast(char* last) {
	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);
}
void Student::setID(int idd) {
	id = idd;
}
void Student::setGPA(float gpaa) {
	gpa = gpaa;
}
