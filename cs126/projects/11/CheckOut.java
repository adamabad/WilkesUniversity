// File: CheckOut.java
// Date: April 16, 2018
// Author: Adam Abad
// Purpose: To store data for patrons and their books

public class CheckOut
{
    private int patronID;
    private String bookID;
    private long timeStamp;

    //Reading from a File
    public CheckOut(int patron, String book, long time)
    {
	patronID = patron;
	bookID = book;
	timeStamp = time;
    }
    //Making CheckOut for new book
    public CheckOut(int patron, String book)
    {
	patronID = patron;
	bookID = book;
	timeStamp = System.currentTimeMillis();
    }

    public String getBook()
    {
	return bookID;
    }

    public int getPatron()
    {
	return patronID;
    }

    public long getTime()
    {
	return timeStamp;
    }

    public boolean equals(Object o)
    {
	if(o instanceof CheckOut)
	    return true;
	return false;
    }
    
    public String toSting()
    {
	String out;
	out = patronID + " " + bookID + " " + timeStamp;
	return out;
    }
}
