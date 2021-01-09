/**
 * Implements a stack using a given array size, or defaults to 10.
 * If the array fills, a larger array is made using a given increment or 
 * by the size of the given array.
 * Modified from ArrayStack.java
 */

import java.util.EmptyStackException;

public class Stack<T> {
    int top;
    T[] items;
    int cap;
    int incr;
    
    public Stack() {
	this(10,10);
    }

    public Stack(int capacity) {
	this(capacity,capacity);
    }
    @SuppressWarnings("unchecked")
    public Stack(int capacity, int increment) {
	if(capacity <= 0 || increment <= 0) {
	    throw new IllegalArgumentException();
	} else {
	    top = -1;
	    items = (T[]) new Object[capacity];
	    incr = increment;
	    cap = capacity;
	}
    }
    
    public void push(T item) {
        if ((top + 1) >= cap) {
	    T[] hold = items;
	    items = (T[]) new Object[cap + incr];
	    for (int x = 0; x < cap; x++) {
		items[x] = hold[x];
	    }
	    cap = cap + incr;
	}
	items[++top] = item;
	System.out.println(items[top]);
    }

    public T pop() {
	try {
	    return items[top--];
	}
	catch (ArrayIndexOutOfBoundsException e) {
	    throw new EmptyStackException();
	}
    }

    public boolean isEmpty() {
	return top == -1;
    }
}

    
