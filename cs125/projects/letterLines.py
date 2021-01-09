# File: letterLines.py
# Date: November 16, 2017
# Author: Adam Abad
# Purpose: To read and display contents of a file and copy it

def intro():

    print()
    print("Program to count letters in each line")
    print("in a file.")
    print("You will enter the name of a file.")
    print("The program will create an output file.")
    print("Written by Adam Abad.")
    print()

def getFile():

    infileName = input("Enter the name of input file: ")
    print() #forturnin
    infile = open(infileName,"r")
    return infile, infileName

def convertName(infileName):

    outfileNameSplit = infileName.split(".")
    outfileName = outfileNameSplit[0] + ".out"
    print("The name of output file is", outfileName)
    outfile = open(outfileName,"w")
    print()
    return outfile

def main():
    
    intro()
    infile, infileName = getFile()
    outfile = convertName(infileName)
    numList = [0,0,0,0,0,0,0,0,0,0]
    countUpper = 0
    countLower = 0
    lineNum = 0

    #Data input
    
    for lines in infile:
        lineNum = lineNum + 1
        letterinLine = 0
        for letter in lines:
            if letter >= "A" and letter <= "Z":
                countUpper = countUpper + 1
                letterinLine = letterinLine + 1
                
            if letter >= "a" and letter <= "z":
                countLower = countLower + 1
                letterinLine = letterinLine + 1

            if letter >= "0" and letter <= "9":
                num = int(letter)
                numList[num] = numList[num] + 1
        
        outline = str(letterinLine) + ": " + lines
        print(outline[:-1],file=outfile)
        
    infile.close()
    outfile.close()    
    #Data output
    print("Number of lines:{0:13}".format(lineNum))
    numCount = 0
    for number in numList:
        print("Number of",str(numCount)+"'s:{0:15}".format(number))
        numCount = numCount + 1
    print()
    
main()
