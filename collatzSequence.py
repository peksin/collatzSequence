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
