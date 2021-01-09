// File: SalesTable.java
// Date: March 26, 2018
// Author: Adam Abad
// Purpose: SalesTable Class to handle objects for Cars.java

import java.util.*;
import java.io.*;

public class SalesTable
{
    private int [][] table = new int[10][8];
    private int [] personTotal;
    
    public SalesTable(String fileName)
    {
	//Checks for File
	Scanner theFile = null;
	try
	{
	    theFile = new Scanner(new File(fileName));
	}
	catch (FileNotFoundException e)
	{
	    System.out.println("File " + fileName + " not found.");
	    System.exit(1);
	}

	//Zeros the Table
	for(int x = 0; x < 10; x++)
	    for(int y = 0; y < 8; y++)
		table[x][y] = 0;
	//Input Data from file
	for(int x = 0; x < 10; x++)
	    for(int y = 0; y < 8; y++)
		table[x][y] = theFile.nextInt();
	    
    }

    //Finds salesperson total (down column)
    public int personTotal(int person)
    {
	int total = 0;
	for(int x = 0; x < 10; x++)
	    total = total + table[x][person];
	return total;
    }

    //Outputs String for a person's sales
    public String personOut(int person)
    {
        String outPerson = "";
	for(int x = 0; x < 10; x++)
	    outPerson = outPerson + " " + table[x][person];
	return outPerson;
    }
    
    //Finds modeltotals (across row)
    public int modelTotal(int model)
    {
	int total = 0;
	for(int x = 0; x < 8; x++)
	    total = total + table[model][x];
	return total;
    }

    //Outputs String for a model's sales
    public String modelOut(int model)
    {
	String outModel = "";
	for(int x = 0; x < 10; x++)
	    outModel = outModel + " " + table[model][x];
	return outModel;
    }

    public int salesMax(int person)
    {
	int max = table[0][person];
	for(int x = 1; x < 10; x++)
	    if(max < table[x][person])
		max = table[x][person];
	return max;
    }

    public int modelMax(int model)
    {
	int max = table[model][0];
	for(int x = 1; x < 8; x++)
	    if(max < table[model][x])
		max = table[model][x];
	return max;
    }
    public int getField(int model,int person)
    {
	return table[model][person];
    }
    
    //toString method
    public String toString()
    {
	String tableOut = "";
	for(int x = 0; x < 10; x++)
	{
	    for(int y = 0; y < 8; y++)
		tableOut = tableOut + table[x][y] + " ";
	    tableOut = tableOut + "\n";
	}
	return tableOut;
    }
}
