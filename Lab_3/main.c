#include <stdio.h>
#include <unistd.h>

long factorial(long num) {
	long factNum = 1;
	
	for (int i = num; i > 1; i--) {
		factNum = factNum * i;
	}
	return factNum;
}

int isPalindrome(long value) {
	char numString[10] = "";
	int placeholder;
	int palCheck = 1;
	
	sprintf(numString, "%ld", value);
	placeholder = strlen(numString) - 1;
	if (strlen(numString)%2 != 0) {
		for (int i = 0; i != placeholder; i++) {
			if (numString[i] != numString[placeholder]) {
				palCheck = 0;
			}
			placeholder--;
		}
	}
	else {
		for (int i = 0; i < strlen(numString)/2; i++) {
			if (numString[i] != numString[placeholder]) {
				palCheck = 0;
			}
			placeholder--;
		}
	}
	return palCheck;
}

int highestBitSet(int value) {
	int binarySet[10];
	int holder = value;
	char binaryHold[10] = "0";
	int i;
	int placeholder = 0;
	
	for (i = 0; holder > 0; i++) {
		binarySet[i] = holder % 2;
		holder = holder/2;
	}
	for (i = i - 1; i >= 0; i--) {
		binaryHold[placeholder] = binarySet[i] + 48;
		placeholder++;
	}
	printf("Value = %d, Binary = %s, Highest bit set = %d.\n",value, binaryHold, strlen(binaryHold) - 1);
}

void reverseIt(void) {
	float f1,f2,f3,f4,f5;
	FILE *fp;
	
	fp = fopen("reverseIt.txt", "w+");
	printf("\nEnter 5 floating point numbers: \n");
	scanf(" %f%f%f%f%f", &f1,&f2,&f3,&f4,&f5);
	fprintf(fp,"Original order: %f %f %f %f %f\n",f1,f2,f3,f4,f5);
	fprintf(fp,"Reverse order: %f %f %f %f %f\n",f5,f4,f3,f2,f1);
	printf("\nReversed order: %f %f %f %f %f\n",f5,f4,f3,f2,f1);
	fclose(fp);
}

void reverseItAgain(void) {
	FILE *fp;
	char buff[255];
	
	fp = fopen("reverseIt.txt", "r");
	printf("\n\nValues from file:\n\n");
	fgets(buff, 255, fp);
	printf("%s\n", buff);
	fgets(buff, 255, fp);
	printf("%s\n", buff);
	fclose(fp);
}

void pyramid(int lines) {
	int starNum[100];
	int placehold = 1;
	FILE *fp;
	
	fp = fopen("pyramid.txt", "w");
	printf("\n");
	for (int i = 0; i < lines; i++) {
		starNum[i] = placehold;
		placehold = placehold + 2;
	}
	for (int i = 0; i < lines; i++) {
		for (int w = placehold/2; w > 0; w--) {
			printf(" ");
			fprintf(fp, " ");
		}
		for (int w = starNum[i]; w > 0; w--) {
			printf("*");
			fprintf(fp, "*");
		}
		placehold = placehold - 2;
		printf("\n");
		fprintf(fp, "\n");
	}
	fclose(fp);
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

int main() {
	long longNum;
	int num;
	int loopHolder = 0;
	
	while (loopHolder == 0) {
		printf("\nInput a number smaller than 13: \n");
		scanf(" %ld", &longNum);
		if (longNum >= 13) {
			printf("Inputted value is too large.\n");
		}
		else {
			printf("The factorial of %ld is %ld.\n", longNum, factorial(longNum));
		}
		loopHolder = retest();
	}
	loopHolder = 0;
	
	while (loopHolder == 0) {
		printf("\nInput a number with 9 or fewer digits: \n");
		scanf(" %ld", &longNum);
		if (isPalindrome(longNum) == 0) {
			printf("\n%ld is not a palindrome.\n", longNum);
		}
		else {
			printf("\n%ld is a palindrome.\n", longNum);
		}
		loopHolder = retest();
	}
	loopHolder = 0;
	
	while (loopHolder == 0) {
		printf("\nInput a number smaller than 2048: \n");
		scanf(" %d", &num);
		if (num >= 2048) {
			printf("Inputted value is too large.\n");
		}
		else {
			highestBitSet(num);
		}
		loopHolder = retest();
	}
	loopHolder = 0;
	
	while (loopHolder == 0) {
		reverseIt();
		reverseItAgain();
		loopHolder = retest();
	}
	loopHolder = 0;
	
	while (loopHolder == 0) {
		printf("\nInput a number smaller than 101: \n");
		scanf(" %d", &num);
		pyramid(num);
		loopHolder = retest();
	}
	loopHolder = 0;
	
	printf("\n");
	return 0;
}