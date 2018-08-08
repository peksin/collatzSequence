import time
import numpy


def collatz(number):
    if number % 2 == 0:
        number = number / 2
        return int(number)
    else:
        number = 3 * number + 1
        return number


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

# Create a list for the integers about to be passed through the sequence

listIntegers = list(range(1, listSize +1))
dataPoint = 0
timeStart = time.process_time()
resultArray = numpy.zeros(shape = (listSize,2), dtype = int)

# Maximum output, activate the pit!

while dataPoint < listSize:
    integerCalc = listIntegers[dataPoint]
    resultArray[dataPoint,0] = integerCalc
    print(integerCalc, end = ',')
    while collatz(integerCalc) != 1:
        integerCalc = collatz(integerCalc)
        iterationCounter = iterationCounter + 1
        continue
    print(str(iterationCounter))
    resultArray[dataPoint,1] = iterationCounter
    dataPoint = dataPoint + 1
    iterationCounter = 1
    continue

timeEnd = time.process_time()
timeElapsed = timeEnd - timeStart
numpy.savetxt("output.csv", resultArray, delimiter = ",")
print("Sequence complete. Elapsed time: ' + str(timeElapsed) + ' seconds. Results written in 'output.csv'")



# Add code to append the outputs into a list/array/dataframe
# Make a plot of the number of iterations over the input number in
# LibreOffice, and then in R/Python. Does the sequence work with floating
# point numbers? Will probably need to trim them out a bit...
