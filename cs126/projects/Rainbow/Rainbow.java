// File: Rainbow.java
// Date: January 30, 2018
// Author: Adam Abad
// Purpose: To calculate the hight of a rainbow
//          given a user's distance away from it

import java.util.*;

public class Rainbow
{    
    public static void main(String args[])
    {
	intro();
        double distance, height;
	distance = getDistance();
	if(distance <= 0)
	    {
		System.out.println(distance + " is less" +
			       " than zero, unable to " +
			       "calculate the distance.");
	    }
	else
	    {
		height = calcHeight(distance);
		printOutput(height, distance);
	    } //comparison
	
	System.out.println();
    } //main
    
    public static void intro()
    {
	System.out.println();
	System.out.println("Program to calculate the height" +
			   " of a rainbow.");
	System.out.println("Program checks that the distance" +
			   " is greater");
	System.out.println("than zero.");
	System.out.println("Written by Adam Abad.");
	System.out.println("You will be asked to enter the" +
			   " distance to the rainbow.");
	System.out.println();
    }

    public static double getDistance()
    {
	Scanner theKeyboard = new Scanner(System.in);
	System.out.print("Enter distance: ");
	double distance;
	distance = theKeyboard.nextDouble();
	//forturnin
	System.out.println();
	System.out.println();
	return distance;
    }

    public static double calcHeight(double distance)
    {
	double radians, tanAngle, height;
	radians = 42.3333333 * Math.PI / 180;
	tanAngle = Math.tan(radians);
	height = tanAngle * distance;
	return height;
    }

    public static void printOutput(double height, double distance)
    {
	System.out.println("Given that the distance to the" +
			   " rainbow is " + distance + ":");
	System.out.println();
	System.out.println("The height of the rainbow is:  " +
			   height);
    }
}
