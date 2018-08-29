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

	// Create an array for the "beaten path" optimization (patent also pending)
    // JT: replaced with dynamical allocation
	// unsigned long resultArray [intCalc+1];
    unsigned long * resultArray = malloc( (intCalc+1) * sizeof(unsigned long));
	
	// Populate the array with zeroes
	for(int i = 0; i <= intCalc; i++)
	{
		resultArray[i] = 0;
	}
	
	// Start timer
	timeBegin = clock();

	// dataPoint = the current integer in the calculation
	for(unsigned long dataPoint = 1; dataPoint <= intCalc; dataPoint++)
	{
		unsigned long dataPointCalc = dataPoint;
		intCounter = 0;

		// Run the collatz sequence
        // JT: replaced != 1, because it is slower to evaluate, when you think about it in binary
		while(dataPointCalc > 1)
		{
            // JT: changed the order of if-clauses. Not sure if better or worse now, but might
            // at least be better this way with the next level optimization
			if(dataPointCalc > intCalc)
			{
                // Carry on with the sequence as usual
				dataPointCalc = collatz(dataPointCalc);					
				intCounter ++;
			}
            else if(resultArray[dataPointCalc] > 0)
			{
                intCounter = intCounter + resultArray[dataPointCalc];
				//dataPointCalc = 1; // replaced with break to speed up
                break;
			}
			else
			{
				// Carry on with the sequence as usual
				dataPointCalc = collatz(dataPointCalc);					
				intCounter ++;
			}

		}
    	// Write the result to resultArray for future generations
		resultArray[dataPoint] = intCounter;

	}
	
	// Open stream in calculations.csv
    // JT: Moved the file generation here, so that it is easier to enable/disable.
    // Makes a small penalty, because another loop is needed.
    // Generally file-IO is slow and should be avoided, but here the writing is linear and
    // the old way could actually be the wisest. Still, writing to disk takes 60-70% of the
    // time even on an SSD.
	FILE *fp;	
	fp = fopen("calculations.csv", "w+");

    for(unsigned long dataPoint = 1; dataPoint <= intCalc; dataPoint++)
	{
	    // Write the number of iterations required and the 
        // original number into the csv-file
        fprintf(fp, "%ld,%ld\n", dataPoint, resultArray[dataPoint]);
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
