// File: Banking.java
// Date: April 9, 2018
// Author: Adam Abad
// Pupose: To complete the AcountKind's superclass and perform banking
//         actions using InterestAccount, and CDAccount

import AccountKinds.*;

public class Banking
{
    public static void main(String args[])
    {
	System.out.println();
	System.out.println("Welcome to the First Bank of Cuba.");
	System.out.println("Written By Adam Abad.");
	System.out.println();

	//Creating Intrest Account and CD Account
	InterestAccount iAccount = new InterestAccount(
		     "The Incredible Hulk","8765",50.0);

	CDAccount cdAccount = new CDAccount("Nemo", "3456",
					    10000.0);
	System.out.printf("Account status is: " +
			      iAccount.getName() +
			      " has balance $%.2f\n",
			      iAccount.getBalance());
	System.out.printf("Account status is: " +
			      cdAccount.getName() +
			      " has balance $%.2f\n",
			      cdAccount.getBalance());

	System.out.println();
	    
	//3 Monthly Updates and printing status
	for(int month = 1; month <= 3; month++)
	{
	    iAccount.monthly_update();
	    cdAccount.monthly_update();
	    System.out.println("After " + month + " month(s), ");
	    System.out.printf("Account status is: " +
			      iAccount.getName() +
			      " has balance $%.2f\n",
			      iAccount.getBalance());
	    System.out.printf("Account status is: " +
			      cdAccount.getName() +
			      " has balance $%.2f\n",
			      cdAccount.getBalance());
	    System.out.println();
	}
	
	//Deposit 2000 into Hulk's Account.
	System.out.println("Depositing $2000 into Hulk's" +
			   " Account.");
	iAccount.deposit(2000.0,"8765");
	System.out.printf("Account status is: " +
			      iAccount.getName() +
			      " has balance $%.2f\n",
			      iAccount.getBalance());
	System.out.println();

	//Withdraw 3000 out of Nemo's Account.
	System.out.println("Withdrawing $3000 from Nemo's" +
			   " Account.");
	cdAccount.withdraw(3000.0,"3456");
	System.out.printf("Account status is: " +
			      cdAccount.getName() +
			      " has balance $%.2f\n",
			      cdAccount.getBalance());
	System.out.println();
	
	//10 Monthly Updates and printing status
	for(int month = 4; month <= 13; month++)
	{
	    iAccount.monthly_update();
	    cdAccount.monthly_update();
	    System.out.println("After " + month + " month(s), ");
	    System.out.printf("Account status is: " +
			      iAccount.getName() +
			      " has balance $%.2f\n",
			      iAccount.getBalance());
	    System.out.printf("Account status is: " +
			      cdAccount.getName() +
			      " has balance $%.2f\n",
			      cdAccount.getBalance());
	    System.out.println();
	}
    }
}
