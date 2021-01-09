// File: InterestAccount.java
// Date: April 9, 2018
// Author: Adam Abad
// Purpose: Extend BasicAccount to InterestAccount


/***********************************************************
 * InterestAccount.java is an account that has no minimum, *
 * 7% interest per year, monthly, and a fee of 10% or $10  *
 * (whichever is smaller)                                  *
 ***********************************************************/

package AccountKinds;

public class InterestAccount extends MinimumAccount
{
    static public double INTEREST_RATE = 0.07;
    static public double MINIMUM = 0.0;
    static public double PENALTY = 0.0;

    /**
     * InterestAccount Constructor
     *
     * Input: name of account, PIN, and starting Balance
     **/
    public InterestAccount(String name, String pin, double start)
    {
	super(name, pin, MINIMUM, PENALTY);
	super.deposit(start, pin);
	setRate(INTEREST_RATE);
    }

}
