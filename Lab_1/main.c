#include<stdio.h>
#include<unistd.h>

void SizeOfVariables(void) { //Does exactly what you think it does... 
	char c;  //Initialize all the variables
	short s;  
	int i;  
	unsigned int ui;  
	unsigned long int ul; 
	float f;
	double d;  
	long double ld;
	void *ptr;  
	
	printf("Size of \"c\" is: %llu\n", sizeof(c)); //Prints size of each variable
	printf("Size of \"s\" is: %llu\n", sizeof(s));
	printf("Size of \"i\" is: %llu\n", sizeof(i));
	printf("Size of \"ui\" is: %llu\n", sizeof(ui));
	printf("Size of \"ul\" is: %llu\n", sizeof(ul));
	printf("Size of \"f\" is: %llu\n", sizeof(f));
	printf("Size of \"d\" is: %llu\n", sizeof(d));
	printf("Size of \"ld\" is: %llu\n", sizeof(ld));
	printf("Size of \"*ptr\" is: %llu\n\n", sizeof(*ptr));
}
 
int isLeapYear(int aYear) { //These names are pretty explainatory
	if (aYear < 1752) { //Yeah each if just goes down the checklist to see if the year is a leap year
		return 0;
	}
	else if (aYear % 400 == 0) { //Something funny happens if you input a char or string instead of a number
		return 1;
	}
	else if (aYear % 100 == 0) { //Checking if the input isn't a number is outside the scope so I didn't bother
		return 0;
	}
	else if (aYear % 4 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
 
int isVowel(char aLetter) { //Once again, good function name
	if (aLetter == 'a' || aLetter == 'e' || aLetter == 'i' || aLetter == 'o' || aLetter == 'u' || aLetter == 'A' || aLetter == 'E' || aLetter == 'I' || aLetter == 'O' || aLetter == 'U') {
		return 1; //Checks if its a vowel (making this list was annoying)
	}
	else if ((aLetter > 'a' && aLetter <= 'z') || (aLetter > 'A' && aLetter <= 'Z')) { //Checks if its a letter (has to be non-vowel)
		return 0; //I originally did this in ASCII decimal form, but the vowel check was annoying so I stuck with chars
	}
	else { //If not a char, do this
		return 2; //I know its not conventional/needed to return 2, but it made my life easier
	}
}

void reverseNumber(long aNumber) { //Oh boy was this one annoying
	char numString[10] = ""; //Making placeholder variables is my guilty pleasure
	char reverseString[10] = ""; //Warning, dear reader: trying to make sense of this stuff might make you angry
	int placehold = 0;
	char placeholdString[10] = "";
	int negCheck = 0;
	
	sprintf(numString, "%ld", aNumber); //So first I make the inputted number into a string...
	if (numString[0]==45) { //...then I check if its a negative number... (btw why does it not work if I test for "-"?)
		negCheck = 1; //(Keep an eye out for this later, it's used to mark a number as negative)
		for (int i = 1; i < strlen(numString); i++) {
			placeholdString[i-1] = numString[i];
		}
		numString[strlen(numString)-1] = 0; //(This is to make sure the inputted number gets processed correctly)
		for (int i = 0; i < strlen(placeholdString); i++) { //...if it's negative I use a placeholder to remove the "-" from the number...
			numString[i] = placeholdString[i];
		}
	}
	for (int i = strlen(numString) - 1; i>=0; i--) { //...then I reverse the inputted number...
		reverseString[placehold] = numString[i];
		placehold++; //(Don't ask.)
	}
	if (negCheck == 1) { //...and finally if the number was negative I put the "-" back in the front of the number!
		for (int i = 0; i < strlen(reverseString); i++) {
			placeholdString[i] = reverseString[i];
		}
		reverseString[0] = 45; 
		for (int i = 0; i < strlen(placeholdString); i++) { //(The return of the placeholder)
			reverseString[i+1] = placeholdString[i];
		}
	}
	printf("When %ld is reversed, it becomes %s.\n", aNumber, reverseString); //You know what a print statement does.
}

int retest(void) { //My personal creation :)
	int loop = 0; //I love binary variables that hold together the logic of my code, they're like digital duct tape and WD-40!
	char character; //Yeah I'm reusing the variable from main(), what're you gonna do about it?
	while (loop == 0) { //The loop is here to make sure that if the user inputs something other than y/n, they're trapped until they cooperate
		printf("\nContinue testing? y/n: \n");
		scanf(" %c",&character); //So it turns out that that space in front of %c is pretty important
		if (character == 'n' || character == 'N') { //Dunno how long I spent trying to figure out why things were printing twice
			loop = 1;
			return 1; //returns are pretty useful, aren't they
		}
		else if (character == 'y' || character == 'Y') {
			loop = 1; //Now that I'm thinking about it, these changes to loop aren't necessary, are they?
			return 0; //Gonna keep them in though, not gonna mess with something that works
		}
	}
}

int main() { //Commenting is tiring
    int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50
	int yearTest;
	int loopHolder = 0;
	char charTest;
	long numReverse;

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
	


	//FUNCTION CALL FOR PART A
    SizeOfVariables(); //Wow, now that's what I call a function call

	//FUNCTION CALL FOR PART B
	while (loopHolder == 0) { //The while loop and "loopholder" stuff makes it easier to test each function multiple times
		printf("\nInput a year: \n");
		scanf(" %i",&yearTest);
		if (isLeapYear(yearTest) == 0) { //I decided to put this printing stuff in main() since I have to return info from the function anyways
			printf("\n%i is not a leap year.\n", yearTest);
		}
		else { //pretty conventional if-else and printing
			printf("\n%i is a leap year.\n", yearTest);
		}
		loopHolder = retest(); //Originally had this logic in each while loop in main(), but it looked bad so I made a function :)
	}
	loopHolder = 0; //Int reset for future use, not gonna comment on it again later

	//FUNCTION CALL FOR PART C
	while (loopHolder == 0) { //basically same ideas as in part B
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
		loopHolder = retest(); //So how're you doing? Hope my code isn't giving you a headache...
	}
	loopHolder = 0;

	//FUNCTION CALL FOR PART D
	while (loopHolder == 0) { //Did the printing logic in the function this time, fancy innit? 
		printf("\nEnter a multi-digit number (up to 10 digits):\n");
		scanf(" %ld", &numReverse);
		reverseNumber(numReverse);
		loopHolder = retest();
	}
	loopHolder = 0;
	
	printf("\n"); //Looks bad without this space
    return 0;
} //Aaaaaaaaand we're done! Good job making it this far!