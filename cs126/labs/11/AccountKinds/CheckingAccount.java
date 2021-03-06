/* CheckingAccount.java is an account that has a minimum balance
 * and 7% interest and a fee for each transaction of 10 cents.
 *
 * Written by: Charles Hoot, for Hands On Java.
 * Date: July 2000
 * Completed by: Adam Abad
 * Date: April 3, 2018
 **/

package AccountKinds;

public class CheckingAccount extends MinimumAccount
{
    private int myTransactions;

    static public double MINIMUM = 100.00;
    static public double PENALTY = 10.00;
    static public double INTEREST_RATE = 0.07;
    static public double TRANSACTION_COST = 0.10;
    
    /**
     * CheckingAccount constructor
     *
     * Input: name of account holder, and PIN, and initial balance
     **/
    
    public CheckingAccount ( String name, String pin, double initial) 
    {
	super(name, pin, MINIMUM, PENALTY);
	deposit(initial);
	setRate(INTEREST_RATE);
	myTransactions = 0;
    }

    public void withdraw(double amount, String pin)
    {
	super.withdraw(amount, pin);
	myTransactions++;
    }

    public void deposit(double amount, String pin)
    {
	super.deposit(amount, pin);
	myTransactions++;
    }

    public double computeFees()
    {
	double fee = super.computeFees();
       	fee = fee + (myTransactions * TRANSACTION_COST);
	myTransactions = 0;
	return fee;
    }
}
