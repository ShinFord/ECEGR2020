#include<stdio.h>
#include<unistd.h>

 void SizeOfVariables(void) {
	char c;  
	short s;  
	int i;  
	unsigned int ui;  
	unsigned long int ul; 
	float f;
	double d;  
	long double ld;
	void *ptr;  
	
	printf("Size of \"c\" is: %llu\n", sizeof(c));
	printf("Size of \"s\" is: %llu\n", sizeof(s));
	printf("Size of \"i\" is: %llu\n", sizeof(i));
	printf("Size of \"ui\" is: %llu\n", sizeof(ui));
	printf("Size of \"ul\" is: %llu\n", sizeof(ul));
	printf("Size of \"f\" is: %llu\n", sizeof(f));
	printf("Size of \"d\" is: %llu\n", sizeof(d));
	printf("Size of \"ld\" is: %llu\n", sizeof(ld));
	printf("Size of \"*ptr\" is: %llu\n\n", sizeof(*ptr));
 }
 
 int isLeapYear(int aYear) {
	 if (aYear < 1752) {
		 return 0;
	 }
	 else if (aYear % 400 == 0) {
		 return 1;
	 }
	 else if (aYear % 100 == 0) {
		 return 0;
	 }
	 else if (aYear % 4 == 0) {
		 return 1;
	 }
	 else {
		 return 0;
	 }
 }
 
 int isVowel(char aLetter) {
	 if (aLetter == 'a' || aLetter == 'e' || aLetter == 'i' || aLetter == 'o' || aLetter == 'u' || aLetter == 'A' || aLetter == 'E' || aLetter == 'I' || aLetter == 'O' || aLetter == 'U') {
		 return 1;
	 }
	 else if ((aLetter > 'a' && aLetter <= 'z') || (aLetter > 'A' && aLetter <= 'Z')) {
		 return 0;
	 }
	 else {
		 return 2;
	 }
 }

void reverseNumber(long aNumber) {
	char numString[10] = "";
	char reverseString[10] = "";
	int placehold = 0;
	char placeholdString[10] = "";
	int negCheck = 0;
	
	sprintf(numString, "%ld", aNumber);
	if (numString[0]==45) {
		negCheck = 1;
		for (int i = 1; i < strlen(numString); i++) {
			placeholdString[i-1] = numString[i];
		}
		numString[strlen(numString)-1] = 0;
		for (int i = 0; i < strlen(placeholdString); i++) {
			numString[i] = placeholdString[i];
		}
	}
	for (int i = strlen(numString) - 1; i>=0; i--) {
		reverseString[placehold] = numString[i];
		placehold++;
	}
	if (negCheck == 1) {
		for (int i = 0; i < strlen(reverseString); i++) {
			placeholdString[i] = reverseString[i];
		}
		reverseString[0] = 45;
		for (int i = 0; i < strlen(placeholdString); i++) {
			reverseString[i+1] = placeholdString[i];
		}
	}
	printf("When %ld is reversed, it becomes %s.\n", aNumber, reverseString);
}

int main() {
    int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50
	int yearTest;
	int loopHolder = 0;
	int loop2 = 0;
	char charTest;
	long numReverse;
/*
    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);

    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);

    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();

    printf("\n\nEnter your complete name:\n\n\n");

    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
	
*/
/*
	//FUNCTION FOR PART A
    SizeOfVariables();	
*/
/*
	while (loopHolder == 0) {
		printf("\nInput a year: \n");
		scanf(" %i",&yearTest);
		if (isLeapYear(yearTest) == 0) {
			printf("\n%i is not a leap year.\n", yearTest);
		}
		else {
			printf("\n%i is a leap year.\n", yearTest);
		}
		loop2 = 0;
		while (loop2 == 0) {
			printf("\nContinue testing years? y/n: \n");
			scanf(" %c",&character);
			if (character == 'n' || character == 'N') {
				loopHolder = 1;
				loop2 = 1;
			}
			else if (character == 'y' || character == 'Y') {
				loopHolder = 0;
				loop2 = 1;
			}
		}
	}
	loopHolder = 0;
	loop2 = 0;
*/
/*
	while (loopHolder == 0) {
		printf("\nInput a character: \n");
		scanf(" %c",&charTest);
		if (isVowel(charTest) == 0) {
			printf("\n%c is not a vowel.\n", charTest);
		}
		else if (isVowel(charTest) == 1) {
			printf("\n%c is a vowel.\n", charTest);
		}
		else {
			printf("Error: not an ASCII letter.\n");
		}
		loop2 = 0;
		while (loop2 == 0) {
			printf("\nContinue testing chars? y/n: \n");
			scanf(" %c",&character);
			if (character == 'n' || character == 'N') {
				loopHolder = 1;
				loop2 = 1;
			}
			else if (character == 'y' || character == 'Y') {
				loopHolder = 0;
				loop2 = 1;
			}
		}
	}
	loopHolder = 0;
	loop2 = 0;
*/ 
	while (loopHolder == 0) {
		printf("\nEnter a multi-digit number:\n");
		scanf(" %ld", &numReverse);
		reverseNumber(numReverse);
		loop2 = 0;
		while (loop2 == 0) {
			printf("\nContinue testing numbers? y/n: \n");
			scanf(" %c",&character);
			if (character == 'n' || character == 'N') {
				loopHolder = 1;
				loop2 = 1;
			}
			else if (character == 'y' || character == 'Y') {
				loopHolder = 0;
				loop2 = 1;
			}
		}
	}
	loopHolder = 0;
	loop2 = 0;

    return 0;
}