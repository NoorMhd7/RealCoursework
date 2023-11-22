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

while (fgets(line, sizeof(line), input)) {
    char date[11], time[6], steps[11];
    tokeniseRecord(line, ",", date, time, steps);
    strcpy(data[recordCount].date, date);
    strcpy(data[recordCount].time, time);
    data[recordCount].steps = atoi(steps);

    recordCount++;

    if (sscanf(line, "%10[^,],%5[^,],%d", line, line, line) != 3) {
        fprintf(stderr, "Invalid data type at line %d\n", recordCount);
        fclose(filename);
        return 1; // 120
            }

}

}