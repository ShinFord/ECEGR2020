#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

enum Department{humanities1, humanities2, humanities3, stem1, stem2, stem3, other};

class student {
private:
	int ID;
	char *firstName;
	char *lastName;
	float GPA;
	
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
		firstName = (char*) malloc(sizeof(strlen(first)+1));
		strcpy(firstName, first);
	}
	void *setLast(char *last) {
		lastName = (char*) malloc(sizeof(strlen(last)+1));
		strcpy(lastName, last);
	}
};

class professor {
private:
	int ID;
	char *firstName;
	char *lastName;
	float salary;
	bool tenured;
	Department department;
	
public:
	professor();
	professor(int ID, char *firstName, char *lastName, float salary, bool tenured, Department department);
	professor(professor &init);
	~professor();
	
	int getID() {
		return ID;
	}
	char *getFirst() {
		return firstName;
	}
	char *getLast() {
		return lastName;
	}
	float getSalary() {
		return salary;
	}
	bool getTenure() {
		return tenured;
	}
	Department getDepart() {
		return department;
	}
	
	void setID(int id) {
		ID = id;
	}
	void *setFirst(char *first) {
		firstName = (char*) malloc(sizeof(strlen(first) + 1));
		strcpy(firstName, first);
	}
	void *setLast(char *last) {
		lastName = (char*) malloc(sizeof(strlen(last) + 1));
		strcpy(lastName, last);
	}
	void setSalary(float sal) {
		salary = sal;
	}
	void setTenure(bool tenure) {
		tenured = tenure;
	}
	void setDepart(Department dept) {
		department = dept;
	}
};

class employee {
private:
	int ID;
	char *firstName;
	char *lastName;
	float salary;
	
public:
	employee();
	employee(int ID, char *firstName, char *lastName, float salary);
	employee(employee &init);
	~employee();
	
	int getID() {
		return ID;
	}
	char *getFirst() {
		return firstName;
	}
	char *getLast() {
		return lastName;
	}
	float getSalary() {
		return salary;
	}
	
	void setID(int id) {
		ID = id;
	}
	void *setFirst(char *first) {
		firstName = (char*) malloc(sizeof(strlen(first) + 1));
		strcpy(firstName, first);
	}
	void *setLast(char *last) {
		lastName = (char*) malloc(sizeof(strlen(last) + 1));
		strcpy(lastName, last);
	}
	void setSalary(float sal) {
		salary = sal;
	}
};

student::student() {
	ID = 0;
	firstName = NULL;
	lastName = NULL;
	GPA = 0.0;
}

professor::professor() {
	ID = 0;
	firstName = NULL;
	lastName = NULL;
	salary = 0.0;
	tenured = false;
	department = other;
}

employee::employee() {
	ID = 0;
	firstName = NULL;
	lastName = NULL;
	salary = 0.0;
}


student::student(int id, char* first, char* last, float gpa) {
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first)+1));
	strcpy(this->firstName, first);
	this->lastName = (char*) malloc(sizeof(strlen(last)+1));
	strcpy(this->lastName, last);
	this->GPA = gpa;
}

professor::professor(int id, char* first, char* last, float sal, bool tenure, Department dept) {
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first)+1));
	strcpy(this->firstName, first);
	this->lastName = (char*) malloc(sizeof(strlen(last)+1));
	strcpy(this->lastName, last);
	this->salary = sal;
	this->tenured = tenure;
	this->department = dept;
}

employee::employee(int id, char* first, char* last, float sal) {
	this->ID = id;
	this->firstName = (char*) malloc(sizeof(strlen(first)+1));
	strcpy(this->firstName, first);
	this->lastName = (char*) malloc(sizeof(strlen(last)+1));
	strcpy(this->lastName, last);
	this->salary = sal;
}


student::student(student &init) {
	this->ID = init.ID;
	this->firstName = (char*)malloc(sizeof(strlen(init.firstName)+1));
	strcpy(this->firstName, init.firstName);
	this->lastName = (char*)malloc(sizeof(strlen(init.lastName)+1));
	strcpy(this->lastName, init.lastName);
	this->GPA = init.GPA;
}

professor::professor(professor &init) {
	this->ID = init.ID;
	this->firstName = (char*)malloc(sizeof(strlen(init.firstName)+1));
	strcpy(this->firstName, init.firstName);
	this->lastName = (char*)malloc(sizeof(strlen(init.lastName)+1));
	strcpy(this->lastName, init.lastName);
	this->salary = init.salary;
	this->tenured = init.tenured;
	this->department = init.department;
}

employee::employee(employee &init) {
	this->ID = init.ID;
	this->firstName = (char*)malloc(sizeof(strlen(init.firstName)+1));
	strcpy(this->firstName, init.firstName);
	this->lastName = (char*)malloc(sizeof(strlen(init.lastName)+1));
	strcpy(this->lastName, init.lastName);
	this->salary = init.salary;
}

student::~student() {
	free(firstName);
	free(lastName);
	printf("Destruction test\n");
}

professor::~professor() {
	free(firstName);
	free(lastName);
	printf("Destruction test\n");
}

employee::~employee() {
	free(firstName);
	free(lastName);
	printf("Destruction test\n");
}

int main() {
	student s1;
	student s2(123,(char*)"John",(char*)"Doe", 2.0);
	student s3(s2);
	
	printf("Student 1 info: \n");
	printf("ID = %d, Name = %s %s, GPA = %f\n\n", s1.getID(), s1.getFirst(), s1.getLast(), s1.getGPA());
	
	printf("Student 2 info: \n");
	printf("ID = %d, Name = %s %s, GPA = %f\n\n", s2.getID(), s2.getFirst(), s2.getLast(), s2.getGPA());
	
	printf("Student 3 info: \n");
	printf("ID = %d, Name = %s %s, GPA = %f\n\n", s3.getID(), s3.getFirst(), s3.getLast(), s3.getGPA());
	
	s3.setID(321);
	s3.setFirst((char*)"Jane");
	s3.setLast((char*)"Deer");
	s3.setGPA(3.0);
	printf("Student 3 new info: \n");
	printf("ID = %d, Name = %s %s, GPA = %f\n\n", s3.getID(), s3.getFirst(), s3.getLast(), s3.getGPA());
	
	return 0;
}