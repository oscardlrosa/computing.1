/*
 * Author: Oscar De La Rosa
 * Date: 09/26/15
 *
 * Purpose: This program display the 'Oneness' property for two numbers in seven column in the format
 *          'x:y', where 'x' is the initial number and 'y' is the number of step that took from x->1
 *
 */

#include <stdio.h>

void clrKeyboardBuffer();
void oneness(int startPoint, int endPoint);

void clrKeyboardBuffer()
{
    char ch;
    scanf("%c", &ch);   // It takes the last character of the string, \n
    while(ch != '\n')   // Until \n is found it will stay inside this while loop
        scanf("%c", &ch);
}

void oneness(int startPoint, int endPoint)
{
    int stepsTo1 = 0;                        // How many steps to startPoint -> 1
    int newLnCounter = 0;                   // To help produce the seven columns
    int updatedStartPoint = startPoint;     // Copy startPoint to be used throughout the function
    while(startPoint <= endPoint)
    {
        if(updatedStartPoint % 2 == 0)          // Even number
        {
            updatedStartPoint = updatedStartPoint / 2;
            stepsTo1++;                              // Update steps
            if(updatedStartPoint == 1)
            {
                printf("%5d:%-5d", startPoint, stepsTo1);
                newLnCounter++;                     // Control of how many relationship have we printed

                if(newLnCounter == 7)               // After the 6th relationship, the counter will be seven, therefore we move to a new line.
                {
                    printf("\n");
                    newLnCounter = 0;                   // Set line counter back to zero, to print 7 new columns
                }

                startPoint++;                       // Move on to the next number
                stepsTo1 = 0;                        // Reset control
                updatedStartPoint = startPoint;     // Update startPoint copy
            }
        }
        else                                    // Odd number
        {
            updatedStartPoint = 3 * updatedStartPoint + 1;
            stepsTo1++;                              // Update control
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int firstGivenNumber, secondGivenNumber;

    printf("__--Oneness Property--__\n");
	printf("Enter a starting point (a number between 1-1,000): ");
    scanf("%d", &firstGivenNumber);

    while(firstGivenNumber <= 1 || firstGivenNumber >= 1000)
    {
        clrKeyboardBuffer();
        printf("I'm sorry. The first number should be between 1 and 1000. Try again: ");
        scanf("%d", &firstGivenNumber);
    }

    printf("Enter an ending point (a number between previous number-10,000): ");
    scanf("%d", &secondGivenNumber);

    while(secondGivenNumber <= firstGivenNumber || secondGivenNumber >= 10000)
    {
        clrKeyboardBuffer();
        printf("Sorry, but the second number must be higher than the first number and less than 10,000. Please, try again: ");
        scanf("%d", &secondGivenNumber);
    }

    oneness(firstGivenNumber, secondGivenNumber);

	return 0;
}
