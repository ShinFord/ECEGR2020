#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
    int ID;
    char firstName[50];
    char lastName[50];
    float GPA;
	struct student* next;
} Student;

FILE *f;
Student* head = NULL;

Student* studentNodeMake(int id, char first[50], char last[50], float gpa);
Student* studentMake(int id);
void studentNodeAdd(Student* studentAdd);
void studentRead(void);
void studentNodeInsert(Student* studentAdd);
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
		scanf(" %d", &menuOpt);
		if(menuOpt == 1) {
			readList();
		}
		else if(menuOpt == 2) {
			printf("\nNew student ID:");
			scanf(" %d", &id);
			Student* idCheck = head;
			while(idCheck != NULL) {
				if(id == idCheck->ID) {
					printf("\nID already in use.\n");
					idCheck = head;
					printf("\nNew student ID:");
					scanf(" %d", &id);
				}
				idCheck = idCheck->next;
			}
			studentMake(id);
		}
		else if(menuOpt == 3) {
			printf("\nID of student to remove:");
			scanf(" %d", &id);
			studentNodeDelete(id);
		}
		else if(menuOpt == 4) {
			printf("\nID of student to update:");
			scanf(" %d", &id);
			update(id);
		}
	}
	
	Student* ptr = head;
	int num = 0;
	
	f = fopen("C:\\Users\\shinf\\OneDrive\\Documents\\ECEGR2020\\Lab_4\\studentInfo.txt", "w+");
	while(ptr != NULL) {
		num++;
		ptr = ptr->next;
	}
	fprintf(f, "Number of Students: %d\n\n", num);
	ptr = head;
	while(ptr != NULL) {
		fprintf(f, "\nStudent ID: %d\n", ptr->ID);
		fprintf(f, "\nStudent Name: %s %s\n", ptr->firstName, ptr->lastName);
		fprintf(f, "\nStudent GPA: %f\n\n", ptr->GPA);
		ptr = ptr->next;
	}
	fclose(f);
	
	Student* nextPtr = head->next;
	ptr = head;
	while(ptr != NULL) {
		studentNodeDelete(ptr->ID);
		ptr = nextPtr;
		nextPtr = nextPtr->next;
	}
}


Student* studentNodeMake(int id, char first[50], char last[50], float gpa) {
	Student* ptr = malloc(sizeof(Student));
	
	if (ptr != NULL) {
		ptr->ID = id;
		strcpy(ptr->firstName, first);
		strcpy(ptr->lastName, last);
		ptr->GPA = gpa;
		ptr->next = NULL;
	}
	
	return ptr;
}

Student* studentMake(int id) {
	char first[50], last[50];
	float gpa;
	Student* ptr = NULL;
	
	printf("\nEnter student's first name: ");
	scanf(" %49s", first);
	printf("\nEnter student's last name: ");
	scanf(" %49s", last);
	printf("\nEnter student's GPA: ");
	scanf(" %f", &gpa);
	
	ptr = studentNodeMake(id, first, last, gpa);
	studentNodeInsert(ptr);
	return ptr;
}

void studentNodeAdd(Student* studentAdd) {
	Student* ptr = head;
	
	if(head == NULL) {
		head = studentAdd;
		return;
	}
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = studentAdd;
	studentAdd->next = NULL;
}

void studentRead() {
	int id, num;
	char first[50], last[50];
	float gpa;
	
	f = fopen("C:\\Users\\shinf\\OneDrive\\Documents\\ECEGR2020\\Lab_4\\studentInfo.txt", "r+");
	fscanf(f, "Number of Students: %d\n\n", &num);
	printf("%d\n", num);
	
	for(int i=0; i<num; i++) {
		fscanf(f, "\nStudent ID: %d\n", &id);
		fscanf(f, "\nStudent Name: %s %s\n", first, last);
		fscanf(f, "\nStudent GPA: %f\n\n", &gpa);
		printf("%d, %s %s, %f\n", id, first, last, gpa);
		Student* ptr = studentNodeMake(id, first, last, gpa);
		studentNodeAdd(ptr);
	}
	fclose(f);
}

void studentNodeInsert(Student* studentAdd) {
	Student* ptr = head;
	
	if (ptr == NULL) {
		head = studentAdd;
	}
	else if (ptr->next == NULL) {
		Student* nextPtr = ptr->next;
		if(head->GPA > studentAdd->GPA) {
			nextPtr = studentAdd;
			head->next = nextPtr;
		}
		else {
			nextPtr = head;
			head = studentAdd;
			head->next = nextPtr;
		}
		nextPtr->next = NULL;
	}
	else {
		Student* nextPtr = ptr->next;
		while(ptr->next != NULL) {
			nextPtr = ptr->next;
			if((ptr->GPA > studentAdd-> GPA) && (studentAdd->GPA >= nextPtr->GPA)) {
				studentAdd->next = ptr->next;
				ptr->next = studentAdd;
				return;
			}
			else if(ptr->GPA <= studentAdd->GPA) {
				studentAdd->next = ptr;
				head = studentAdd;
				return;
			}
			ptr = ptr->next;
		}
		ptr->next = studentAdd;
		studentAdd->next = NULL;
	}
	return;
}

void studentNodeDelete(int id) {
	Student* ptr = head;
	Student* lastPtr = NULL;
	Student* studentDelete = NULL;
	
	while(ptr != NULL) {
		if (id == ptr->ID) {
			studentDelete = ptr;
		}
		ptr = ptr->next;
	}
	
	ptr = head;
	
	if(head == studentDelete) {
		head = head->next;
		free(studentDelete);
		return;
	}
	if(studentDelete != NULL) {
		while((ptr != NULL)&&(ptr != studentDelete)) {
			lastPtr = ptr;
			ptr = ptr->next;
		}
		if(ptr != NULL) {
			lastPtr->next = ptr->next;
		}
		free(studentDelete);
	}
}

void readList() {
	Student* ptr = head;
	printf("\nCurrent List:\n");
	while(ptr != NULL) {
		printf("\nStudent ID: %d\n",ptr->ID);
		printf("Student Name: %s %s\n", ptr->firstName, ptr->lastName);
		printf("Student GPA: %f\n", ptr->GPA);
		ptr = ptr->next;
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
	Student* ptr = head;
	
	while(ptr != NULL) {
		if(id == ptr->ID){
			studentNodeDelete(id);
			studentMake(id);
		}
		ptr = ptr->next;
	}
}