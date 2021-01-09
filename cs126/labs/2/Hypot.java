//Hypot.java computes the hypotenuse length of a right triangle,
//  given the lengths of its two legs.
//
// Author: Adam Abad
// Date: January 23, 2018
// For: CS126
//
// Specification:
//   input(keyboard):
//   output(screen):
// ***************************************************************

import java.util.*;

public class Hypot
{
    public static void main(String args[])
    {
	System.out.println();
	System.out.println("Given two right triangle leg lengths,");
	String s2;
	s2 = "this program computes the hypotenuse length.";
	System.out.println(s2);
	System.out.println("Written by Adam Abad.");
	System.out.println();

	// get two sides
	Scanner theKeyboard = new Scanner(System.in);
	double leg1, leg2;

	System.out.print("Enter the length of side 1: ");
	leg1 = theKeyboard.nextDouble();
	System.out.println(); //forturnin
	
	System.out.print("Enter the length of side 2: ");
	leg2 = theKeyboard.nextDouble();
	System.out.println(); //forturnin
	System.out.println();

	double hypotenuse = Math.sqrt(Math.pow(leg1, 2.0) +
				      Math.pow(leg2, 2.0));
	
	// output results
	String s3;
	s3 = "For a triangle with sides " + leg1;
	s3 = s3 + " and " + leg2;
	
	System.out.println(s3);
	String s4 = "The hypotenuse is ";
	System.out.print(s4);
	System.out.printf("%.3f", hypotenuse);
	System.out.println();
	System.out.println();
	
    } // end of main
}
