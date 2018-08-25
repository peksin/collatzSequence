#include <stdio.h>
#include <time.h>

int collatz(int number)
	{
		if(number % 2 == 0)
		{
			number = number / 2;
			return (int)number;
		}
		else
		{
			number = 3 * number + 1;
			return (int)number;
		}
	}

int main(void)
{
	double timeElapsed;
	clock_t timeBegin;
	clock_t timeEnd;
	unsigned int intCalc;
	int intCounter = 0;

	printf("Please insert the positive integer you would like to use\n");
	printf("in the calculation: ");
	scanf("%i", &intCalc);

	timeBegin = clock();
	while(intCalc != 1)
	{
		printf("%d\n", intCalc);
		intCalc = collatz(intCalc);
		intCounter ++;
	}
        printf("1\n");
	timeEnd = clock();
	timeElapsed = (double)(timeEnd - timeBegin);

	printf("Iterations required to arrive back at one: %d\n", intCounter);
	printf("Time elapsed: %f. ", timeElapsed);
	printf("Thanks for playing!\n");
	return 0;
}
