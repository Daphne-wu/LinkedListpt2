// The program creates linked lists  with Students Daphne, Sarah, Kim
#include <iostream>
#include <cstring>
#include <iomanip>
#pragma warning(disable : 4996)
#include "Node.h"
#include "Student.h"



void add(Node* head, Node* node, Node* previous);
void printList(Node* next);
void deleteStudent(Node* &head, int id, Node* &previous);
void askForInfo(Student* student);
float average(Node* head);

//Node* head = NULL;

int main() {
	bool playing = true;
	char* input = new char();
	Node* head = NULL;

	while (playing) {
		cout << "Welcome to Student List! What would you like to do: ADD, AVERAGE, PRINT, DELETE, QUIT." << endl;
		cin.getline(input, 10, '\n');

		if (strcmp(input, "ADD") == 0) {
			//create the new student to be added
			Student* newStudent = new Student();
			//create the node that holds the student
			Node* node = new Node(newStudent);
			//ask for student information
			askForInfo(newStudent);
			//create node pointing to nothing that holds the previous valude
			Node* previous = NULL;
			if (head != NULL) {
               //if added node has an id lower than  head, it the new node = head
               if (head->getStudent()->getID() >= newStudent->getID()) {
               		//set the next node as the head
                   node->setNext(head);
                   //the the node after that to NULL
                   head->setNext(NULL);
                   //the node becomes the new head
                   head = node;
                   
               }
                // else its put in the add function where it is sorted in the list
                else {
                    add(head, node, previous);
                    //delete extra node
                    delete previous;
                }
            }
            //otherwise if there is nothing inside the list, it become the first node
            else {
            	head = node;
            }
		}
		else if (strcmp(input, "AVERAGE") == 0) {
			cout << "The average of the students' GPA's is: " << fixed << setprecision(2) << average(head) << endl;
		}
		else if (strcmp(input, "PRINT") == 0) {
			printList(head);
		}
		else if (strcmp(input, "DELETE") == 0) {
			int id = 0;
            cout << "Which id would you like to delete?\n";
            cin >> id;
            cin.get();
            //first check if the first node is the one to be deleted
            if (head->getStudent()->getID() == id) {
            	//if it is, set a tempoary node to equal to head
              Node* temp = head;
              // the head becomes the next node in the list
              head = head->getNext();A   
            }
            //otherwise just delete;
            else {
            	//create a node to hold the previous value
            	Node *previous = NULL;
            	//set a temp variable to be the head
            	Node* temp = head;
            	//run the delete function
            	deleteStudent(temp, id, previous);
        	}
		}
		else if (strcmp(input, "QUIT") == 0) {
			playing = false;
		}
		else {
			cout << "Ah man, invalid input, try again?" << endl;
		}
	}

	//delete everything

}


//ADD
//You should create a new entry for a student.  
//After you type in add, the program should prompt for first name, last name, student id, and GPA.  
//You should then insert a new node into your linked list, sorting it by student id number (least to greatest).
// USE RECURSION. (20 points)
void add(Node* head, Node* node, Node* previous) {
	Node* current = head;
	bool check = false;

	if (head != NULL) {
		//check if node is less than or equal to the node value
		if (node->getStudent()->getID() <= head->getStudent()->getID()) {
			//push the node to where the head is
			node->setNext(current);
			check = true;
			if (previous != NULL) {
				//set the previous to the node
				previous->setNext(node);
			}
		}
	
		//otherwise, if the current node is larger and not the last in the list, repeat the process over again
		else {
            if (current->getNext() != NULL && check == false) {
                previous = current;
                add(current->getNext(), node, previous);
            }
            // if no nodes are less than the added node, then its tagged on at the end
            else if (current->getNext() == NULL) {
                current->setNext(node);
                //set the next node to null
                node->setNext(NULL);

            }
        }
	}
}

//which prints the GPA average of all students, shown to two decimal places.
float average(Node* head) {
	Node* current = head;
	float sum = 0.0;
	int size = 0;

	while(current != NULL) {
		sum = sum + current->getStudent()->getGPA();
		current = current->getNext();
		++size;
	}
	return (sum / (float)size);

}

//prints student
void printList(Node* next) {
	  if (next != NULL) {
            cout << "Name: " << next->getStudent()->getFirst() << " " << next->getStudent()->getLast() << " ID: " << next->getStudent()->getID() << " GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
            next = next->getNext();
            printList(next);
    }
}

//delete student fuction
void deleteStudent(Node* &head, int id, Node* &previous) {
	//set a current node equal to the head
	Node* current = head;
	// if the head exists
	if (head != NULL) {
		//then compare the current node to the id of the student and if they are the same ->
		if(current->getStudent()->getID() == id) {
			//check if the current node is the last node in the list, then set the second to last =null
			if (current->getNext() == NULL) {
				//if the previous is not null
				if (previous != NULL) {
					//then set the previous to null
					previous->setNext(NULL);
				}
				//otherwise just delete the current node
				delete current;
			}
			//skip over current and delete current
			else if (previous != NULL) {
				//connects the previous node the node after the current one
				previous->setNext(current->getNext());
				//deletes the current nodt\e
				delete current;
			}
		}
		//otherwise do it again
		else {
			Node* next = current->getNext();
			deleteStudent(next, id, current);
		}
	}
}

//as for the information of the student and store it in the student value passed in
void askForInfo(Student* student) {
	char* input = new char[20];
	cout << "Student first name: ";
	cin >> input;
	student->setFirst(input);
	cout << "Student last name: ";
	cin >> input;
	student->setLast(input);
	cout << "Student ID: ";
	cin >> student->id;
	cout << "Student GPA: ";
	cin >> student->gpa;
	//to make sure there are no left over cin
	cin.get();
}
