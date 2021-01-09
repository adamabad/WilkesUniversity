//Encode.java allows its users to encode a message stored in a file//  using the Caesar cipher.//// The decoded message is stored in a file.////  Begun by: Charles Hoot, for Hands On Java.//  Adapted from code by: Joel C. Adams, for Hands On C++.//  Completed by: Adam Abad//  Date: April 10, 2018//  //  Specification://    input(input file):   a sequence of characters.//   output(output file): the sequence of encoded input characters.// *******************************************************************import java.io.*;public class Encode{	public static void main(String Args[])	{		BufferedReader  inStream = null;	BufferedWriter outStream = null;	// 0. Create theKeyboard	PrintStream theScreen = new PrintStream(System.out);	BufferedReader theKeyboard = new BufferedReader(					      new InputStreamReader(System.in));		// 1. Display introductory message	theScreen.println( "\nThis program uses the Caesar cipher to encode the contents of a"		+ "\nfile and writes the encoded characters to another file.");  	// 2. Prompt for and read name of the input file.	theScreen.print( "\nEnter the name of the input file: ");	String inFile=""; 	try	{	    inFile = theKeyboard.readLine();	}	catch (IOException e)	{	    System.err.println("Failed to read input file name");	    System.exit(1);	}	// 3. Open a BufferedReader named inStream for input from inFile	// 4. If inStream failed to open, display an error message and quit	try	{	    inStream = new BufferedReader(new FileReader(inFile));	}	catch (FileNotFoundException ex)	{	    System.err.println("Failed to open input file named " + inFile);	    System.exit(1);	}	// 5. Prompt for and read name of the input file.	System.out.print( "\nEnter the name of the output file: ");	String outFile=""; 	try{ 		outFile = theKeyboard.readLine();	} 	catch (IOException ex) {		System.err.println("Failed to read file name");		System.exit(1);	}	// 6. Open an BufferedWriter named outStream for output to outFile	// 7. If outStream failed to open, display an error message and quit	try	{	    outStream = new BufferedWriter(new FileWriter(outFile));	}	catch (IOException ex)	{	    System.err.println("Failed to open output file named " + outFile);	    System.exit(1);	}		int  inValue = 0;	char outChar=' ';  	// 8. Loop	while(true)	{		// a. read a character from the input file via inStream into inValue	    try	    {		inValue = inStream.read();	    }	    catch (IOException ex)	    {		System.err.println("Failed to read from input file " + inFile);		System.exit(1);	    }		// b. if end-of-file was reached, terminate repetition	    if(inValue == -1) break;		// c. encode the character using the Caesar cipher	    outChar = caesarEncode( (char) inValue, 3);      		// d. write the encoded character to the output file via outStream	    try	    {		outStream.write(outChar);	    }	    catch (IOException ex)	    {		System.err.println("Failed to write to output file " + outFile);		System.exit(1);	    }	}  	// 9a. close the connection to the input file	try	{	    inStream.close();	}	catch (IOException ex)	{	    System.err.println("Failed to close input file " + inFile);	    System.exit(1);	}	// 9b. close the connection to the output file  	try	{	    outStream.close();	}	catch (IOException ex)	{	    System.err.println("Failed to close output file " + outFile);	    System.exit(1);	}	// 10. display a 'successful completion' message	System.out.println("\nProcessing complete.\n Encoded message is in "+ outFile);	}	// *******************************************************************	// caesarEncode implements the Caesar cipher encoding scheme.        *	//                                                                   //	// Receive: ch, a character.                                         *	//          key, the amount by which to rotate ch.                   *	// Return:  The character that is key positions after ch,            *	//          with "wrap-around" to the beginning of the sequence.     *	//********************************************************************	public static char caesarEncode(char ch, int key)	{		final int FIRST_UPPER = (int) 'A',				FIRST_LOWER = (int) 'a',	            NUM_CHARS = 26;		if (key <= 0 || key >= NUM_CHARS)	    {			System.err.println("\n*** CaesarEncode: key must be between 1 and 25\n");			System.exit(1);	    }	  		if (Character.isUpperCase(ch))			return (char) ((ch - FIRST_UPPER + key) % NUM_CHARS + FIRST_UPPER);		else if (Character.isLowerCase(ch))			return (char) ((ch - FIRST_LOWER + key) % NUM_CHARS + FIRST_LOWER);		else			return ch;	}	} //end class