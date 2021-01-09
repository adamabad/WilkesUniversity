// File: Chill.java
// Date: Febuary 13, 2018
// Author: Adam Abad
// Purpose: To display how dangerous an entered wind chill is
//          using methods

import java.util.*;

public class Chill
{
    
    public static String condition(int chillValue)
    {
	if(chillValue >= 10)
	    return "is not considered dangerous or unpleasant";
	if(chillValue >= -10)
	    return "is considered unpleasant";
	if(chillValue >= -30)
	    return "frostbite is possible";
	if(chillValue >= -70)
	    return "frostbite is likely and outdoor activity" +
		" becomes dangerous";
	return "means \nexposed flesh will usually freeze within" +
	    " half a minute";
	// \n for line enter split within string
    }
    
    public static void main(String args[])
    {
	Scanner sc = new Scanner(System.in);
	//Intro
	System.out.println();
	System.out.println("Program to calculate the condition of a " +
			   "group of wind chills.");
	System.out.println("Written by Adam Abad.");
	System.out.println("You will be asked to enter the number of" +
			   " wind chills,");
	System.out.println("followed by the value of each wind chill.");
	System.out.println();

	//Inputs
	int numChills;
	double totalChill = 0;
	System.out.print("Enter the number of wind chills: ");
	numChills = sc.nextInt();
	System.out.println();
	System.out.println(); //ForTurnin

	if(numChills > 0)
	{
	    //ForLoop
	    for(int chillNum = 1; chillNum <= numChills; chillNum++)
	    {
		int chillValue;
		System.out.print("Enter the value of wind chill " +
			     chillNum + ": ");
		chillValue = sc.nextInt();
		System.out.println(); //forTurnin
		totalChill = totalChill + chillValue;
		String condition = condition(chillValue);
		String message = "A wind chill of " + chillValue +
		    " " + condition;
		System.out.println(message);
		System.out.println();
	    }
	
	    //Ending Output
	    double averageChill = totalChill / numChills;
	    System.out.printf("The average of the " + numChills +
			  " wind chills is %1.3f", averageChill);
	    System.out.println();
	    System.out.println();
	}
	else
	{
	    System.out.println("Number of wind chills must be " +
			       "greater than 0, not " + numChills);
	    System.out.println();
	}
    }
    
}
