# File: sqrt2.py
# Date: November 9, 2017
# Author: Adam Abad
# Purpose: To approximate sqrt of 1 + x using infinte series

from math import *

def intro():
    print()
    print("Program to approximate the square root of 1 + x.")
    print("(|x| must be less than 1)")
    print("You will be asked to enter the value of x and")
    print("the number of terms.")
    print("Written by Adam Abad")
    print()
    
def getValue():
    number = float(input("Enter the value of x (|x| < 1): "))
    print() #forturnin
    return number

def getTerms():
    terms = int(input("Enter the number of terms to use: "))
    print() #forturnin
    print()
    return terms

def factorial(factNumber):
    factor = 1
    for factLoop in range(1,factNumber + 1):
        factor = factor * factLoop
    return factor

def rootMain(loopTerm,number):
    factTop = factorial(2 * loopTerm)
    factBot = factorial(loopTerm) ** 2
    #(-1)^n * (2 * n)!
    equatTop = ((-1) ** loopTerm) * factTop
    #(1-2n) * n!^2 * 4^n
    equatBot = (1 - 2 * loopTerm) * factBot * (4 ** loopTerm)
    # sigma + equat * x^n
    final = (equatTop / equatBot) * (number ** loopTerm)
    return final

def actual(number):
    actualRoot = sqrt(1 + number)
    return actualRoot
    
def output(sigma,actualRoot,differ):
    print("sqrt(1+x)"+
          "{0:17.12f}{1:17.12f}{2:17.12f}".format(sigma,actualRoot,differ))
    
def main():
    intro()
    number = getValue()
    if abs(number) < 1:
        terms = getTerms()
        sigma = 0
        for loopTerm in range(terms):
            sigma = sigma + rootMain(loopTerm,number)

        print("For",terms,"terms and x is "+str(number)+":")
        print()
        print("Function    Approx. Value    Actual Value    Difference")
        actualRoot = actual(number)
        differ = sigma - actualRoot
        output(sigma,actualRoot,differ)
        
    else:
        print("You entered", str(number)+". which is not within the range.")
    
    print()     
main()
