//MinimumAccount.java is a basic account that has a minumum balance// If the balance falls below the minimum, then a fee is charged//// Written by: Charles Hoot, for Hands On Java.// Date: July 2000// **************************************************************package AccountKinds;abstract class MinimumAccount extends ProtectedAccount {		private double myMinimum;	private double myPenalty;	private boolean chargePenalty;		// ***************************************************************	// MinimumAccount constructor	//	// Input: name of account holder, and PIN, minimum and penalty	// PostCondition: superclass constructor called	//					minimum and penaly set	//					penalty will not be charged	//****************************************************************	public MinimumAccount ( String name, String pin, double min, double penalty) {		super(name,pin);		myMinimum = min;		myPenalty = penalty;		chargePenalty = false;	}			// ***************************************************************	// withdraw needs to be overriden	// input: amount to withdraw, PIN	// 	// PostCondition: chargePenalty is true if balance fell below	// 					the minimum	//****************************************************************	public void withdraw( double amount, String pin) {		super.withdraw(amount, pin);		if(getBalance() < myMinimum)			chargePenalty = true;	}		// ***************************************************************	// override the fees	//****************************************************************	public double computeFees() {		double fee = super.computeFees();		if(chargePenalty)			fee = myPenalty;				//reset the fee flag		chargePenalty = false;				return fee;	}		}