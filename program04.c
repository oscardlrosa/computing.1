/*
 * program04.c
 *
 *  Created on: Nov 9, 2015
 *      Author: Oscar De La Rosa
 *     Purpose:	Take an input file, "quiz.txt", and manipulate its content, calculate average for quizzes and printing them to an output file, "average.txt"
 */


#include<stdio.h>
#include<stdlib.h>

#define MAX_QUIZZES 10	// Number of total quizzes

// Function prototypes
void openFiles(FILE ** pntrQuiz, FILE ** pntrAverage);	// Function to open files
void closeFiles(FILE * quiz, FILE * average);			// Function to close files
int processingFiles(FILE * quiz, FILE * average);		// Function to process files
int readName(FILE * quiz, FILE * average);				// Function to read the names in input file
void readGrade(FILE * quiz, FILE * average, int name);	// Function to read the grades in input file

int main(int argc, char *argv[]) {

	FILE *quiz, *average;
	int processed = 0;

	printf("Quiz Avg. Program\n");
	openFiles(&quiz, &average);	// Open files
	processed = processingFiles(quiz, average);	// Process files

	if(processed == -1)
		printf("ERROR: FILE EMPTY!\n");	// Let the user know if there's an error

	if(processed == 1)
		printf("Please check the file \"average.txt\" for the average of the quizzes.\nThank you.\n");	// Let the user know that the operation was successful

	closeFiles(quiz, average);	// Close files

	return 0;
}

// PRECON: Take input file double pointer, output file double pointer
// POSTCON: Open files
void openFiles(FILE ** pntrQuiz, FILE ** pntrAverage) {

		*pntrQuiz = fopen("/home/delarosa/.workspace/program04/quiz.txt", "r");

		if(*pntrQuiz == NULL) {	// If file opening unsuccessful
			fprintf(stderr, "\"quiz.txt\" failed to open,\n");
			printf("\"quiz.txt\" failed to open,\n");
			exit(1);
		}

		*pntrAverage = fopen("/home/delarosa/.workspace/program04/average.txt", "w");

		if(*pntrAverage == NULL) {	// If file opening unsuccessful
			fprintf(stderr, "\"average.txt\" failed to open,\n");
			printf("\"average.txt\" failed to open,\n");
			exit(1);
		}
}

// PRECON: Take input file pointer, output file pointer
// POSTCON: Close files
void closeFiles(FILE * quiz, FILE * average) {

	// Close both files
	fclose(quiz);
	fclose(average);

}

// PRECON: Take input file pointer, output file pointer
// POSTCON: Process the input file, if not empty, print header to output file, return value to main function
int processingFiles(FILE * quiz, FILE * average) {

	int name = 0, notEmpty = 0;

	notEmpty = fgetc(quiz);	// Read first character
	ungetc(notEmpty, quiz);	// Go back at the beginning of the file

	if(notEmpty == EOF)	// If file empty
		return -1;

	fprintf(average, "Name\tQuiz:\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\tAverage\n");	// Print header to output file
	fprintf(average, "=======================================================================================================\n");

	while(notEmpty != EOF) {	// File the file is not at the end
		name = readName(quiz, average);	// Get names
		fprintf(average, " ");
		readGrade(quiz, average, name);	// Get grades

		notEmpty = fgetc(quiz);	// Get next character
		ungetc(notEmpty, quiz);
	}

	return 1;
}

// PRECON: Take input file pointer, output file pointer
// POSTCON: Print names into output file and return length of name
int readName(FILE * quiz, FILE * average) {

	int name, count = 0;

	do {
		name = fgetc(quiz);	// Start reading names
		count++;			// And counting up characters
	}while(name != 32);

	do {
		name = fgetc(quiz);
		count++;
	}while(name != 32 && name != '\n' && name != EOF);

	if(name == '\n')
		count++;	// Avoid names being cutoff, because some may not have 10 quizzes grades

	fseek(quiz, -(long)count, SEEK_CUR);	// Reset cursor position

	do {
		name = fgetc(quiz);
		if(name != '\n')			// No new lines
			fputc(name, average);	// Error fix when there's no quiz grades
	}while(name != 32);

	do {
		name = fgetc(quiz);
		if(name != '\n' && name != EOF) // No new lines
			fputc(name, average);
		if(name == EOF || name == '\n')	// Extra space: student with no grades
			fputc(' ', average);
	}while(name != 32 && name != '\n' && name != EOF);	// Running until space, new line, eof

	return name;
}

// PRECON: Take input file pointer, output file pointer and the length of name
// POSTCON: Print grades to output file to their corresponding students
void readGrade(FILE * quiz, FILE * average, int name) {

	int num = 0, sum = 0, count = 0;
	double avg = 0;

	if(name != 13) {	// If there're numbers, try to get the next 10

		while(fscanf(quiz, "%d", &num) == 1) {	// Run while we find a number

			sum += num;
			fprintf(average, "\t%d", num);
			count++;
		}
	} else
		sum = 0;	// If there's no number assign 0 to sum

	if(count != MAX_QUIZZES) {	// If we haven't got 10 quizzes

		count = MAX_QUIZZES - count;	// We're adding this number to p

		while(count > 0) {

			fprintf(average, "\t0");	// For the grade that's not there i.e. 0
			count--;
		}
	}

	fprintf(average, " ");	// Add space between grades and average
	avg = (double)sum / MAX_QUIZZES;	// Get average
	fprintf(average, "\t%g\n", avg);		// Print average to file, accounting for the extra zeroes
}
