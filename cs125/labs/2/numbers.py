# File: numbers.py
# Date: 9/5/2017
# Author: Adam Abad
# Purpose: To write a program for CS 125

def main():
    print()
    number = int(input("Input a number: "))
    print()
    print("The original number is",number)
    a = number + 3
    b = a * 2
    c = b - 4
    d = c - (number * 2)
    e = d + 3
    print("The new number is",e)
    print()
main()
