#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class student {
private:
	int ID;
	string firstName;
	string lastName;
	float GPA;
	student* next;
	
public:
	student();
	student(int ID, string firstName, string lastName, float GPA);
	student(student &init);
	~student();
	
	int getID() {
		return ID;
	}
	float getGPA() {
		return GPA;
	}
	void setID(int id) {
		ID = id;
	}
	void setGPA(float gpa) {
		GPA = gpa;
	}
	
	string getFirst() {
		return firstName;
	}
	string getLast() {
		return lastName;
	}
	void setFirst(string first) {
		firstName = first;
	}
	void setLast(string last) {
		lastName = last;
	}
	
	student* getNext() {
		return next;
	}
	void setNext(student* Next) {
		next = Next;
	}
};

student* head = NULL;

student::student() {
	this->ID = 0;
	this->firstName = " ";
	this->lastName = " ";
	this->GPA = 0.0;
	this->next = NULL;
}

student::student(int id, string first, string last, float gpa) {
	this->ID = id;
	this->firstName = first;
	this->lastName = last;
	this->GPA = gpa;
	this->next = NULL;
}

student::student(student &init) {
	this->ID = init.ID;
	this->firstName = init.firstName;
	this->lastName = init.lastName;
	this->GPA = init.GPA;
	next = init.next;
}

student::~student() {
}

student* studentMake(int id);
void studentNodeAdd(student* studentAdd);
void studentRead(void);
void studentNodeInsert(student* studentAdd);
void studentNodeDelete(int id);
void readList(void);
void menu(void);
void update(int id);

int main() {
	int id; 
	int menuOpt = 0;
	
	studentRead();
	while(menuOpt != 5) {
		menu();
		cin >> menuOpt;
		if(menuOpt == 1) {
			readList();
		}
		else if(menuOpt == 2) {
			printf("\nNew student ID:");
			cin >> id;
			student* idCheck = head;
			while(idCheck != NULL) {
				if(id == idCheck->getID()) {
					printf("\nID already in use.\n");
					idCheck = head;
					printf("\nNew student ID:");
					cin >> id;
				}
				idCheck = idCheck->getNext();
			}
			studentMake(id);
		}
		else if(menuOpt == 3) {
			printf("\nID of student to remove:");
			cin >> id;
			studentNodeDelete(id);
		}
		else if(menuOpt == 4) {
			printf("\nID of student to update:");
			cin >> id;
			update(id);
		}
	}
	
	student* ptr = head;
	int num = 0;
	
	ofstream file;
	file.open("C:\\Users\\shinf\\OneDrive\\Documents\\ECEGR2020\\Lab_4\\studentInfo.txt");
	while(ptr != NULL) {
		num++;
		ptr = ptr->getNext();
	}
	file << "Number of Students: " << num;
	file << "\n\n";
	ptr = head;
	while(ptr != NULL) {
		file << "\nStudent ID: " << ptr->getID();
		file << "\n";
		file << "\nStudent Name: " << ptr->getFirst();
		file << " " << ptr->getLast();
		file << "\n";
		file << "\nStudent GPA: " << ptr->getGPA();
		file << "\n\n";
		ptr = ptr->getNext();
	}
	file.close();
	
	return 0;
}

student* studentMake(int id) {
	string first;
	string last;
	float gpa;
	string temp;
	student* ptr = head;
	
	printf("\nEnter student's first name: ");
	cin >> first;
	printf("\nEnter student's last name: ");
	cin >> last;
	printf("\nEnter student's GPA: ");
	cin >> gpa;
	
	ptr = new student(id, first, last, gpa);
	studentNodeInsert(ptr);
	return ptr;
}

void studentNodeAdd(student* studentAdd) {
	student* ptr = head;
	
	if(head == NULL) {
		head = studentAdd;
		return;
	}
	while(ptr->getNext() != NULL) {
		ptr = ptr->getNext();
	}
	ptr->setNext(studentAdd);
	studentAdd->setNext(NULL);
}

void studentRead() {
	int id, num;
	string first;
	string last;
	float gpa;
	string temp;
	ifstream file;
	
	file.open("C:\\Users\\shinf\\OneDrive\\Documents\\ECEGR2020\\Lab_4\\studentInfo.txt");
	file >> temp;
	file >> temp;
	file >> temp;
	file >> num;
	
	for(int i=0; i<num; i++) {
		file >> temp;
		file >> temp;
		file >> id;
		
		file >> temp;
		file >> temp;
		file >> first;
		
		file >> last;
		
		file >> temp;
		file >> temp;
		file >> gpa;
		
		student* ptr = new student(id, first, last, gpa);
		studentNodeAdd(ptr);
	}
	file.close();
}

void studentNodeInsert(student* studentAdd) {
	student* ptr = head;
	
	if (ptr == NULL) {
		head = studentAdd;
	}
	else if (ptr->getNext() == NULL) {
		student* nextPtr = ptr->getNext();
		if(head->getGPA() > studentAdd->getGPA()) {
			nextPtr = studentAdd;
			head->setNext(nextPtr);
		}
		else {
			nextPtr = head;
			head = studentAdd;
			head->setNext(nextPtr);
		}
		nextPtr->setNext(NULL);
	}
	else {
		student* nextPtr = ptr->getNext();
		while(ptr->getNext() != NULL) {
			nextPtr = ptr->getNext();
			if((ptr->getGPA() > studentAdd->getGPA()) && (studentAdd->getGPA() >= nextPtr->getGPA())) {
				studentAdd->setNext(ptr->getNext());
				ptr->setNext(studentAdd);
				return;
			}
			else if(ptr->getGPA() <= studentAdd->getGPA()) {
				studentAdd->setNext(ptr);
				head = studentAdd;
				return;
			}
			ptr = ptr->getNext();
		}
		ptr->setNext(studentAdd);
		studentAdd->setNext(NULL);
	}
	return;
}

void studentNodeDelete(int id) {
	student* ptr = head;
	student* lastPtr = NULL;
	student* studentDelete = NULL;
	
	while(ptr != NULL) {
		if (id == ptr->getID()) {
			studentDelete = ptr;
		}
		ptr = ptr->getNext();
	}
	
	ptr = head;
	
	if(head == studentDelete) {
		head = head->getNext();
		free(studentDelete);
		return;
	}
	if(studentDelete != NULL) {
		while((ptr != NULL)&&(ptr != studentDelete)) {
			lastPtr = ptr;
			ptr = ptr->getNext();
		}
		if(ptr != NULL) {
			lastPtr->setNext(ptr->getNext());
		}
		free(studentDelete);
	}
}

void readList() {
	student* ptr = head;
	printf("\nCurrent List:\n");
	while(ptr != NULL) {
		cout << "\nStudent ID: " << ptr->getID() << "\n";
		cout << "Student Name: " << ptr->getFirst() << " " << ptr->getLast() << "\n";
		cout << "Student GPA: " << ptr->getGPA() << "\n";
		ptr = ptr->getNext();
	}
	printf("\n");
}

void menu() {
	printf("\nChoose one of the following:\n");
	printf("\n1) List all students");
	printf("\n2) Add student");
	printf("\n3) Remove student");
	printf("\n4) Update student");
	printf("\n5) Quit\n\n");
}

void update(int id) {
	student* ptr = head;
	
	while(ptr != NULL) {
		if(id == ptr->getID()){
			studentNodeDelete(id);
			studentMake(id);
		}
		ptr = ptr->getNext();
	}
}