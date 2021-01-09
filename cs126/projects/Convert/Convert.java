// File: Convert.java
// Date: Febuary 6, 2018
// Author: Adam Abad
// Purpose: To use methods to convert units

import java.util.Scanner;

public class Convert
{
    public static void main(String args[])
    {
	Scanner theKeyboard = new Scanner(System.in);
	double num, meters, sqMm, sqMeters, acreSqMeters;

	//Intro
	System.out.println();
	System.out.println("Program to convert units.");
	System.out.println("Written by Adam Abad.");
	System.out.println("You will be asked to enter one" +
			   " number.");
	System.out.println();

	//Input
	System.out.print("Enter a number: ");
	num = theKeyboard.nextDouble();
	//Forturnin
	System.out.println();
	System.out.println();

	//Conversions
	meters = Metric.feetToMeters(num);
	sqMm = Metric.sqInchToSqMm(num);
	sqMeters = Metric.sqFeetToSqMeters(num);
	acreSqMeters = Metric.acresToSqMeters(num);
	
	//Output
	System.out.println(num + " feet = " + meters + " meters");
	System.out.println(num + " square inches = " + sqMm +
			   " square millimeters");
	System.out.println(num + " square feet = " + sqMeters +
			   " square meters");
	System.out.println(num + " acres = " + acreSqMeters +
			   " square meters");
	System.out.println();
    }
}
