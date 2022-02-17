#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int theArray[10] = {1,2,3,4,5,6,7,8,9,10};
char userString[100];

typedef struct student {
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
} student;

void reverseArray(void) {
	int newArray[10];
	int placehold = 0;
	
	for (int i = 9; i >= 0; i--) {
		newArray[i] = theArray[placehold];
		placehold++;
	}
	for (int i = 0; i < 10; i++) {
		theArray[i] = newArray[i];
		printf("%d ",theArray[i]);
	}
	printf("\n");
}

student* studentInfo(void) {
	student* ptr = malloc(sizeof(student));
	int id;
	char first[50];
	char last[50];
	float gpa;
	
	printf("\nEnter student's ID: \n");
	scanf(" %d", &id);
	ptr->ID = id;
	
	printf("\nEnter student's first name: \n");
	scanf(" %s", &first);
	strcpy(ptr->firstName, first);
	
	printf("\nEnter student's last name: \n");
	scanf(" %s", &last);
	strcpy(ptr->lastName, last);
	
	printf("\nEnter student's GPA: \n");
	scanf(" %f", &gpa);
	ptr->GPA = gpa;
	
	return ptr;
}

void gpaSorting(student** studentArray, int studentNum) {
	student* placehold;
	
	for (int i = 0; i < studentNum; i++) {
		for (int j = 1; j < studentNum; j++) {
			if (studentArray[j-1]->GPA < studentArray[j]->GPA) {
				placehold = studentArray[j];
				studentArray[j] = studentArray[j-1];
				studentArray[j-1] = placehold;
			}
		}
	}
}

void studentRead(student** studentArray) {
	int id, num;
	char first[50];
	char last[50];
	float gpa, avgGPA;
	FILE *f;
	student* ptr = malloc(sizeof(student));
	
	printf("\n\nInfo about students:\n");
	
	f = fopen("studentInfo.txt", "r");
	fscanf(f, "Number of Students: %d\n", &num);
	printf("Number of Students: %d\n", num);
	
	for (int i = 0; i < num; i++) {
		fscanf(f, "\nStudent ID: %d\n", &id);
		ptr->ID = id;
		printf("\nStudent ID: %d\n", id);
		
		fscanf(f, "Student Name: %s %s\n", &first, &last);
		strcpy(ptr->firstName, first);
		strcpy(ptr->lastName, last);
		printf("Student Name: %s %s\n", first, last);
		
		fscanf(f, "Student GPA: %f\n", &gpa);
		ptr->GPA = gpa;
		printf("Student GPA: %f\n", gpa);
		
		avgGPA += gpa;
		studentArray[i] = ptr;
	}
	avgGPA /= num;
	printf("\nAverage GPA: %f\n\n\n", avgGPA);
	fclose(f);
}

int vowelCount(char string[100]) {
	int vowelNum = 0;
	
	for (int i = 0; i < strlen(string); i++) {
		if ((string[i] == 'a') || (string[i] == 'e') || (string[i] == 'i') || (string[i] == 'o') || (string[i] == 'u') || (string[i] == 'A') || (string[i] == 'E') || (string[i] == 'I') || (string[i] == 'O') || (string[i] == 'U')) {
			vowelNum++;
		}
	}
	return vowelNum;
}

int consCount(char string[100]) {
	int consNum = 0;
	
	for (int i = 0; i < strlen(string); i++) {
		if ((string[i] != 'a') && (string[i] != 'e') && (string[i] != 'i') && (string[i] != 'o') && (string[i] != 'u') && (string[i] != 'A') && (string[i] != 'E') && (string[i] != 'I') && (string[i] != 'O') && (string[i] != 'U') && (string[i] != ' ') && (string[i] != '\n')) {
			consNum++;
		}
	}
	return consNum;
}

void uppering() {
	for (int i = 0; i < strlen(userString); i++) {
		userString[i] = toupper(userString[i]);
	}
}

void lowering() {
	for (int i = 0; i < strlen(userString); i++) {
		userString[i] = tolower(userString[i]);
	}
}

void reversing() {
	char wordHold[100];
	int lastSpace = 0;
	int placehold = 0;
	
	userString[strlen(userString)-1] = ' ';
	
	for (int i = 0; i < strlen(userString); i++) {
		if (userString[i] == ' ') {
			for (int j = i-1; j >= lastSpace; j--) {
				wordHold[placehold] = userString[j];
				placehold++;
			}
			lastSpace = i+1;
			placehold = lastSpace;
			wordHold[i] = ' ';
		}
	}
	for (int i = 0; i < strlen(userString); i++) {
		userString[i] = wordHold[i];
	}
}

int main() {
	int num;
	char menuOpt;
	FILE *f;
	
	reverseArray();
	printf("\n");

	printf("\nInput the number of students: \n");
	scanf(" %d", &num);
	student **studentArray = malloc(num * sizeof(student*));
	for (int i = 0; i < num; i++) {
		studentArray[i] = studentInfo();
	}
	gpaSorting(studentArray, num);
	f = fopen("studentInfo.txt", "w+");
	fprintf(f, "Number of Students: %d\n\n", num);
	for (int i = 0; i < num; i++) {
		fprintf(f, "\nStudent ID: %d\n", studentArray[i]->ID);
		fprintf(f, "\nStudent Name: %s %s\n", studentArray[i]->firstName, studentArray[i]->lastName);
		fprintf(f, "\nStudent GPA: %f\n\n", studentArray[i]->GPA);
	}
	free(studentArray);
	fclose(f);
	
	student **studentArrayAgain = malloc(num * sizeof(student*));
	studentRead(studentArrayAgain);
	free(studentArrayAgain);
	
	fflush(stdin);
	printf("Input a string: \n");
	fgets(userString, 100, stdin);
	printf("\n");
	
	printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nR) Reverse words in string\n\nM) Display this menu\nX) Exit the program\n\n");
	
	while ((menuOpt != 'x') && (menuOpt != 'X')) {
		fflush(stdin);
		menuOpt = getchar();
		
		if ((menuOpt == 'A') || (menuOpt == 'a')) {
			printf("There are %d vowels in the string.\n\n", vowelCount(userString));
		}
		else if ((menuOpt == 'B') || (menuOpt == 'b')) {
			printf("There are %d consonants in the string.\n\n", consCount(userString));
		}
		else if ((menuOpt == 'C') || (menuOpt == 'c')) {
			uppering();
		}
		else if ((menuOpt == 'D') || (menuOpt == 'd')) {
			lowering();
		}
		else if ((menuOpt == 'E') || (menuOpt == 'e')) {
			printf("%s\n", userString);
		}
		else if ((menuOpt == 'F') || (menuOpt == 'f')) {
			fflush(stdin);
			printf("Input a string: \n");
			fgets(userString, 100, stdin);
			printf("\n");
		}
		else if ((menuOpt == 'R') || (menuOpt == 'r')) {
			reversing();
		}
		else if ((menuOpt == 'M') || (menuOpt == 'm')) {
			printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nR) Reverse words in string\n\nM) Display this menu\nX) Exit the program\n\n");
		}
	}
}
