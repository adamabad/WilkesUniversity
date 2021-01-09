// File: CDAccount.java
// Date: April 9, 2018
// Author: Adam Abad
// Purpose: Extend BasicAccount to CDAccount

/************************************************
 * CDAccount is an account that has no minimum, *
 * 15% Interest paid yearly, charges a fee of   *
 * 10% or 10 (smallest), but a charge of 20%    *
 * of total if withdraw before 12 months pass   *
 ************************************************/

package AccountKinds;

public class CDAccount extends MinimumAccount
{
    static public double INTEREST_RATE = 0.15;
    static public double MINIMUM = 0.0;
    static public double PENALTY = .20;

    private int monthsPassed = 0;

    /**
     * CDAccount Constructor
     *
     * Input: name of account, PIN, starting Balance
     **/

    public CDAccount(String name, String pin, double start)
    {
	super(name, pin, MINIMUM, PENALTY);
	deposit(start, pin);
    }

    public void withdraw(double amount, String pin)
    {
	if(monthsPassed > 12)
	    super.withdraw(amount, pin);
	else
	{
	    double fee = getBalance() * PENALTY;
	    super.withdraw(fee, pin);
	    super.withdraw(amount, pin);
	}
    }

    public void monthly_update()
    {
	monthsPassed = monthsPassed + 1;
	if(monthsPassed % 12 == 0)
	{
	    double adjustBy = getBalance() * INTEREST_RATE;
	    deposit(adjustBy);
	}
    }
}
