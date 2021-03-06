#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Collatz function
unsigned long collatz(unsigned long number)
	{
		if(number % 2 == 0)
		{
			number = number / 2;
			return (unsigned long)number;
		}
		else
		{
			number = 3 * number + 1;
			return (unsigned long)number;
		}
	}

int main(void)
{
	double timeElapsed;
	clock_t timeBegin;
	clock_t timeEnd;
	unsigned long intCalc;
	unsigned long intCounter = 0;

	printf("Please insert the positive integer you would like to use\n");
	printf("in the calculation: ");
	
	// Prompt for an integer. intCalc = the LAST integer to be calculated
	scanf("%li", &intCalc);		

	// Open stream in calculations.csv
	FILE *fp;	
	fp = fopen("calculations.csv", "w+");

        // Create an array for the "beaten path" optimization (patent also pending)
        // JT: replaced with dynamical allocation
	// unsigned long resultArray [intCalc+1];
        unsigned long * resultArray = malloc( (intCalc+1) * sizeof(unsigned long));
	
	// Populate the array with zeroes
	for(unsigned long i = 0; i <= intCalc; i++)
	{
		resultArray[i] = 0;
	}

	// Temp array
	unsigned long tempArray [1000];

	// Counter for tempArray
	int tempArrayCounter;
	
	// Start timer
	timeBegin = clock();

	// dataPoint = the current integer in the calculation
	for(unsigned long dataPoint = 1; dataPoint <= intCalc; dataPoint++)
	{
		unsigned long dataPointCalc = dataPoint;

		intCounter = 0;
		tempArray[intCounter] = dataPointCalc;

		// Run the collatz sequence
		while(dataPointCalc > 1)
		{
			// If the spot (integer we're looking at) in the resultArray is zero or it's outside the 
			// array, the program hasn't calculated that integer before 
			// (or we'll skip it for now altogether)
			if(dataPointCalc > intCalc)				
			{
				// Carry on with the sequence as usual
				dataPointCalc = collatz(dataPointCalc);					
				intCounter ++;
				tempArray[intCounter] = dataPointCalc;
				
			}
			else if(resultArray[dataPointCalc] == 0)
			{
				// Carry on with the sequence as usual
				dataPointCalc = collatz(dataPointCalc);					
				intCounter ++;
				tempArray[intCounter] = dataPointCalc;
			}
			// Otherwise, take the current intCounter and add the precalculated integer from the resultArray
			else													
			{
				tempArrayCounter = resultArray[dataPointCalc];
				break;
			}
		}

			// All immediately  simultaneously 
			for (int i = intCounter; i >= 0; i--)
			{
				if(tempArray[i] <= intCalc)
				{
					resultArray[tempArray[i]] = intCounter + tempArrayCounter - i;
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
