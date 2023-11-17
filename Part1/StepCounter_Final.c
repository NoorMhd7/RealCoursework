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
    char filename[100];
    
    

    

    // Read data from the file
    char line[100];
    int recordCount = 0;

    

       
     int minIndex;
     int maxIndex;
     int mean;
    
    while (1) {      
        char choice;
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        
        scanf("%c", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 'A':
            printf("Input filename: ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, " %s ", filename);
            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: Could not find or open the file.\n");
                return 1;  }
            else {
                printf("File successfully loaded.\n");
            }
            
            while (fgets(line, sizeof(line), input))
            {         
                char date[11], time[6], steps[11];
                tokeniseRecord(line, ",", date, time, steps);
                strcpy(data[recordCount].date, date);
                strcpy(data[recordCount].time, time);
                data[recordCount].steps = atoi(steps);

                recordCount++;}
                break;

            
                   
                        
                 
            case 'B':
                printf("Total records: %d\n", recordCount);
                break;
            case 'C':
                minIndex = findFewestSteps(data, recordCount);
                printf("Fewest Steps: %s %s\n", data[minIndex].date, data[minIndex].time);
                break;
            case 'D':
                maxIndex = findLargestSteps(data, recordCount);
                printf("Largest steps: %s %s\n", data[maxIndex].date, data[maxIndex].time);
                break;
            case 'E':
                mean = meanSteps(data, recordCount);
                printf("Mean step count: %d\n", mean);
                break;
            case 'F':
                Longestperiod(data, recordCount);
                break;
            case 'Q':
                return 0;

            default: 
                printf("Invalid choice. Try again.\n");
                break;   
        }
        
        
              
    } 

}
