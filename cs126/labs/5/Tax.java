//Tax.java defines tax computation functions.//// Author: Adam Abad// Date: Febuary 13, 2018//// ************************************************************public class Tax{    public static double computeTotalCost(double cost, double rate)    {	final double MIN_LUXURY = 100.0;	final double LUXURY_RATE = 10.0;		if((cost < 0) || (rate < 0))	{	    String message = "in computeTotalCost, " +		"the values of cost and rate must be > 0, not " +		cost + " " + rate;	    throw new IllegalArgumentException(message);        }	if (cost <= MIN_LUXURY)	    return cost + cost * rate / 100.;	double regularCost, luxuryBase, luxurySurcharge,	    totalCost;		regularCost = cost + cost * rate / 100;	luxuryBase = cost - MIN_LUXURY;	luxurySurcharge = luxuryBase * LUXURY_RATE / 100;	totalCost = regularCost + luxurySurcharge;	return totalCost;    }}