# Calculation modules for the master program
# Pekka Sinkkonen, 8.8.2018

import time
import numpy
import decimal
from termcolor import cprint

# The basic collatz logic to be used in the modules to follow

def collatz(number):
    if number % 2 == 0:
        number = number / 2
        return int(number)
    else:
        number = 3 * number + 1
        return number

#############################################################################

# Prints each step of the sequence on its own line

def printEachStep():

    iterationCounter = 0

    while True:
        try:
            numberUser = int(input("Please enter the number you wish to iterate: "))
            break
        except ValueError:
            print("Invalid value, please enter a number")

    while collatz(numberUser) != 1:

        numberUser = collatz(numberUser)
        print(str(numberUser))
        iterationCounter = iterationCounter + 1
        continue
    print(collatz(numberUser))

############################################################################

# Counts out the number of iterations required and prints the output in a csv

def iterations():
    iterationCounter = 1

    while True:
        try:
            listSize = int(input("Enter the desired size of the collatz sequence visualization: "))
            break
        except ValueError:
            print("Invalid value, please enter a number")


    # listIntegers = The actual list of the numbers to be sequenced
    # dataPoint = Position (in the list) of the number to be sequenced
    # integerCalc = The integer to be sequenced
    # iterationCounter = Keep track of the number of iterations needed to reach '1'
    # timeStart, timeEnd = Used to calculate elapsed time
    # resultArray = Numpy array for the results
    # Probably could've been done with a list, but hey

    # Create a list for the integers about to be
    # passed through the sequence (now's the time
    # to get hype)

    listIntegers = list(range(1, listSize +1))
    dataPoint = 0
    timeStart = time.process_time()
    resultArray = numpy.zeros(shape = (listSize,2), dtype = int)

    # Maximum output, activate the pit!

    cprint('Calculating...', attrs = ['blink'],
    end = "\r")

    while dataPoint < listSize:
        integerCalc = listIntegers[dataPoint]
        resultArray[dataPoint,0] = integerCalc

        while collatz(integerCalc) != 1:
            integerCalc = collatz(integerCalc)
            iterationCounter = iterationCounter + 1
            continue

        resultArray[dataPoint,1] = iterationCounter
        dataPoint = dataPoint + 1
        iterationCounter = 1
        continue

    print('Calculating...Complete.')
    timeEnd = time.process_time()
    timeElapsed = decimal.Decimal(timeEnd - timeStart)
    timeElapsed = round(timeElapsed,6)
    numpy.savetxt("output.csv", resultArray, fmt = '%10.0f', delimiter = ",")
    print("Sequence complete. Elapsed time: " + str(timeElapsed) + " seconds. Results written in 'output.csv'")
