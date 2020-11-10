//pranav's code

#include "Node.h"
Node::Node(Student* ptr1) {
	//student = new Student();
	student = ptr1;
	next = NULL;
}

Node::~Node() {
	delete &student;
	next = NULL;

}

Student* Node::getStudent() {
	return student;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* value) {
	next = value;
}




// #include <iostream>
// #include <string>
// #include "Node.h"

// using namespace std;

// Node::Node() {
// 	student = new Student();
// 	next = NULL;
// }

// Node::~Node() {
// 	delete &student;
// 	next = NULL;
// }

// void Node::setStudent(Student* newStudent) {
//   student = newStudent;
// }

// void Node::setNext(Node* newNext) {
//   next = newNext;
// }

// Student* Node::getStudent() {
//   return student;
// }

// Node* Node::getNext() {
//   return next;
// }