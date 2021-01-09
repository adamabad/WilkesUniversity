// File: Histo.java
// Date: Febuary 27, 2018
// Author: Adam Abad
// Purpose: To make and display a histogram of grades

import java.io.*;
import java.util.Scanner;

public class Histo
{
    public static void main(String[] args)
	throws FileNotFoundException
    {	    
        
	intro();
	String[] nameArr;
	double[] scoreArr;
	final int MAX_SCORES = 1000;

	nameArr = new String[MAX_SCORES];
	scoreArr = new double[MAX_SCORES];

	int scores = fillArraysFile(nameArr, scoreArr);

	scoreArr = DoubleArrayOps.subArray(scoreArr,0,scores-1);
	
	double high = getHigh(scoreArr);
	double low = getLow(scoreArr);
	double average = DoubleArrayOps.average(scoreArr);
	double stdDev = DoubleArrayOps.standardDev(scoreArr);

	//Table Output
	summary(high,low,average,stdDev,scoreArr,nameArr);

	//Histogram
	selectionSort(scoreArr);
	printHist(scoreArr);
	System.out.println();
    }
    


    public static void intro()
    {
	System.out.println();
	System.out.println("Program to print a histogram of a "
			   + "list of scores.");
	System.out.println("It also produces the high, low, and "
			   + "average score.");
	System.out.println("along with the standard deviation.");
	System.out.println("Written by Adam Abad.");
	System.out.println();
    }

    public static double getHigh(double[] scoreArr)
    {
	double high = scoreArr[0];
	int numValue = scoreArr.length;
	if(numValue > 0)
	{
	    for(int i = 1; i < numValue; i++)
	    {
		double compare = scoreArr[i];
		if(compare > high)
		    high = compare;
	    }
	}
	else
	{
	    System.out.println("No Numbers Found.");
		return 0.0;
	  
	}
	return high;
    }
    
    public static double getLow(double[] scoreArr)
    {
	double low = scoreArr[0];
	int numValue = scoreArr.length;
	if(numValue > 0)
	{
	    for(int i = 1; i < numValue; i++)
	    {
		double compare = scoreArr[i];
		if(compare < low)
		    low = compare;
	    }
	}
	else
	{
	    System.out.println("No Numbers Found.");
		return 0.0;
	  
	}
	return low;
    }
    
    

    public static void summary(double high, double low,double avg,
			       double stdDev,double[] scoreArr,
			       String[] nameArr)
    {
	System.out.printf("Worst score: %13.2f\n",low);
	System.out.printf("Best score: %14.2f\n",high);
	System.out.printf("Average score: %11.2f\n",avg);
	System.out.printf("Standard deviation: %6.2f\n",stdDev);

	System.out.println();
	System.out.println("Name              Score");
	System.out.println("====              =====");
	System.out.println();

	for(int i = 0; i < scoreArr.length; i++)
	    System.out.printf("%-17s%6.2f\n",nameArr[i],
			       scoreArr[i]);
	System.out.println();
    }

    //Swap and SelectionSort from sheet
    
    public static void swap(double[] a, int i, int j)
    {
	if (i != j)
	{
	    double temp = a[i];
	    a[i] = a[j];
	    a[j] = temp;
	}
    }

    public static void selectionSort(double[] a)
    {
	for(int i = 0; i < a.length - 1; i++)
	{
	    int smallest = i;
	    for(int j = i + 1; j < a.length; j++)
	    {
		if(a[j] < a[smallest])
		{
		    smallest = j;
		}
	    }
	    swap(a, i, smallest);
	}
    }

    public static void printHist(double[] sorted)
    {
	System.out.println("Histogram:");
	System.out.println("==========");
	System.out.println();
	int position = 0;
	for(int x = (int)sorted[0]; x <= (int)sorted[sorted.length - 1];
	    x++)
	{
	    System.out.print(x + ": ");
	    while(x == sorted[position])
	    {
		System.out.print("*");
		position++;
		if(position >= sorted.length - 1)
		    break;
	    }
	    System.out.println();
	}
    }
    
    public static int fillArraysFile(String[] nameArr,
				     double[] scoreArr)
	throws FileNotFoundException
    {
	
	Scanner theKeyboard = new Scanner(System.in);
    
	System.out.print("Enter the name of the scores file: ");
	String filename = theKeyboard.next();
	System.out.println();
	System.out.println(); //Turnin

	Scanner theFile = new Scanner(new File(filename));

	int numscores = 0;
	String name;
	double score;

	while(true)
	{
	    name = theFile.next();
	    if(name.equals("done"))
		break;
	    score = theFile.nextDouble();

	    nameArr[numscores] = name;
	    scoreArr[numscores] = score;

	    numscores++;
	}
	return numscores;
    }
}
