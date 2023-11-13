#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
const int MAX_RECORDS = 1000;

// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

int main() {
    // Declare an array to store FITNESS_DATA
    FITNESS_DATA data[MAX_RECORDS];
    
    

    // Open the CSV file for reading
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    // Read data from the file
    char line[100];
    int recordCount = 0;

    // while loop which counts and stores values from the file by tokeniseRecord function
    while (fgets(line, sizeof(line), file)) {
        // formats each value to its designated string
        char date[11], time[6], steps[11];
        tokeniseRecord(line, ",", date, time, steps);
        // copies data to its destination. date, time and steps
        strcpy(data[recordCount].date, date);
        strcpy(data[recordCount].time, time);
        data[recordCount].steps = atoi(steps);

        recordCount++;
    }       
    int minIndex = findFewestSteps(data, recordCount);
    int maxIndex = findLargestSteps(data, recordCount);
    int mean = meanSteps(data, recordCount);
    // Longestperiod(data, recordCount);
     
     char choice;
    printf("Menu:\n1. Option A\n2. Option B\n3. Option C\n4. Option D\n5. Option E\n6. Option F\n7. Option Q\nEnter your choice: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'A':
            printf("Input filename: %s\n", filename);
            break;
        case 'B':
            printf("Total records: %d\n", recordCount);
            break;
        case 'C':
            printf("Fewest Steps: %s %s\n", data[minIndex].date, data[minIndex].time);
            break;
        case 'D':
            printf("Largest steps: %s %s\n", data[maxIndex].date, data[maxIndex].time);
            break;
        case 'E':
            printf("Mean step count: %d\n", mean);
            break;
        case 'F':
           Longestperiod(data, recordCount);
           break;
        case 'Q':
            printf("Exiting the program.\n");
            return 0;
        
        
              
    }

    return 0;
}