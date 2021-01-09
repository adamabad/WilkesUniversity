# File: checkerboard.py
# Date: November 14, 2017
# Author: Adam Abad
# Purpose: To make a checkerboard based on a user's input

def intro():
    
    print()
    print("This program will display a checkerboard.")
    print("You will enter the number of rows, columns,")
    print("block size and the checkerboard character.")
    print("Written by Adam Abad.")
    print()
    
def getInputs():

    rows = int(input("How many rows? "))
    print() #forturnin
    columns = int(input("How many columns? "))
    print() #forturnin
    blockSize = int(input("What is the block size? "))
    print() #forturnin
    grid = input("What is the checkerboard character? ")
    print() #forturnin
    print()
    return rows, columns, blockSize, grid

def checkerboard(rows, columns, blockSize, grid):

    for i in range(rows):
        if i % 2 == 0:
            writeRow(columns, blockSize, grid)
        else:
            writeRowIndented(columns, blockSize, grid)

def writeRow(columns, blockSize, grid):

    line = ""
    for c in range(columns):
        if c % 2 == 0:
            line = line + blockSize * grid
        else:
            line = line + blockSize * " "
    for b in range(blockSize):
        print(line)
    
def writeRowIndented(columns, blockSize, grid):

    line = ""
    for c in range(columns):
        if c % 2 == 1:
            line = line + blockSize * grid
        else:
            line = line + blockSize * " "
    for b in range(blockSize):
        print(line)
    
def main():
    
    intro()
    rows, columns, blockSize, grid = getInputs()
    checkerboard(rows, columns, blockSize, grid)
    print()
    
main()
