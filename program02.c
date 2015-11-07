/*
 * program02.c
 *
 *  Created on: Oct 4, 2015
 *      Author: Oscar De La Rosa
 *      Purpose: Calculate the total green crud (in pounds) according to the input data (# of days)
 *
 */


#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
int fibo(int num);
void clrKeyboardBuffer();

int main(int argc, char * argv[]) {
	char answer;
	int scanfReturn, greenCrud, days, tempVar, totalPounds;

	do {
		do {
			printf("Please enter the initial size of the green crud: ");
			scanfReturn = scanf("%d", &greenCrud);
			if(greenCrud <= 0 || scanfReturn == 0) {	// If greenCrud is zero or less, means there's nothing. Print warning and go to the end of the loop.
				clrKeyboardBuffer();
				printf("I'm sorry that value is unrecognizable or is negative.\n");
			}
			totalPounds = greenCrud;	// If the number of days isn't a multiple of 5, the crud population won't grow. Thus, this will be printed.
		} while(greenCrud <= 0);

		do {
			printf("Please enter the number of days: ");
			scanfReturn = scanf("%d", &days);
			if(days < 0 || scanfReturn == 0) {	// If days is negative, print warning and go to the end of the loop
				clrKeyboardBuffer();
				days = -1;						// Assign a negative number, since days would be full of random characters.
				printf("I'm sorry that value is unrecognizable or is negative.\n");
			}
			else if(days % 5 == 0) {	// If the number of days is a multiple of 5
				tempVar = days / 5;		// Divide by 5 to get input for Fibonacci sequence
				totalPounds *= fibo(tempVar);	// Call Fibonacci function, multiply the result by the original pounds, and assign it to totalPounds
			}
		} while(days < 0);

		printf("With an initial population of %d pounds of crud growing for %d day/s.\n", greenCrud, days);
		printf("The final population would be %d pound/s.\n", totalPounds);

		printf("Would you like to continue? (y/n) ");	// Ask the user if they want to run the program again.
		scanf(" %c", &answer);

	} while(answer == 'y' || answer == 'Y');			// If answer if y or Y, the program will run again

	return 0;
}

// Function definition
int fibo(int num) {				// As per the given definition
	if(num == 0 || num == 1)
		return 1;
	else
		return (fibo(num - 1) + fibo(num - 2));
}

void clrKeyboardBuffer() {
	char ch;
	scanf("%c", &ch);
	while(ch != '\n')
		scanf("%c", &ch);
}
