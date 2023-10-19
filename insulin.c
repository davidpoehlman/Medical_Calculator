/******************************************************************************
 *
 * insulin.c
 *
 * This program will calculate the amount of insulin needed to take for an 
 * adjustive dose to compensate for a patient's high blood sugar level.
 * 
 * Author: David Poehlman
 * Version: 0.4
 * Date: 2023.09.30	
 * Update: 2023.10.19
 * 
 * Version 0.1:
 * Get base code created and printing something.
 * 
 * Version 0.2:
 * Adjust for input validation.
 * 
 * Version 0.3:
 * Adjust for error handling.
 * 
 * Version 0.4:
 * Adjust print statements and compensate for too high/low values.
 * 
 *****************************************************************************/

// Preprocessor Statements
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// CONSTANTS
#define CARBOHYDRATE_COVERAGE 15
#define GLUCOSE_LOW 70
#define GLUCOSE_HIGH 350

// typedefs and structures

// globalVariables

// FunctionPrototypes
float inputChecker(const char* prompt);


int main(void)
{
    // Local Declarations:
    float glucoseTarget, glucoseCurrent, glucoseFinal, insulinAmt;

    // Statements:
    printf("This script will Identify the amount of insulin you should take for your adjusted dose...\n");

    // This is the main function that will call the inputChecker function to validate the inputs.
    glucoseCurrent = inputChecker("Please start by entering in your current glucose level: ");
    glucoseTarget  = inputChecker("Now enter the level your glucose is supposed to be at: ");

    // This is the main function that will calculate the amount of insulin needed to take for an adjustive dose to compensate for a patient's high blood sugar level.
	glucoseFinal = glucoseCurrent - glucoseTarget;
	insulinAmt   = glucoseFinal / (float)CARBOHYDRATE_COVERAGE;

    // This is the main function that will print the results of the calculations.

    if (glucoseCurrent <= GLUCOSE_LOW)
    {
        printf("\n\nYour glucose level is much too low for an adjustive dose.\n");
        printf("Please call your endocronologist for further assistance!\n");
        return 0;
    }
    else if (glucoseCurrent >= GLUCOSE_HIGH)
    {
        printf("\n\nYour glucose level is much too high. Please call your endocronologist for further assistance!\n");
        printf("If you are directed to take an adjustive dose based on the provided formula, please take\n");
        printf("%.1f unit(s) of insulin to compensate.\n", insulinAmt);
        return 0;
    }
    else if (insulinAmt < 0)
	{
        printf("\n\nAfter careful consideration... You dont need an adjustive dose of insulin!\n");
        return 0;
	}
    else
    {
        printf("\nAfter careful consideration... You need to take more insulin.\n");
	    printf("Please take %.1f unit(s) of insulin to compensate.\n", insulinAmt);
    }
	
	return 0;
}

/* Secondary function that handles the input validation of the numbers requested in the terminal.
(This is essentially version 0.2 of this function.) */
float inputChecker(const char* prompt) {

    // Local Declarations:
    float inputValue;
    int y;

    // Statements:
    while (1)
    {
        
        // Initialize the variables.
        inputValue = 0;
        y = 0;

        // This is the main function that will print the prompt and scan the input for the inputValue.
        printf("%s", prompt);                                              
        if (scanf("%f", &inputValue) != 1 || (y = getchar()) != '\n')
        {
            // This is the main function that will print the error message and clear the input buffer.
            printf("Invalid! Please enter a proper value!\n\n");
            while ((y = getchar()) != '\n' && y != EOF) {}
        }
        else if (inputValue < 0)
        {
            printf("Invalid! Please enter a positive number!\n\n");
        }
        else
        {
            break;
        }
    }
    return inputValue;  // This will return the inputValue to the main function.
}