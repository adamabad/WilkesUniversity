# File: bar.py
# Date: October 3, 2017
# Author: Adam Abad
# Purpose: To create a bar graph using given data

from graphics import *
from random import randrange

def main():
    print()
    print("Program to display a bar graph.")
    print("You will enter the name of a data file.")
    print("Written by Adam Abad.")
    print()

    filename = input("Enter the file name: ")
    infile = open(filename, "r")

    # read from the file
    vertAxisLabel = infile.readline()
    horizAxisLabel = infile.readline()
    
    vertAxisLabel = vertAxisLabel[:-1]
    horizAxisLabel = horizAxisLabel[:-1]

    totalValues = 0
    values = []

    for line in infile:
        if line != "\n":
            value = int(line)
            values = values + [value]
            totalValues = totalValues + 1

    infile.close()

    # print(values)

    winWidth = 600
    winHeight = 500
    graphWidth = 400
    graphHeight = 400
    topGap = 50
    leftGap = 150
    maxValue = 50

    win = GraphWin("Bar Graph", winWidth, winHeight)
    win.setBackground('white')

    p1 = Point(leftGap, topGap)
    p2 = Point(leftGap, topGap + graphHeight)
    p3 = Point(leftGap + graphWidth, topGap + graphHeight)

    vertAxis = Line(p1, p2)
    vertAxis.draw(win)
    horizAxis = Line(p2, p3)
    horizAxis.draw(win)

    #draw tic marks
    totalHashes = 5
    hashWidth = 10

    name = Text(Point(winWidth / 2, 20), "Adam Abad")
    name.draw(win)

    for k in range(totalHashes):

        x1Loc = leftGap - (hashWidth / 2)
        x2Loc = x1Loc + hashWidth

        y1Loc = topGap + graphHeight - 80 * (k + 1)
        y2Loc = y1Loc

        hashLine = Line(Point(x1Loc,y1Loc),Point(x2Loc,y2Loc))
        hashLine.draw(win)

        #hash label
        hashStr = str(10 * (k + 1))
        hashLabel = Text(Point(x1Loc - 20, y1Loc), hashStr)
        hashLabel.draw(win)

    #create the bars

    barSpace = int(graphWidth / totalValues)
    barWidth = 7 / 8 * barSpace

    for i in range(totalValues):
        x2Loc = leftGap + (i + 1) * barSpace
        x1Loc = x2Loc - barWidth

        y2Loc = topGap + graphHeight
        scaleValue = graphHeight / maxValue
        
        barHeight = scaleValue * min(maxValue, values[i])
        y1Loc = y2Loc - barHeight

        bar = Rectangle(Point(x1Loc,y1Loc),Point(x2Loc,y2Loc))
        bar.draw(win)

        # color the bars

        redVal = randrange(0,256)
        greenVal = randrange(0,256)
        blueVal = randrange(0,256)

        randomColor = color_rgb(redVal,greenVal,blueVal)
        bar.setFill(randomColor)

        # label the bars

        labelY = topGap + graphHeight + 20
        number = Text(Point((x1Loc + x2Loc) / 2, labelY), i + 1)
        number.draw(win)           
main()
