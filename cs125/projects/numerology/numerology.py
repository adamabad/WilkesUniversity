# File: numerology.py
# Date: September 20, 2017
# Author: Adam Abad
# Purpose: To find the numeric value of a name by adding each
#          character's individual value

def main():

    print()
    print("Program to calculate the numeric value of a name.")
    print("You will be asked to enter a name.")
    print("Written by Adam Abad.")
    print()

    name = input("Enter a name: ")
    print() #Enter for turnin
    print()
    numTotal = 0
    caseLower = name.lower()
    for char in caseLower:    
        letterNum = ord(char) 
        if letterNum>=97 and letterNum<=122:
            #Doesnt compare spaces or special charcaters
            numerologyNum = letterNum - 96
            numTotal = numTotal + numerologyNum
            
    print("Original name:",name)
    print("Numeric value:",numTotal)
    print()
    
main()
