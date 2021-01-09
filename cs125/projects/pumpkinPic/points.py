# File: points.py
# Author: John Koch
# Date modified: 3/11/2014
# Further modification: 10/8/2015
# Purpose: to open an image and be able to click on points of the image
# to create the code for a Polygon.
# Click on the "Stop" box to the top left side of the window to stop creating points
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
    
#    import Image to the middle of the window
    graphic = Image(Point(winWidth/2, winHeight/2),"pumpkin.gif")
    graphic.draw(win)
    
# 	Stop box
    stop = Rectangle(Point(5,5), Point(30,20))
    stop.setFill("red")
    stop.draw(win)
    stoptext = Text(stop.getCenter(), "Stop")
    stoptext.setOutline("white")
    stoptext.draw(win)


#
    s = ""
    while True:       #Attempting to generate an appended list of x,y coord.
        p = win.getMouse()
        if (p.getX() < 30) and (p.getY() < 20): break
        s = s + "Point("+str(p.getX())+ "," + str(p.getY()) + "), \n"
        
    print("Polygon(" + s[:-3] + ")")

    win.close()

## Sample use of output:
##    p = Polygon(Point(135,221), 
##    Point(136,221), 
##    Point(127,216), 
##    Point(120,214), 
##    Point(113,211), 
##    Point(114,205), 
##    Point(109,196), 
##    Point(118,188), 
##    Point(129,188), 
##    Point(134,193), 
##    Point(140,199), 
##    Point(142,210), 
##    Point(146,216), 
##    Point(138,221))
##
##    p.draw(win)

    
main()
