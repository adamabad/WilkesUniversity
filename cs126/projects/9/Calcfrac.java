// File: Calcfrac.jaca
// Date: April 2, 2018
// Author: Adam Abad
// Purpose: To extend the fraction class to other operations
//       involving fractions.

import java.util.*;

public class Calcfrac
{
    static final String MENU = "Please enter an operation:\n" +
	"        1, for add;\n" +
	"        2, for subtract;\n" +
	"        3, for multiply;\n" +
	"        4, for divide;\n" +
	"        5, for less than;\n" +
	"        6, for less than or equal to;\n" +
	"        7, for equal to;\n" +
	"        8, for greater than;\n" +
	"        9, for greater than or equal to;\n" +
	"        0, to stop;\n" +
	"--> ";

    static Scanner sc = new Scanner(System.in);
    
    public static void main(String args[])
    {
	//Intro
	System.out.println();
	System.out.println("Program to calculate operations on fractions.");
	System.out.println("Written by Adam Abad.");
	System.out.println();

	//Calc Loop
	while(true)
	{
	    int choice = getInt();
	    if(choice == 0) break;
	    
	    System.out.print("Enter first fraction:  ");
	    Fraction leftOperand = new Fraction();
	    leftOperand.read(sc);
	    System.out.println(); //For Turnin

	    System.out.print("Enter second fraction: ");
	    Fraction rightOperand = new Fraction();
	    rightOperand.read(sc);
	    System.out.println(); //For Turnin

	    System.out.println();
	    calculate(choice, leftOperand, rightOperand);
	    System.out.println();
	    
	}
	System.out.println();
    }
    public static int getInt()
    {
	int choice;
	while(true)
	{
	    System.out.print(MENU);
	    if(sc.hasNextInt())
	    {
		choice = sc.nextInt();
		System.out.println(); //For Turnin
		if((choice >= 0) && (choice <= 9))
		    break;
		else
		    System.out.println("Choice must be between " +
				       "0 and 9, not " + choice);
		System.out.println(); //For Turnin
	    }
	    else
	    {
		String junk = sc.nextLine();
		System.out.println(); //For Turnin
		System.out.println("Error, value must be an integer, " +
				   "not, " + junk);
		System.out.println();
	    }
	}
	    String junk = sc.nextLine();
	    return choice;
    }
    
    public static void calculate(int choice, Fraction left, Fraction right)
    {
	Fraction result;
	boolean logicResult;
	switch(choice)
	{
	case 1:
	    result = left.addition(right);
	    System.out.println(left + " + " + right
			       + " is " + result);
	    break;
	case 2:
	    result = left.subtraction(right);
	    System.out.println(left + " - " + right
			       + " is " + result);
	    break;
	case 3:
	    result = left.times(right);
	    System.out.println(left + " * " + right
			       + " is " + result);
	    break;
	case 4:
	    result = left.divide(right);
	    System.out.println(left + " / " + right
			       + " is " + result);
	    break;
	case 5:
	    logicResult = left.less(right);
	    System.out.println(left + " < " + right
			       + " is " + logicResult);
	    break;
	case 6:
	    logicResult = left.lessEqual(right);
	    System.out.println(left + " <= " + right
			       + " is " + logicResult);
	    break;
	case 7:
	    logicResult = left.equalTo(right);
	    System.out.println(left + " == " + right
			       + " is " + logicResult);
	    break;
	case 8:
	    logicResult = left.greater(right);
	    System.out.println(left + " > " + right
			       + " is " + logicResult);
	    break;
	case 9:
	    logicResult = left.greaterEqual(right);
	    System.out.println(left + " >= " + right
			       + " is " + logicResult);
	    break;
	default:
	    System.out.println("Error in choice selection.");
	}
    }
}
