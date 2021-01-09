# File: easter.py
# Date: September 19, 2017
# Author: Adam Abad
# Purpose: To calculate the date of easter on a year input by a user

def main():
    #Test Cases: April 16, 2006; March 31, 2002; April 3, 1994
    print()
    print("This program will tell you the Easter date given a year.")
    print("Written by Adam Abad.")
    print()

    year = int(input("Please enter a year: "))
    print() #Turnin Enter
    print()

    A = year % 19
    B = year % 4
    C = year % 7
    D = ((19 * A) + 24) % 30
    E = ((2 * B) + (4 * C) + (6 * D) + 5) % 7
    easterDate = 22 + D + E

    if easterDate <= 31:
        print("Easter falls on March",easterDate,",",year,".")
    else:
        print("Easter falls on April",easterDate-31,",",year,".")
    print()
main()
