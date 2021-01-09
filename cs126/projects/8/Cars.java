// File: Cars.java
// Date: March 26, 2018
// Author: Adam Abad
// Purpose: To get data from a file and display a table using objects

public class Cars
{
    public static void main(String args[])
    {
	intro();
	String inFile = args[0];
	SalesTable table = new SalesTable(inFile);
	outTable(table);
	System.out.println();
    }

    public static void intro()
    {
	System.out.println();
	System.out.println("Program to output a monthly report of" +
			   " car sales.");
	System.out.println("Written by Adam Abad.");
	System.out.println();
    }

    public static void outTable(SalesTable table)
    {
	//Header

	System.out.println("                    Salesperson");
	System.out.println("  Model  :   1   2   3   4   5   6   7   8  :" +
			   "  Totals  :  Max");
	System.out.println("---------------------------------------------" +
			   "------------------");
	//Table Loops
	for(int x = 0; x < 10; x++)
	{
	    System.out.printf("%5d    :",x + 1);
	    for(int y = 0; y < 8; y++)
		System.out.printf("%4d",table.getField(x,y));
	    System.out.printf("  :%6d",table.modelTotal(x));
	    System.out.printf("    :%4d",table.modelMax(x));
	    System.out.println();
	}

	//Footer
	System.out.println("---------------------------------------------" +
			   "------------------");
	System.out.print(" Totals  :");
	for(int y = 0; y < 8; y++)
	    System.out.printf("%4d",table.personTotal(y));
	System.out.println();
	System.out.print("   Max   :");
	for(int y = 0; y < 8; y++)
	    System.out.printf("%4d",table.salesMax(y));
	System.out.println();
    }
}
