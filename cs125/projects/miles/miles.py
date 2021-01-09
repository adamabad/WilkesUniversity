# File: miles.py
# Date: September 12, 2017
# Author: Adam Abad
# Purpose: To produce a table of conversions from miles to kilometers, and
#          from kilometers to miles.

def main():

    print()
    print("Table of Miles and Kilometer Equivalents")
    print("Written by Adam Abad")
    print()
    
    print("Miles    Kilometers")
    print("=====    ==========")

    for i in range(0,101,10):
        miles = i
        kilometer = miles * 1.609344
        print(" ",miles,"M","  ",kilometer,"K")
    print()

    print("Kilometers    Miles")
    print("==========    =====")
    
    for z in range(0,101,10):
        kilometer = z
        miles = kilometer * 0.621371192
        print(" ",kilometer,"K",7*" ",miles,"M")
    print()
    
main()
