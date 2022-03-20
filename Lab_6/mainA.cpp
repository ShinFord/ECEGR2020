#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class student {
private:
	int ID;
	char *firstName;
	char *lastName;
	float GPA;
	student* next;
	
public:
	student();
	student(int ID, char *firstName, char *lastName, float GPA);
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
	
	char *getFirst() {
		return firstName;
	}
	char *getLast() {
		return lastName;
	}
	void *setFirst(char *first) {
		firstName = (char*) malloc(strlen(first)+1);
		strcpy(firstName, first);
	}
	void *setLast(char *last) {
		lastName = (char*) malloc(strlen(last)+1);
		strcpy(lastName, last);
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
	this->firstName = NULL;
	this->lastName = NULL;
	this->GPA = 0.0;
	this->next = NULL;
}

student::student(int id, char* first, char* last, float gpa) {
	this->ID = id;
	this->firstName = (char*) malloc(strlen(first)+1);
	strcpy(this->firstName, first);
	this->lastName = (char*) malloc(strlen(last)+1);
	strcpy(this->lastName, last);
	this->GPA = gpa;
	this->next = NULL;
}

student::student(student &init) {
	this->ID = init.ID;
	this->firstName = (char*)malloc(strlen(init.firstName)+1);
	strcpy(this->firstName, init.firstName);
	this->lastName = (char*)malloc(strlen(init.lastName)+1);
	strcpy(this->lastName, init.lastName);
	this->GPA = init.GPA;
	next = init.next;
}

student::~student() {
	if (firstName != NULL) {
		free(firstName);
	}
	if (lastName != NULL) {
		free(lastName);
	}
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
	char* first;
	char* last;
	float gpa;
	string temp;
	student* ptr = head;
	
	printf("\nEnter student's first name: ");
	cin >> temp;
	first = (char*) malloc(sizeof(strlen((temp.c_str())+1)));
	strcpy(first, temp.c_str());
	printf("\nEnter student's last name: ");
	cin >> temp;
	last = (char*) malloc(sizeof(strlen((temp.c_str())+1)));
	strcpy(last, temp.c_str());
	printf("\nEnter student's GPA: ");
	cin >> gpa;
	
	ptr = new student(id, first, last, gpa);
	studentNodeInsert(ptr);
	free(first);
	free(last);
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
	char* first;
	char* last;
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
		file >> temp;
		first = (char*) malloc(strlen((temp.c_str())+1));
		strcpy(first, temp.c_str());
		
		file >> temp;
		last = (char*) malloc(strlen((temp.c_str())+1));
		strcpy(last, temp.c_str());
		
		file >> temp;
		file >> temp;
		file >> gpa;
		
		student* ptr = new student(id, first, last, gpa);
		studentNodeAdd(ptr);
		free(first);
		free(last);
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
		printf("\nStudent ID: %d\n",ptr->getID());
		printf("Student Name: %s %s\n", ptr->getFirst(), ptr->getLast());
		printf("Student GPA: %f\n", ptr->getGPA());
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