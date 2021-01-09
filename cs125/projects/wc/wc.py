# File: wc.py
# Date: October 4, 2017
# Author: Adam Abad
# Purpose: To count the lines, words, and bytes in a file

def main():
    
    print()
    print("Program to print the number of newlines,")
    print("words and characters in a file")
    print("You will be asked to enter the name of a file.")
    print("Written by Adam Abad.")
    print()

    infileName = input("Enter the name of a file: ")
    print() #forturnin
    print()

    infile = open(infileName,"r")

    lineCount = 0 
    wordCount = 0
    charCount = 0
    
    for lines in infile:
        lineCount = lineCount + 1
        wordCount = wordCount + 1 #Counts word at end of each line
        
        for char in lines:
            charCount = charCount + 1
            
            if char == " ":
                wordCount = wordCount + 1
                
    infile.close()
    print(lineCount,wordCount,charCount,infileName)
    print()
    
main()
        
