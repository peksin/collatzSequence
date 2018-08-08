# Master program calling out the calculation
# modules for different stuff you can do with the
# Collatz conjecture.
# Pekka Sinkkonen, 8.8.2018

import calcModules as cM


print("Welcome to the Collatz sequence calulation and visualization tool.\nWhat would you like to do? (Choose with numbers)")

print('(1) Print out the sequence for an integer\n'
      '(2) Count the number of iterations (and by you I mean the computer)\n'
      'and export the results to "output.csv"')

while True:
    try:
        optionSelected = int(input())
        break
    except ValueError:
        print("Please don't break me, enter an actual number")

if optionSelected == 1:
    cM.printEachStep()
elif optionSelected == 2:
    cM.iterations()
else:
    print("Congratulations, you've found the hidden calculation modules that don't yet exist. Check in later and maybe we'll have something for you!")

raise SystemExit
