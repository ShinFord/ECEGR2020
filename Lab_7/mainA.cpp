#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <cstring>
using namespace std;

enum Department{humanities1, humanities2, humanities3, stem1, stem2, stem3, other};

class members {
private:
	int ID;
	string firstName;
	string lastName;
	members* next;
	
public:
	members();
	members(int ID, string firstName, string lastName);
	members(members &init);
	virtual ~members();
	
	int getID() {
		return ID;
	}
	string getFirst() {
		return firstName;
	}
	string getLast() {
		return lastName;
	}
	members* getNext() {
		return next;
	}
	
	void setID(int id) {
		ID = id;
	}
	void setFirst(string first) {
		firstName = first;
	}
	void setLast(string last) {
		lastName = last;
	}
	void setNext(members* Next) {
		next = Next;
	}
};

class student: public members {
private:
	float GPA;
	
public:
	student();
	student(int ID, string firstName, string lastName, float GPA);
	student(student &init);
	~student();
	
	float getGPA() {
		return GPA;
	}
	void setGPA(float gpa) {
		GPA = gpa;
	}
};

class employee: public members {
private:
	float salary;
	
public:
	employee();
	employee(int ID, string firstName, string lastName, float salary);
	employee(employee &init);
	~employee();
	
	float getSalary() {
		return salary;
	}
	void setSalary(float sal) {
		salary = sal;
	}
};

class professor: public employee {
private:
	bool tenured;
	Department department;
	
public:
	professor();
	professor(int ID, string firstName, string lastName, float salary, bool tenured, Department department);
	professor(professor &init);
	~professor();
	
	bool getTenure() {
		return tenured;
	}
	Department getDepart() {
		return department;
	}
	void setTenure(bool tenure) {
		tenured = tenure;
	}
	void setDepart(Department dept) {
		department = dept;
	}
};

members* head = NULL;


members::members() {
	this->ID = 0;
	this->firstName = "";
	this->lastName = "";
	this->next = NULL;
}

student::student() {
	this->setID(0);
	this->setFirst("");
	this->setLast("");
	this->GPA = 0;
	this->setNext(NULL);
}

employee::employee() {
	this->setID(0);
	this->setFirst("");
	this->setLast("");
	this->salary = 0;
	this->setNext(NULL);
}

professor::professor() {
	this->setID(0);
	this->setFirst("");
	this->setLast("");
	this->setSalary(0);
	this->tenured = false;
	this->department = other;
	this->setNext(NULL);
}


members::members(int id, string first, string last) {
	this->ID = id;
	this->firstName = first;
	this->lastName = last;
	this->next = NULL;
}

student::student(int id, string first, string last, float gpa) {
	setID(id);
	setFirst(first);
	setLast(last);
	this->GPA = gpa;
	setNext(NULL);
}

employee::employee(int id, string first, string last, float sal) {
	setID(id);
	setFirst(first);
	setLast(last);
	this->salary = sal;
	setNext(NULL);
}

professor::professor(int id, string first, string last, float sal, bool tenure, Department dept) {
	setID(id);
	setFirst(first);
	setLast(last);
	setSalary(sal);
	this->tenured = tenure;
	this->department = dept;
	setNext(NULL);
}


members::members(members &init) {
	this->ID = init.ID;
	this->firstName = init.firstName;
	this->lastName = init.lastName;
	this->next = init.next;
}

student::student(student &init) {
	setID(init.getID());
	setFirst(init.getFirst());
	setLast(init.getLast());
	setGPA(init.getGPA());
	setNext(init.getNext());
}

employee::employee(employee &init) {
	setID(init.getID());
	setFirst(init.getFirst());
	setLast(init.getLast());
	setSalary(init.salary);
	setNext(init.getNext());
}

professor::professor(professor &init) {
	setID(init.getID());
	setFirst(init.getFirst());
	setLast(init.getLast());
	setSalary(init.getSalary());
	setTenure(init.tenured);
	setDepart(init.department);
	setNext(init.getNext());
}


members::~members() {
}

student::~student() {
}

employee::~employee() {
}

professor::~professor() {
}

void fileRead();

int main() {
	int menuOpt
	
	fileRead();
	
}

void fileRead() {
	int id, num;
	string first;
	string last;
	float gpa;
	float salary;
	bool tenure;
	Department department;
	string temp;
	ifstream file;
	
	file.open("universityInfo.txt");
	file >> temp;
	file >> temp;
	file >> temp;
	file >> num;
	
	for(int i=0; i<num; i++) {
		file >> temp;
		
		if(temp == "Student") {
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
			
			members* ptr = new student(id, first, last, gpa);
			studentNodeAdd(ptr);
		}
		else if(temp == "Professor") {
			
		}
	}
	file.close();
}