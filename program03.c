/*
 * program03.c
 *
 *  Created on: Oct 24, 2015
 *      Author: Oscar De La Rosa
 *     Purpose: This program will convert length and weight from Metric system to the US system according to the user choices
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Constants declarations: Use entirely for conversion
#define METERS_IN_A_FOOT 0.3048
#define INCHES_IN_A_FOOT 12
#define CENTIMETERS_IN_A_METER 100
#define POUNDS_IN_A_KG 2.2046
#define GRAMS_IN_A_KG 1000
#define OUNCES_IN_A_LB 16

// Function declarations
void convert_lengths();
void length_to_metric();
void length_to_us();
void convert_weights();
void weight_to_metric();
void weight_to_us();

void initial_values_length_metric();
void initial_values_length_us();
void convert_values_length_metric(double *main_conv_value, double *sec_conv_value);
void convert_values_length_us(double *main_conv_value, double *sec_conv_value);
void output_values_length_metric(double main_out_value, double sec_out_value);
void output_values_length_us(double main_out_value, double sec_out_value);

void initial_values_weight_metric();
void initial_values_weight_us();
void convert_values_weight_metric(double *main_conv_value, double *sec_conv_value);
void convert_values_weight_us(double *main_conv_value, double *sec_conv_value);
void output_values_weight_metric(double main_out_value, double sec_out_value);
void output_values_weight_us(double main_out_value, double sec_out_value);

void clr_keyboard_buffer();
int validate_input(int num, int not_int_char);
void validate_values(int *num_1, double *num_2, int non_int_char);

int main() {
	int user_input, scanf_return;

	do {
		printf("Conversion Menu:\n\t1. Lengths\n\t2. Weights\n\t0. Exit the program\nSelection: ");
		scanf_return = scanf("%d", &user_input);
		user_input = validate_input(user_input, scanf_return);	// Validate function only allows 0, 1, 2 to be use as inputs

		switch(user_input)
		{
		case 0:	// Quit the program
			printf("\nYou selected %d. This program will quit now... Bye.\n", user_input);
			break;
		case 1: // Deal with lengths
			printf("\nYou've selected %d. This program will convert lengths\n", user_input);
			convert_lengths();	// Call convert_lenghts function
			break;
		case 2: // Deal with weights
			printf("\nYou've selected %d. This program will convert weights\n", user_input);
			convert_weights();	// Call convert_weights function
			break;
		}
	} while(user_input != 0);

	return 0;
}

// Convert lengths function
void convert_lengths() {
	int user_input, scanf_return;
	printf("Would you like to go convert from:\n");
	printf("\t 1. Feet/Inches to Meters/Centimeters\n\t 2. Meters/Centimeters to Feet/Inches\n\t 0. Go back\n Selection: ");
	scanf_return = scanf("%d", &user_input);
	user_input = validate_input(user_input, scanf_return);
	switch(user_input)
	{
	case 0:	// No more lengths conversions. Go back to main
		break;
	case 1: // Feet/Inches to Meters/Centimeters
		length_to_metric();
		break;
	case 2: // Meters/Centimeters to Feet/Inches
		length_to_us();
		break;
	}
}

// Convert weights function
void convert_weights() {
	int user_input, scanf_return;
	printf("Would you like to go convert from:\n");
	printf("\t 1. Pounds/Ounces to Kilograms/Grams\n\t 2. Kilograms/Grams to Pounds/Ounces\n\t 0. Go back\n Selection: ");
	scanf_return = scanf("%d", &user_input);
	user_input = validate_input(user_input, scanf_return);
	switch(user_input)
	{
	case 0:	// No more lengths conversions. Go back to main
		break;
	case 1: // Feet/Inches to Meters/Centimeters
		weight_to_metric();
		break;
	case 2: // Meters/Centimeters to Feet/Inches
		weight_to_us();
		break;
	}
}

// Stub functions definition for length and weight
// Awaiting further instructions...
void length_to_metric() {
	printf("\nTo metric system. (Length)\n");
	initial_values_length_metric();
}

void length_to_us() {
	printf("\nTo US system. (Length)\n");
	initial_values_length_us();
}

void weight_to_metric() {
	printf("\nTo metric system. (Weight)\n");
	initial_values_weight_metric();
}

void weight_to_us() {
	printf("\nTo US system. (Weight)\n");
	initial_values_weight_us();
}

void initial_values_length_metric() {
	int main_value, scanf_return;
	double sec_value, main_value_db;
	printf("Please enter your values to be converted (Feet, Inches): ");
	scanf_return = scanf("%d %lf", &main_value, &sec_value);
	validate_values(&main_value, &sec_value, scanf_return);	// Validate inputs
	main_value_db = main_value;	// Make a double copy of the original value for further manipulation
	convert_values_length_metric(&main_value_db, &sec_value);
}

void initial_values_length_us() {
	int main_value, scanf_return;
	double sec_value, main_value_db;
	printf("Please enter your values to be converted (Meters, Centimeters): ");
	scanf_return = scanf("%d %lf", &main_value, &sec_value);
	validate_values(&main_value, &sec_value, scanf_return);	// Validate inputs
	main_value_db = main_value;	// Make a double copy of the original value for further manipulation
	convert_values_length_us(&main_value_db, &sec_value);
}

void convert_values_length_metric(double *main_conv_value, double *sec_conv_value) {
	double main_conv_decimal_extracted, main_conv_decimal_int;

	*main_conv_value *= METERS_IN_A_FOOT; // Converted to meters
	main_conv_decimal_extracted = modf(*main_conv_value, &main_conv_decimal_int);	// Get decimal extract
	main_conv_decimal_extracted *=  CENTIMETERS_IN_A_METER;	// Convert extracted value into centimeters
	*main_conv_value = main_conv_decimal_int;	// Update value after decimal extraction

	*sec_conv_value = *sec_conv_value / INCHES_IN_A_FOOT * METERS_IN_A_FOOT * CENTIMETERS_IN_A_METER; // Converted to centimeters
	*sec_conv_value += main_conv_decimal_extracted;	// Add extract to converted centimeters
	output_values_length_metric(*main_conv_value, *sec_conv_value);	// Send values to be printed
}

void convert_values_length_us(double *main_conv_value, double *sec_conv_value) {
	double main_conv_decimal_extracted, main_conv_decimal_int, sec_conv_decimal_extracted, sec_conv_decimal_int;

	*main_conv_value /= METERS_IN_A_FOOT;	// Converted to feet
	main_conv_decimal_extracted = modf(*main_conv_value, &main_conv_decimal_int);	// Get decimal extract
	main_conv_decimal_extracted *= INCHES_IN_A_FOOT;	// Convert extracted value into inches
	*main_conv_value = main_conv_decimal_int;	// Update the value after decimal extraction

	*sec_conv_value = *sec_conv_value / CENTIMETERS_IN_A_METER * INCHES_IN_A_FOOT / METERS_IN_A_FOOT; // Converted to inches
	*sec_conv_value += main_conv_decimal_extracted;
	if(*sec_conv_value >= INCHES_IN_A_FOOT) {	// If number of inches greater than 12 = 1 foot
		*sec_conv_value /= INCHES_IN_A_FOOT;	// Convert inches to feet
		sec_conv_decimal_extracted = modf(*sec_conv_value, &sec_conv_decimal_int);	// Extract decimal inches
		*main_conv_value += sec_conv_decimal_int;	// Add converted feet to main value
		*sec_conv_value = sec_conv_decimal_extracted;	// Update the new value for inches

	}
	output_values_length_us(*main_conv_value, *sec_conv_value);		// Send values to be printed
}

void output_values_length_metric(double main_out_value, double sec_out_value) {
	printf("Your converted value is %g meters, %g centimeters\n\n", main_out_value, sec_out_value);
}

void output_values_length_us(double main_out_value, double sec_out_value) {
	printf("Your converted value is %g feet, %g inches\n\n", main_out_value, sec_out_value);
}

void initial_values_weight_metric() {
	int main_value, scanf_return;
	double sec_value, main_value_db;
	printf("Please enter your values to be converted (Pounds, Ounces): ");
	scanf_return = scanf("%d %lf", &main_value, &sec_value);
	validate_values(&main_value, &sec_value, scanf_return);	// Validate inputs
	main_value_db = main_value;	// Make a double copy of the original value for further manipulation
	convert_values_weight_metric(&main_value_db, &sec_value);
}
void initial_values_weight_us() {
	int main_value, scanf_return;
	double sec_value, main_value_db;
	printf("Please enter your values to be converted (Kilograms, Grams): ");
	scanf_return = scanf("%d %lf", &main_value, &sec_value);
	validate_values(&main_value, &sec_value, scanf_return);	// Validate inputs
	main_value_db = main_value;	// Make a double copy of the original value for further manipulation
	convert_values_weight_us(&main_value_db, &sec_value);
}

void convert_values_weight_metric(double *main_conv_value, double *sec_conv_value) {
	double main_conv_decimal_extracted, main_conv_decimal_int;

	*main_conv_value /= POUNDS_IN_A_KG;	// Converted to Kilograms
	main_conv_decimal_extracted = modf(*main_conv_value, &main_conv_decimal_int);	// Extract decimal portion of conversion
	main_conv_decimal_extracted *= GRAMS_IN_A_KG; // Convert the extracted KG to g
	*main_conv_value = main_conv_decimal_int;	// Update value after decimal extraction

	*sec_conv_value = *sec_conv_value / OUNCES_IN_A_LB / POUNDS_IN_A_KG * GRAMS_IN_A_KG;	// Converted to grams
	*sec_conv_value += main_conv_decimal_extracted;	// Add extracted value grams to grams
	output_values_weight_metric(*main_conv_value, *sec_conv_value);
}

void convert_values_weight_us(double *main_conv_value, double *sec_conv_value) {
	double main_conv_decimal_extracted, main_conv_decimal_int;

	*main_conv_value *= POUNDS_IN_A_KG;	// Converted to Pounds
	main_conv_decimal_extracted = modf(*main_conv_value, &main_conv_decimal_int);	// Extract decimal portion of conversion
	main_conv_decimal_extracted /= GRAMS_IN_A_KG;	// Convert the extracted pounds to ounces
	*main_conv_value = main_conv_decimal_int;	// Update value after decimal extraction

	*sec_conv_value = *sec_conv_value / GRAMS_IN_A_KG * POUNDS_IN_A_KG * OUNCES_IN_A_LB;	// Converted to Ounces
	*sec_conv_value += main_conv_decimal_extracted;	// Add extracted value ounces to ounces
	output_values_weight_us(*main_conv_value, *sec_conv_value);
}

void output_values_weight_metric(double main_out_value, double sec_out_value) {
	printf("Your converted value is %g Kilograms, %g grams\n\n", main_out_value, sec_out_value);
}

void output_values_weight_us(double main_out_value, double sec_out_value) {
	printf("Your converted value is %g pounds, %g ounces\n\n", main_out_value, sec_out_value);
}

// Functions for validation of input and clearing of the buffer
void clr_keyboard_buffer() {
	char ch;
	scanf("%c", &ch);
	while(ch != '\n')
		scanf("%c", &ch);
}

int validate_input(int num, int non_int_char) {
	while(num < 0 || num >= 3 || non_int_char == 0) {	// If the input is less than zero, greater or equal than 3, or characters, it will keep asking the user for a valid input
		clr_keyboard_buffer();
		printf("\nI'm sorry that number is not valid\n");
		printf("Please enter a valid number: ");
		non_int_char = scanf("%d", &num);		// Re-check to see if we have a valid input
	}
	return num;
}

void validate_values(int *num_1, double *num_2, int non_int_char) {
	while(*num_1 < 0 || *num_2 < 0 || non_int_char == 0) {	// If the input is less than zero, greater or equal than 3, or characters, it will keep asking the user for a valid input
		clr_keyboard_buffer();
		printf("\nI'm sorry that number is not valid\n");
		printf("Please enter a valid number: ");
		non_int_char = scanf("%d %lf", num_1, num_2);		// Re-check to see if we have a valid input
	}
}
