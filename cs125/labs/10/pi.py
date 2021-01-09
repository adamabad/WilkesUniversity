# File: pi.py
# Date: November 7, 2017
# Author: Adam Abad
# Purpose: To calculate pi using infinite series

import math

def intro():
    
    print()
    print("Program to calculate pi by 2 methods")
    print("Written by Adam Abad")
    print()
    
def getTerms():
    
    terms = int(input("How many terms would you like? "))
    print() #forturnin
    print()
    return terms
    
def main():
    
    intro()
    numTerms = getTerms()
    pi1 = 0
    pi2 = 0
    piReal = math.pi
    sign = 1  
    print("Pi by alternating sums    Pi by odd products")
    
    for term in range(1, numTerms + 1):

        #pi1 Calculations
        denom = term * 2 - 1
        value = 4.0 / denom * sign
        sign = sign * -1
        pi1 = pi1 + value

        #pi2 Calculations
        denomMain = term * 4
        denom2 = (denomMain - 3) * (denomMain - 1)
        value2 = 8.0 / denom2
        pi2 = pi2 + value2
        print("{0:10.6f}{1:27.6f}".format(pi1,pi2))
        
    print("For", numTerms ,"terms the difference is:")
    print("{0:10.6f}{1:27.6f}".format(pi1 - piReal, pi2 - piReal))
    print("The actual value of pi is {0:0.11f}".format(piReal))
    print()
    
main()
