// File: PopFarm.java
// Date: April 23, 2018
// Author: Adam Abad
// Purpose: To hold data for farms regarding popcorn

public class PopFarm
{
    private String name;
    private double acres;
    private int pints;
    
    public PopFarm(String inName, double inAcres, int inPints)
    {
	name = inName;
	acres = inAcres;
	pints = inPints;
    }

    public String getName()
    {
	return name;
    }

    public double getAcres()
    {
	return acres;
    }

    public int getPints()
    {
	return pints;
    }

    public String toString()
    {
	String out = "Name: " + name +"\nAcres: " + acres
	    + "\nPints: " + pints;
	return out;
    }
}
