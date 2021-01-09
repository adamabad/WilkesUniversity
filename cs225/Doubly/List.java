/**
 * A linear list. Positions in the list are numbered from 0.
 */

import java.util.Iterator;

public interface List<T> {
    /**
     * Computes the length of the list.
     * @return The length of the list.
     */
    public int length();

    /**
     * Determines whether the list is empty.
     * @return True if the list is empty; false otherwise.
     */
    public boolean isEmpty();

    /**
     * Retrieves the first item.
     * @return the first item.
     */
    public T getFirst();

    /**
     * Retrieves the last item.
     * @return the last item.
     */
    public T getLast();

    /**
     * Retrieves an item by position.
     * @param n The position of the item.
     * @return the nth item.
     */
    public T get(int n);

    /**
     * Updates the value of an item by position.
     * @param n The position of the item to be updated.
     * @param item The new value of the item.
     */
    public void set(int n, T item);

    /**
     * Inserts an item at the specified position.
     * @param n The position at which the item is to be inserted.
     * @param item The item to be inserted.
     */
    public void insert(int n, T item);

    /**
     * Inserts an item at the front (position 0).
     * @param item The item to be inserted.
     */
    public void insertFirst(T item);

    /**
     * Inserts an item at the end.
     * @param item The item to be inserted (position length() - 1).
     */
    public void insertLast(T item);

    /**
     * Removes the item at the specified position.
     * @param n The position of the item to be removed.
     * @return The item that was removed.
     */
    public T remove(int n);

    /**
     * Removes the first item (position 0).
     * @return The item that was removed.
     */
    public T removeFirst();

    /** 
     * Removes the last item (position length() - 1).
     * @return The item that was removed.
     */
    public T removeLast();

    /**
     * Searches the list for an item (comparing with equals()).
     * @param item The item to be found.
     * @return If the item was found, the position of the 
     * first occurrence. Otherwise -1.
     */
    public int search(T item);

    /** 
     * Returns an iterator for the list.
     * @return An iterator that goes from the front of the list
     *         to the rear. 
     */
    public Iterator<T> iterator();
}
