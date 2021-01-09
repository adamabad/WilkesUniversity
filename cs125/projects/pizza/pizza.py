# File: pizza.py
# Date: September 27, 2017
# Author: Adam Abad
# Purpose: To calculate the size and price of a pizza
#          givin a diameter input

import math
def main():

    print()
    print("Program to calculate the area and cost")
    print("per square inch of pizza.")
    print("You will be asked to enter the diameter")
    print("of the pizza in inches and the cost in dollars.")
    print("Written by Adam Abad.")
    print()

    diam = float(input("Enter the diameter (in inches): "))
    print() #forturnin
    print()
    price = float(input("Enter the cost (in dollars): "))
    print() #forturnin
    print()

    if diam % 1 == 0: #Collin Helped me here for formating float outputs
        diam = int(diam)
        
    radius = diam / 2
    area = math.pi * (radius ** 2)
    costPerinch = price / area

    print("For a diameter of",diam,"inches")
    print("and a cost of ${0:0.2f}".format(price)+":")
    print("Area in square inches: {0:0.3f}".format(area))
    print("Cost per square inch:  ${0:0.2f}".format(costPerinch))
    print()
    
main()
