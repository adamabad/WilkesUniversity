// File: Sphere.java
// Date: January 25, 2018
// Author: Adam Abad
// Purpose: To calculate the surface area and volume of a
//          sphere

import java.util.*;

public class Sphere
{
    public static void main(String args[])
    {
	//Intro
	System.out.println();
	System.out.println("Program to calculate the surface area");
	System.out.println("and volume of a sphere.");
	System.out.println("Written by Adam Abad.");
	System.out.println("You will be asked to enter the radius" +
			   " of the sphere.");
	System.out.println();

	//Declaring Variables and Scanner
	double rad, surfaceA, volume;
	Scanner theKeyboard = new Scanner(System.in);

	//Input
	System.out.print("Enter Radius: ");
	rad = theKeyboard.nextDouble();
	System.out.println(); //forturnin
	System.out.println();

	//Calculations
	surfaceA = 4. * Math.PI * rad * rad;
	volume = (4. / 3.) * Math.PI * rad * rad * rad;

	//Output
	System.out.println("A sphere with a radius of " + rad +
			   " has:");
	System.out.println();
	System.out.println("Surface Area: " + surfaceA);
	System.out.println("      Volume: " + volume);
	System.out.println();
    }
}
	
