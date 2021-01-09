# File: points.py
# Author: John Koch
# Date modified: 3/11/2014
# Further modification: 10/8/2015
# Purpose: to open an image and be able to click on points of the image
# to create the code for a Polygon.
# Click close to the left side of the window to stop creating points
# and print the Polygon code.

# Added Stop box to end clicking

# Thanks to Robert Hildenbrand and Lyssa Scott for causing me to
# create this program

from graphics import *
from random import *


def main():
    
    # generate the graph
    winWidth = 500
    winHeight = 500        

    win = GraphWin("Create Polygon", winWidth, winHeight)
    win.setBackground("white")
    
    mouth = Polygon(Point(213,304), 
Point(213,306), 
Point(217,308), 
Point(219,313), 
Point(226,315), 
Point(227,310), 
Point(271,316), 
Point(271,323), 
Point(281,323), 
Point(282,317), 
Point(301,308), 
Point(298,321), 
Point(293,318), 
Point(288,320), 
Point(289,327), 
Point(241,327), 
Point(240,320), 
Point(232,320), 
Point(230,325), 
Point(220,320), 
Point(217,315), 
Point(216,310), 
Point(213,304))
    
    mouth.setFill("black")

    mouth.draw(win)

main()
