#File: histo.py
#Date: December 7, 2017
#Author: Adam Abad
#Purpose: To construct a histogram for data in a file

from math import *

def intro():

    print()
    print("Program to print a histogram of scores.")
    print("It also produces the high, low, and average score")
    print("along with the standard deviation.")
    print("Written by Adam Abad.")
    print()

def getFile():

    infileName = input("Enter the name of the input file: ")
    print() #forturnin
    print()
    infile = open(infileName, "r")
    return infile

def makeList(file):
    
    mainList = []
    for line in file:
        mainList = mainList + line.split()
    return mainList

def calcScores(scores):

    numScores = []
    high = 0 #Number will always be higher than 0
    low = 100 #Number will always be lower than 100
    total = 0
    for scoreValue in range(1,len(scores),2):
        numScores = numScores + [int(scores[scoreValue])]
    for value in numScores:
        total = total + value
        if value < low:
            low = value
        if value > high:
            high = value
    average = total / len(numScores) #collin's idea

    #deviation calc
    sigma = 0
    for Dvalue in numScores:
        sigma = sigma + ((average - Dvalue) ** 2)
    denom = len(numScores) - 1
    standard = sqrt(sigma / denom)

    return low, high, average, standard, numScores

def output(scores):
    
    print("Name              Score")
    print("====              =====")
    print()
    for index in range(0,len(scores),2):
        print("{0:<12}{1:11.2f}".format(scores[index],float(scores[index + 1])))

def histogram(numScores,low,high):
    
    print("Histogram:")
    print("==========")
    print()
    numScores.sort()
    position = 0
    for histo in range(low,high+1):
        
        print("{0:4}".format(str(histo)+":"), end='')
        while numScores[position] == histo:
            print("*",end='')
            if len(numScores)-1 == position: #No list out of range @ last num
                break
            position = position + 1
            
        print()
    
def main():
    
    intro()
    file = getFile()
    scores = makeList(file)

    file.close()
    low, high, average, standard, numScores = calcScores(scores)
    print("Worst score:{0:13.2f}".format(low))
    print("Best score:{0:14.2f}".format(high))
    print("Average score:{0:11.2f}".format(average))
    print("Standard deviation:{0:6.2f}".format(standard))
    print()

    output(scores)
    print()
    histogram(numScores,low,high)
    print()
main()
