//pranav's code with some edits

#pragma once
#include <iostream>
#include "Student.h"
class Node
{
public:
	// variables in Node class
	Student* student;
	Node* next;
	// gets the next node in the linked list
	Node* getNext();
	// gets the student that the node contains
	Student* getStudent();
	// sets next node in the linked list
	void setNext(Node* ptr1);
	// constructer and destructors, initializes and deletes pointers
	Node(Student* value);
	~Node();
};










// #ifndef NODE_H
// #define NODE_H

// #include "Student.h"

// using namespace std;
// //create class node
// class Node {
// public:
// 	Node();
// 	~Node();
// 	void setStudent(Student* newStudent);
// 	Student* getStudent();
// 	void setNext(Node* newNext);
// 	Node* getNext();

// private:
// 	Student* student;
// 	Node* next;
// };
// #endif