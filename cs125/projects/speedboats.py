# File: speedboats.py
# Date: November 30, 2017
# Author: Adam Abad
# Purpose: To display a table for a given set of data

def intro():

    print()
    print("Program to output a monthly report of speedboat sales.")
    print("Written by Adam Abad.")
    print()

def getFile():

    infileName = input("Enter the file name: ")
    print() #forturnin
    print()
    print("For the file", infileName + ":")
    print()
    infile = open(infileName, "r")
    return infile

def getData(infile):

    mainList = []
    for line in infile:
        list = line.split()
        row = []
        for num in list:
            row.append(int(num))
        mainList.append(row)
    return mainList

def makeTable(mainList):

    print("                    Salesperson")
    print("  Model  :   1   2   3   4   5   6   7   8  :  Avg Totals")
    print("---------------------------------------------------------")

    for model in range(1, len(mainList) + 1):
        modelTotal = 0
        print("{0:^9d}:".format(model),end='')

        for sales in mainList[model - 1]: # -1 to start at 0 from model
            print("{0:4d}".format(sales),end='')
            modelTotal = modelTotal + sales
        
        modelAverage = modelTotal / 8
        print("  : {0:^5.1f} {1:^5d}".format(modelAverage,modelTotal))

    print("---------------------------------------------------------")

    averageString = ""
    maxString = ""
    totalString = ""
    absTotal = 0
    
    for salesPerson in range(len(mainList[0])):

        salesTotal = 0
        maxSale = 0
        
        for modelsSold in mainList:
            salesTotal = salesTotal + modelsSold[salesPerson]
            num = modelsSold[salesPerson]
            if num > maxSale:
                maxSale = num
        SalesAverage = salesTotal / 10
        averageString = averageString + "{0:4.1f}".format(SalesAverage)
        maxString = maxString + "{0:4d}".format(maxSale)
        totalString = totalString + "{0:4d}".format(salesTotal)
        absTotal = absTotal + salesTotal

    print("Average  :" + averageString)
    print("Maximum  :" + maxString)
    print(" Totals  :" + totalString,end='')
    print("  :{0:10d}".format(absTotal))
    
def main():

    intro()
    infile = getFile()
    mainList = getData(infile)
    infile.close()
    makeTable(mainList)
    print()
main()
