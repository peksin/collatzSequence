#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* This program takes a sequence of integers (1..n) and calculates the 
 * steps required for each integer to reach zero according to the collatz
 * conjecture
 */

unsigned long collatz(unsigned long number) {
		if (number % 2 == 0) {
			number = number / 2;
			return (unsigned long)number;
		}
		else {
			number = 3 * number + 1;
			return (unsigned long)number;
		}
	}

int main(void) {
	double timeElapsed;
	clock_t timeBegin;
	clock_t timeEnd;
	unsigned long maxInt;
	unsigned long stepCounter = 0;

	printf("Please insert the positive integer you would like to use\n");
	printf("in the calculation: ");
	
	// Prompt for the size of the calculation
	scanf("%li", &maxInt);		

	// Open stream in calculations.csv
	FILE *fp;	
	fp = fopen("calculations.csv", "w+");

  // Create an array for the "beaten path" optimization (patent also pending)
  // JT: replaced with dynamical allocation
	// unsigned long resultArray [largestInteger+1];
  unsigned long *resultArray = malloc( (maxInt+1) * sizeof(unsigned long));
	
	// Populate the array with zeroes
	for (unsigned long i = 0; i <= maxInt; i++) {
		resultArray[i] = 0;
	}

	/* Temp array is used to store the path for the initialInt
   * We can then use it to move all the integers we calculated
   * along the way to the resultArray.
   * For example, after initialInt 3 the tempArray will look
   * like this:
   * [3,10,5,16,8,4,2,0,...,0]
   * The final 2 in that sequence is pulled from the resultArray
   * because the program already knows what the sequence will be
   * from that point on
   */ 
  
	unsigned long tempArray [1000];

	// Counter for tempArray
	int preCalcSteps;
	
	// Start timer
	timeBegin = clock();

	// initialInt = the current starting integer in the calculation
	for (unsigned long initialInt = 1; initialInt <= maxInt; initialInt++) {
		unsigned long currentInt = initialInt;

		stepCounter = 0;
		tempArray[stepCounter] = currentInt;

    // currentInt == 1 means we're finished with that integer
		while (currentInt > 1) {
      /* If currentInt is outside the resultArray (> maxInt), it hasn't
       * been calculated before */
			if (currentInt > maxInt) {
				currentInt = collatz(currentInt);					
				stepCounter ++;
				tempArray[stepCounter] = currentInt;
			}
      /* If this isn't 0, it has already been calculated
       * and we can add the remaining steps from resultArray */
			else if (resultArray[currentInt] == 0) {
				// Carry on with the sequence as usual
				currentInt = collatz(currentInt);					
				stepCounter ++;
				tempArray[stepCounter] = currentInt;
			}
			/* Add the remaining already calculated steps from the resultArray */
			else {
				preCalcSteps = resultArray[currentInt];
				break;
			}
		}

			/* 2020 note: I have a hard time fitting my head around this one anymore,
       * but I know it takes the amount of steps 
       * (stepCounter + preCalcSteps) and copies it to the resultArray.
       * tempArray for currentInt 3 looks like this: 
       * [3,10,5,16,8,4,2,0,...,0]
       * stepCounter: 6
       * preCalcSteps: 1
       */
			for (int i = stepCounter; i >= 0; i--) {
				if (tempArray[i] <= maxInt) {
					resultArray[tempArray[i]] = stepCounter + preCalcSteps - i;
				}
			}

		// Write the number of iterations required and the 
		// original number into the csv-file
    // fprintf(fp, "%ld,%ld\n", dataPoint, resultArray[dataPoint]);
	}
	
	// Close the stream
	fclose(fp);

	// Stop timer
	timeEnd = clock();

	// JT: free the memory allocation
  free(resultArray);
	
	// Timer info for user
	timeElapsed = (double)(timeEnd - timeBegin) / CLOCKS_PER_SEC;
	printf("Time elapsed: %f seconds. ", timeElapsed);
	printf("Output in calculations.csv. Thanks for playing!\n");
	return 0;
}
