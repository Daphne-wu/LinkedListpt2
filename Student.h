
#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>

using namespace std;
//create class student
class Student {
 public:
 //constructor and destructor
  Student();
  ~Student();
 //to get and set the name of student
  char* getFirst();
  char* getLast();
	int getID();
	float getGPA();
	void setFirst(char* first);
	void setLast(char* last);
	void setID(int idd);
	void setGPA(float gpaa);

 //variables w public access
  char* firstName;
	char* lastName;
	int id;
	float gpa;
};
#endif