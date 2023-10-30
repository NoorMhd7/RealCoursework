#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
#define MAX_RECORDS 1000


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

    while (fgets(line, sizeof(line), file)) {
        char date[11], time[6], steps[4];
        tokeniseRecord(line, ",", date, time, steps);
        strcpy(data[recordCount].date, date);
        strcpy(data[recordCount].time, time);
        data[recordCount].steps = atoi(steps);
        recordCount++;
    }

    // Print the number of records
    printf("Number of records in file: %d\n", recordCount);

    // Print the first three rows with date, time, and steps
    for (int i = 0; i < 3; i++) {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}
