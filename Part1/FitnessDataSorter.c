#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
const int MAX_RECORDS = 1000;
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {

    FitnessData data[MAX_RECORDS]; 
    char filename[100];
    char line[100];
    int recordCount = 0;

    printf("Enter filename: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, " %s ", filename);
    FILE *input = fopen(filename, "r");

    if (!input) {
        printf("Error:Inavali file\n");
        return 1;
    } 

    // This checks if the is correctly formated
    while (fgets(line, sizeof(line), input)) {
        char date[11], time[6];
        int steps;
        if (sscanf(line, "%10[^,],%5[^,],%d", date, time, &steps) != 3) {
            printf("Error: Invalid file\n");
            fclose(input);
            return 1;
            }    }

    // Reset file pointer to the beginning of the file
    fseek(input, 0, SEEK_SET);
    while (fgets(line, sizeof(line), input)) {
        char date[11], time[6];
        int steps;
        tokeniseRecord(line, ',', date, time, &steps);
        strcpy(data[recordCount].date, date);
        strcpy(data[recordCount].time, time);
        data[recordCount].steps = steps;

        recordCount++; }

    // https://www.youtube.com/watch?v=YqzNgaFQEh8 // Bubble sort to order the data from most steps to lease
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - 1 - i; j++) {
            if (data[j].steps < data[j + 1].steps) {
                // Swap steps
                int temp = data[j].steps;
                data[j].steps = data[j + 1].steps;
                data[j + 1].steps = temp;
            }
        }
    }

   
    
    // Wries on file name which adds '.tsv' at he end and stores sorted data
    strcat(filename, ".tsv");
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {perror("");
    return 1; }
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
 
    fclose(file);
    return 0;

       

}
