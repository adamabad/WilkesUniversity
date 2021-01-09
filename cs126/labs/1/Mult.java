// Mult.java demonstrates basic I/O in Java.
//
// Author:  Adam Abad.
// Date:    1/18/2018.
// Purpose: Lab 1 in CS126 at Wilkes University.
//
// Specification:
//   Input(keyboard): aNumber, an integer;
//   Output(screen): 2x, 4x and 8x aNumber.
//
 
import java.util.*;  // Scanner
 
public class Mult
{
	
	public static void main(String args[]) 
     {
                Scanner theKeyboard = new Scanner(System.in);
 
   		// 0. print a message explaining the purpose of the program.
		System.out.println();
		System.out.println("This program inputs an integer");
                System.out.println("        and displays 2x, 4x, and 8x its value.");

		// 1a. ask the user to enter an integer.
		System.out.println();
		System.out.print("Please enter an integer: ");
		// 1b.declare an integer container to hold the input number
		int aNumber;
		// 1c. input an integer, storing it in variable aNumber.
		aNumber = theKeyboard.nextInt();

		// 2. output 2x, 4x and 8x aNumber.
		System.out.println();
		System.out.println();
		System.out.println("Twice " + aNumber + " is "
				 + 2 * aNumber + ",");
		System.out.println("        and four times is "
				   + 4 * aNumber + ",");
		System.out.println("        and eight times is "
				   + 8 * aNumber);
		System.out.println();
	}
}
