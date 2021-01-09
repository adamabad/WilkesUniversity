# PROGRAM:  distConvert.py
#
# AUTHOR:   Matt Zukoski
# MODIFIED BY: Adam Abad
#
# DATE:     Oct 31, 2017
#
# FOR:      CS 125 - Wilkes University
#
# PURPOSE:  Demonstrate the Tkinter library
#           for building GUI applications. This one
#           converts between Fahrenheit and Celsius
#           temperatures.
 
from tkinter import *
 
def main():
    global root, fTxt, cTxt
 
    # create a main root window (default size of 200 x 200)
    root = Tk()
 
    # the GUI will have a label and entry box on the top
    # for Fahrenheit, then a label and entry box below that
    # for Celsius, then a Convert button and Quit button
    # below that. We'll use the pack manager, so Frames
    # must be used to get the desired layout.
 
    # the Miles label and entry box go in f1
    f1= Frame(root)
    f1.pack(side=TOP)
 
    # the Kilometers label and entry box go in f2
    f2= Frame(root)
    f2.pack(side=TOP)
 
    # the Convert and Quit buttons go in f3
    f3= Frame(root)
    f3.pack(side=TOP)
 
    Label(f1, text="Miles:").pack(side=LEFT)
    fTxt = Entry(f1)
    fTxt.pack(side=LEFT)
    
    Label(f2, text="Kilometers:").pack(side=LEFT)
    cTxt = Entry(f2)
    cTxt.pack(side=LEFT)
 
    convertBtn = Button(f3, text="Convert", background="yellow")
    convertBtn.pack(side=LEFT)
 
    # associate the convertClick event handler to the
    # left-click event on the convertBtn button
    convertBtn.bind("<Button-1>", convertClick)
    
    quitBtn = Button(f3, text="Quit", background="cyan")
    quitBtn.pack(side=LEFT)
 
    # associate the quitClick event handler to the
    # left-click event on the quitBtn button
    quitBtn.bind("<Button-1>", quitClick)
 
    # the mainloop method is doing all the work for displaying
    # the window, detecting events, and calling event handlers
    root.mainloop()
 
# convertClick is the event handler for the convertBtn
# it's called when the user left-clicks in the button
 
def convertClick(event):
    # check which field is empty. If fTxt is empty, then
    # convert the cTxt entry to Miles. If the cTxt is
    # empty, then convert the fTxt entry to Kilometers
 
    fTempStr = fTxt.get()
    cTempStr = cTxt.get()
 
    if fTempStr == "":
        # convert Kilometers to Miles
        cTemp = float(cTempStr)
        fTemp = cTemp * .621371192
        fTxt.insert(0, str(fTemp))
    else:
        # if there is something in fTxt, convert Miles to
        # Kilometers (even if there is something in cTxt)
        fTemp = float(fTempStr)
        cTemp = fTemp / .621371192
        cTxt.delete(0, END)
        cTxt.insert(0, str(cTemp))
 
def quitClick(event):
    global root
 
    # kill the main root window and all of it's descendants
    # i.e. all the widgets on it
    root.destroy()
 
main()
