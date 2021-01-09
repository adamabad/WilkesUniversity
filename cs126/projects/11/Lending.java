// File: Lending.java
// Date: April 10, 2018
// Author: Adam Abad
// Purpose: To keep track of books in and out of a library

import java.util.*;
import java.io.*;

public class Lending
{    
    static final String MENU = "Please enter a number:\n"
	                     + "        1, for checking a book out;\n"
	                     + "        2, for returning a book;\n"
	                     + "        0, to exit and print list;\n"
	                     + "--> ";

    static Scanner theKeyboard = new Scanner(System.in);
    static ArrayList <CheckOut> currentBooks = new ArrayList <CheckOut>();
    
    public static void main(String args[])
    {
	System.out.println();
	intro();
	System.out.println();

	//Getting File
	System.out.print("Enter the name of input file: ");
	String fileName = theKeyboard.nextLine();
	Scanner theFile = null;
	try
	{
	    theFile = new Scanner(new File(fileName));
	}
	catch (FileNotFoundException e)
	{
	    System.err.println("File " + fileName + " not found.");
	    System.out.println();
	    System.exit(1);
	}	
	loadList(theFile);
	System.out.println(); //For Turnin
	System.out.println();
	//Main indef. Loop
	while(true)
	{
	    int choice = getInt();
	    System.out.println();
	    if(choice == 0) break;
	    switch(choice)
	    {
	    case 1:
		bookOut();
		break;
	    case 2:
		bookReturn();
		break;
	    default:
		System.out.println("Error: Choice not supported: " +
				   choice);
	    }
	} //while end

	currentList();
	outputFile(fileName);
    }

    public static void bookOut()
    {
	System.out.print("Enter 3 digit patron code: ");
	int codeOut = theKeyboard.nextInt();
	System.out.println(); //For Turnin
	System.out.print("Enter 10 letter book description: ");
	String bookOut = theKeyboard.next();
	System.out.println();
	System.out.println(); //For Turnin
	int patronCount = 0;
	boolean outCheck = true;
	for(int x = 0; x < currentBooks.size(); x++)
	{
	    if(currentBooks.get(x).getBook().equals(bookOut))
	    {
		System.out.println(bookOut +
				   " is currently out with patron #" +
				   currentBooks.get(x).getPatron()
				   + ", unable to check out");
		System.out.println();
		outCheck = false;
		break;
	    }
	    if(currentBooks.get(x).getPatron() == codeOut)
	    {
		patronCount++;
		if(patronCount >= 3)
		{
		    System.out.println("Patron " + codeOut +
				       " currently has " + patronCount +
				       " books out, unable to check out.");
		    System.out.println();
		    outCheck = false;
		    break;
		}
	    }
	}
	if(outCheck)
        {
	    currentBooks.add(new CheckOut(codeOut,bookOut));
	}
    }

    public static void bookReturn()
    {
	System.out.print("Enter 3 digit patron code: ");
	int codeIn = theKeyboard.nextInt();
	System.out.println(); //For Turnin
	System.out.print("Enter 10 letter book description: ");
	String bookIn = theKeyboard.next();
	System.out.println();
	System.out.println(); //For Turnin

	for(int x = 0; x < currentBooks.size(); x++)
	{
	    if(currentBooks.get(x).getBook().equals(bookIn))
		if(currentBooks.get(x).getPatron() == codeIn)
		{
		    currentBooks.remove(x);
		    break;
		}
		else
	        {
		    System.out.println("Error: Patron ID does not match " +
				       "current book's patron, unable " +
				       "to return book.");
		    break;
		}
	}
    }

    public static void currentList()
    {
	System.out.println("Lender  Book Desc.  Time");
	System.out.println("======  ==========  ====");
	for(int x = 0; x < currentBooks.size(); x++)
	{
	    int newPatron = currentBooks.get(x).getPatron();
	    String newBook = currentBooks.get(x).getBook();
	    long newTime = currentBooks.get(x).getTime();
	    System.out.printf(" %3d    %-10s  %d",newPatron,newBook,
			      newTime);
	    System.out.println();
	}
	System.out.println();
    }
    
    public static void loadList(Scanner theFile)
    {
	while(theFile.hasNext())
	{
	    int code = theFile.nextInt();
	    String book = theFile.next();
	    long time = theFile.nextLong();
	    
	    currentBooks.add(new CheckOut(code,book,time));
	}
    }

    public static void outputFile(String fileName)
    {
	BufferedWriter outStream = null;
	try
	{
	    outStream = new BufferedWriter(new FileWriter(fileName));
	}
	catch (IOException ex)
	{
	    System.err.println("Failed to open output file named " +
			       fileName);
	    System.exit(1);
	}

	for(int x = 0; x < currentBooks.size(); x++)
	{
	    String outLine = currentBooks.get(x).getPatron() + " " +
		currentBooks.get(x).getBook() + " " +
		currentBooks.get(x).getTime() + "\n";
	    try
	    {
		outStream.write(outLine);
	    }
	    catch (IOException ex)
	    {
		System.err.println("Failed to output to file named " +
				   fileName);
		System.exit(1);
	    }
	}
	try
	{
	    outStream.close();
	}
	catch (IOException ex)
        {
	    System.err.println("Unable to close file.");
	    System.exit(1);
	}
    }
    
    public static int getInt()
    {
	int choice;
	while(true)
	{
	    System.out.print(MENU);
	    if(theKeyboard.hasNextInt())
	    {
		choice = theKeyboard.nextInt();
		System.out.println(); //For Turnin
		if((choice >= 0) && (choice <= 2))
		    break;
		else
		    System.out.println("Choice must be 0, 1, or 2, " +
				       "not: " + choice);
	    }
	    else
	    {
		String junk = theKeyboard.nextLine();
		System.out.println(); //For Turnin
		System.out.println("Error: Value must be an integer," +
				   " not: " + junk);
	    }
	}
	String junk = theKeyboard.nextLine();
	return choice;
    }
    
    public static void intro()
    {
        System.out.println("Program to keep track of library books.");
        System.out.println("You will enter the name of a file.");
        System.out.println("The program will read this file as the list");
        System.out.println("of books already checked out." +
			   " You will then enter");
	System.out.println("a lender code followed by a book" +
			   " description to");
	System.out.println("check out or return a book.");
	System.out.println("When the program is done, it" +
			   " will write out the");
	System.out.println("current list of checked out books to the"
			   + " original file");
	System.out.println("and print a list of the checked out books.");
	System.out.println("Written by Adam Abad.");
    }
    
}
