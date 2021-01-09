// File: Sketch.java
// Date: Febuary 22, 2018
// Author: Adam Abad
// Purpose: To create and display a face based on
//         a user's input.

import java.util.*;
import java.io.*;

public class Sketch
{
    static Scanner theKeyboard = new Scanner(System.in);

    static final String HAIR_MENU = "Please enter a hairstyle:\n" +
	"        1, for bald;\n" +
	"        2, for crew-cut;\n" +
	"        3, for curly;\n" +
	"        4, for wearing a hat;\n" +
	"-->";

    static final String EYE_MENU = "Please enter eye choice:\n" +
	"        1, for beady;\n" +
	"        2, for bug-eyed;\n"+
	"        3, for glasses;\n" +
	"        4, for closed;\n" +
	"-->";

    static final String NOSE_MENU = "Please enter nose choice:\n" +
	"        1, for pug;\n" +
	"        2, for small;\n" +
	"        3, for medium;\n" +
	"        4, for large;\n" +
	"-->";

    static final String MOUTH_MENU = "Please enter mouth choice:\n" +
	"        1, for puzzled;\n" +
	"        2, for smiling;\n" +
	"        3, for bearded;\n" +
	"        4, for frowning;\n" +
	"-->";

    public static void main(String args[])
    {
	intro();
	int hairChoice, eyeChoice, noseChoice, mouthChoice;
;
	hairChoice = getInt(HAIR_MENU);
	System.out.println();

	eyeChoice = getInt(EYE_MENU);
	System.out.println();

	noseChoice = getInt(NOSE_MENU);
	System.out.println();

	mouthChoice = getInt(MOUTH_MENU);
	System.out.println();

	printHair(hairChoice);
	printEye(eyeChoice);
	printNose(noseChoice);
	printMouth(mouthChoice);
	
	System.out.println();
    }

    public static void intro()
    {
	System.out.println();
	System.out.println("Program to sketch a suspect.");
	System.out.println("You will be asked to choose a " +
			   "hairstyle, nose type,");
	System.out.println("eye type and mouth type. Then " +
			   "your sketch will be made.");
	System.out.println("Written by Adam Abad.");
	System.out.println();
    }

    public static int getInt(String currentMenu)
    {
	int choice;
	while(true)
	{
	    System.out.print(currentMenu);
	    if(theKeyboard.hasNextInt())
	    {
		choice = theKeyboard.nextInt();
		System.out.println(); //For Turnin
		if((choice >= 1) && (choice <= 4))
		    break;
		else
		    System.out.println("Choice must be" +
				   " between " +
				   "1 and 4, not " + choice);
		System.out.println(); //For Turnin
	    }
	    else
	    {
		String junk = theKeyboard.nextLine();
		System.out.println(); //For Turnin
		System.out.println("Error, value must be an " +
				   "integer," +
				   " not " + junk);
	    }	
	}
	String junk = theKeyboard.nextLine();
	return choice;
    }
    
    public static void printHair(int choice)
    {
	switch(choice)
	{
	case 1: //Bald
	    System.out.println();
	    System.out.println(" .......");
	    System.out.println(" .     .");
	    break;
	case 2: //CrewCut
	    System.out.println();
	    System.out.println("\\|||||||/");
	    System.out.println(" |     |");
	    break;
	case 3: //Curly
	    System.out.println("   cCc");
	    System.out.println(" cCCCCCc");
	    System.out.println(" c     c");
	    break;
	case 4: //Hat
	    System.out.println(" -----");
	    System.out.println(" |     |");
	    System.out.println("_________");
	    break;
	default:
	    System.out.println();
	    System.out.println("Error Displaying Hair ("+
				   "Choice: " + choice + ")");
	    System.out.println();
	}    
    }
    
    public static void printEye(int choice)
    {
	switch(choice)
	{
	case 1: //beady
	    System.out.println("(| . . |)");
	    break;
	case 2: //bug-eyed
	    System.out.println("(| O O |)");
	    break;
	case 3: //glasses
	    System.out.println("(|-o-o-|)");
	    break;
	case 4: //closed
	    System.out.println("(| _ _ |)");
	    break;
	default:
	    System.out.println("Error Displaying Eyes ("+
				   "Choice: " + choice + ")");
	}    
    }
    
    public static void printNose(int choice)
    {
	switch(choice)
	{
	case 1: //pug
	    System.out.println(" |  ^  |");
	    break;
	case 2: //small
	    System.out.println(" |  .  |");
	    break;
	case 3: //medium
	    System.out.println(" |  >  |");
	    break;
	case 4: //large
	    System.out.println(" |  _\\ |");
	    break;
	default:
	    System.out.println("Error Displaying Nose ("+
				   "Choice: " + choice + ")");
	}
    }

    public static void printMouth(int choice)
    {
	switch(choice)
	{
	case 1: //puzzled
	    System.out.println(" | --- |");
	    System.out.println("  -----");
	    System.out.println();
	    break;
	case 2: //smiling
	    System.out.println(" |\\___/|");
	    System.out.println("  -----");
	    System.out.println();
	    break;
	case 3: //bearded
	    System.out.println(" |||-|||");
	    System.out.println("  |||||");
	    System.out.println("   |||");
	    break;
	case 4: //frowning
	    System.out.println(" |  ^  |");
	    System.out.println("  -----");
	    System.out.println();
	    break;
	default:
	    System.out.println("Error Displaying Mouth ("+
				   "Choice: " + choice + ")");
	}
    }
}
