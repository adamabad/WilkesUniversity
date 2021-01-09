// File: Popcorn.java
// Date: April 23, 2018
// Author: Adam Abad
// Purpose: To input popcorn data from a file
//         and output it as a histogram.

import java.util.*;
import java.io.*;

public class Popcorn
{
    static ArrayList <PopFarm> farms =
	new ArrayList <PopFarm>();
    public static void intro()
    {
	System.out.println();
	System.out.println("Program to produce a bar " +
			   "chart of popcorn production.");
	System.out.println("Written by Adam Abad.");
	System.out.println();
    }

    public static void loadArray(Scanner theFile)
    {
	while(theFile.hasNext())
        {
	    //Java Docs
	    StringTokenizer st = new
		StringTokenizer(theFile.nextLine(),",");
	    String name = st.nextToken();
	    if(name.length() > 30)
		name = name.substring(0,30);
	    StringTokenizer st2 = new
		StringTokenizer(st.nextToken());
	    double acres = Double.parseDouble(st2.nextToken());
	    int pints = Integer.parseInt(st2.nextToken());
	    farms.add(new PopFarm(name, acres, pints));
	}
    }

    public static String printBar(int position)
    {
	String outLine = farms.get(position).getName();
	for(int x = outLine.length(); x < 30; x++) {
	    outLine = outLine + " ";
	}
	double thouPerAcre = farms.get(position).getPints() /
	    farms.get(position).getAcres();
	int count = 0;
	for(double x = thouPerAcre; x > 250; x = x - 250)
	{
	    count++;
	    if(count == 20)
		outLine = outLine + "#";
	    else
		outLine = outLine + "*";
	}
        for(int x = outLine.length(); x < 50; x++)
	{
	    if(x == 49)
		outLine = outLine + "|";
	    else
		outLine = outLine + " ";
	}
	return outLine;
    }
    
    public static void table()
    {
	System.out.printf("%28s", "Pop CoOp");
	System.out.println();
	System.out.printf("%-29s %s","Farm name","Production in");
	System.out.println();
	System.out.printf("%29s %s","","Thousands of");
	System.out.println();
	System.out.printf("%29s %s","","Pint Jars per Acre");
	System.out.println();
	System.out.printf("%32s 1   2   3   4   5   6","");
	System.out.println();
	System.out.printf("%29s ---|---|---|---|---|---|---","");
	System.out.println();
	for(int x = 0; x < farms.size(); x++)
	{
	    System.out.println(printBar(x));
	}
    }
    
    public static void main(String args[])
    {
	if(args[0] == null) {
	    System.err.println("File required on command " +
			       "line.");
	    System.exit(1);
	}
	//Getting File
	Scanner theFile = null;
	try
	{
	    theFile = new Scanner(new File (args[0]));
	}
	catch (FileNotFoundException e)
	{
	    System.err.println("File " + args[0] +
			       " not found.");
	    System.exit(1);
	}
	intro();
	loadArray(theFile);
	table();
	System.out.println();
    }
}
