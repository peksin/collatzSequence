def collatz(number):
    if number % 2 == 0:
        number = number / 2
        return int(number)
    else:
        number = 3 * number + 1
        return number


iterationCounter = 0

while True:
    try:
        numberUser = int(input("Please enter a number: "))
        break
    except ValueError:
        print("Invalid value, please enter a number")

while collatz(numberUser) != 1:

    numberUser = collatz(numberUser)
    print(str(numberUser))
    iterationCounter = iterationCounter + 1
    continue
print(collatz(numberUser))



#  Write software to print out numbers of
#  iterations required per each input number
#  Make a plot of the number of iterations over the input number in
#  LibreOffice, and then in R/Python. Does the sequence work with floating
#  point numbers? Will probably need to trim them out a bit...
