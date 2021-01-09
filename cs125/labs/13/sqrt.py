# File: sqrt.py
# Date: December 5, 2017
# Author: Adam Abad
# Purpose: To use Newton's Method to approximate square roots

from math import *

def intro():

    print()
    print("This program will calculate the square root")
    print("of a number using Newton's Method.")
    print("You will enter the number and the size of the")
    print("delta between Newton's Method square root")
    print("and the real square root.")
    print("Written by Adam Abad.")
    print()
    
def getInputs():

    number = float(input("Enter the number to find its square root: "))
    print() #forturnin
    delta = float(input("Enter the delta: "))
    print() #forturnin
    print()
    return number, delta

def calcSqrt(number, delta):

    tries = 0
    guess = 1
    while True:
        
        newGuess = (guess + number / guess) / 2
        tries = tries + 1
        if abs(guess - newGuess) <= delta:
            break
        guess = newGuess
    return tries, newGuess

def output(number,calcResult):
    
    actual = sqrt(number)
    difference = abs(actual - calcResult)
    print("The calculated square root is",calcResult)
    print("The real square root is      ",actual)
    print("The difference is            ",difference)
    
def main():

    intro()
    number, delta = getInputs()
    tries, calcResult = calcSqrt(number, delta)
    print("For the square root of", number, "after", tries, "tries")
    print("with a delta of", str(delta) + ":")
    output(number,calcResult)
    print()

if __name__ == "__main__": main()
    
    
