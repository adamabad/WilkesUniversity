import java.lang.Thread;
import java.util.concurrent.ArrayBlockingQueue;

public class Beverages {
    
    public static class bevThread extends Thread {
	
	private int n;
	private String bev;
	private ArrayBlockingQueue<Integer> queueIn;
	private ArrayBlockingQueue<Integer> queueOut;
	
	public bevThread(String beverage, ArrayBlockingQueue<Integer> qIn,
			 ArrayBlockingQueue<Integer> qOut) {
	    bev = beverage;
	    queueIn = qIn;
	    queueOut = qOut;
	}
	
	public ArrayBlockingQueue<Integer> getIn () {
	    return queueIn;
	}
	
	public ArrayBlockingQueue<Integer> getOut() {
	    return queueOut;
	}
	
	public void run() {
	    try {
		n = (int)queueIn.take();
	    }
	    catch (InterruptedException e) {
		System.err.println("ArrayBlockingQueue Error: take() in");
	    }   
	    if( n != 1) {
		System.out.print(n + " bottles of " + bev + " on the wall, ");
		System.out.println(n + " bottles of " + bev + ".");
	    }
	    else {
		System.out.print(n + " bottle of " + bev + " on the wall, ");
		System.out.println(n + " bottle of " + bev + ".");
	    }
	    if(n - 1 != 1) {
		System.out.print("Take one down, pass it around, " + (n - 1));
		System.out.println(" bottles of " + bev + " on the wall.\n");
	    }
	    else {
		System.out.print("Take one down, pass it around, " + (n - 1));
		System.out.println(" bottle of " + bev + " on the wall.\n");
	    }
	    
	    try {	
		queueOut.put(n - 1);
	    }
	    catch (InterruptedException e) {
		System.err.println("ArrayBlockingQueue Error: put() in " + n);
	    }
	}
    }
    
    public static void main(String args[]) {
	if(args.length == 2) {
	    String bev;
	    Integer n;
	    
	    bev = args[0];
	    n = Integer.parseInt(args[1]);
	    
	    bevThread threadArray[] = new bevThread[n];
	    for(int x = 0; x < n; x++) {
		ArrayBlockingQueue<Integer> queue = new ArrayBlockingQueue(1);
		if (x == 0) {
		    ArrayBlockingQueue<Integer> queueStart = new ArrayBlockingQueue(1);
		    threadArray[x] = new bevThread(bev, queueStart, queue);
		}
		else {
		    threadArray[x] = new bevThread(bev, threadArray[x - 1].getOut(), queue);
		}
		threadArray[x].start();
	    }
	    
	    try {
		threadArray[0].getIn().put(n);
	    }
	    catch (InterruptedException e) {
		System.err.println("ArrayBlockingQueue Error: put(" + n + ") in first thread.");
	    }
	}
	
	else {
	    System.err.println("Beverages takes 2 command-line arguements: (beverage) (integer)");
	}
    }
}
