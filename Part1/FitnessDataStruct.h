#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

// Implementation for finding the index of the record with the fewest steps. 
int findFewestSteps(const FITNESS_DATA *data, int size) {
    int minIndex = 0;
    int minSteps = data[0].steps;
   //  Source: https://www.youtube.com/watch?v=9DJYGr2W5y8
    for (int i = 1; i < size; ++i) {
        if (data[i].steps < minSteps) {
            minIndex = i;
            minSteps = data[i].steps;
        }
    }

    return minIndex;
}

// Implementation for finding the index of the record with the largest steps. 
int findLargestSteps(const FITNESS_DATA *data, int size) {
    
    int maxIndex = 0;
    
    int maxSteps = data[0].steps;

    // Source: https://www.youtube.com/watch?v=9DJYGr2W5y8
    for (int i = 1; i < size; ++i) {
        
        if (data[i].steps > maxSteps) {
            maxIndex = i;
            maxSteps = data[i].steps;
        }
    }

    return maxIndex;
}

int meanSteps(const FITNESS_DATA *data, int size) {
    if (size == 0) {
        return 0;  // Avoid division by zero
    }

    int sum = 0;

    // Iterate through each element in the data array
    for (int i = 0; i < size; i++) {
        sum += data[i].steps;
    }

    // Calculate the mean
    int mean = sum / size;

    return mean;
}

void Longestperiod(const FITNESS_DATA *data, int size) {
    int maxLength = 0;
    int startIndex = 0;
    int currentLength = 0;
    int currentStart = 0;

    for (int i = 0; i < size; i++) {
        if (data[i].steps > 500) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                startIndex = currentStart;
            }
            currentLength = 0;
            currentStart = i + 1;
        }
    }

    // Check at the end of the array
    if (currentLength > maxLength) {
        maxLength = currentLength;
        startIndex = currentStart;
    }

    // Output the result
         printf("Longest period start: %s %s\nLongest period end: %s %s\n",
            data[startIndex].date, data[startIndex].time, data[startIndex + maxLength - 1].date, data[startIndex + maxLength - 1].time);
      
     
}     
        
#endif // FITNESS_DATA_STRUCT_H