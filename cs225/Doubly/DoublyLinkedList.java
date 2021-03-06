import java.util.Iterator;

public class DoublyLinkedList<T> implements Iterable<T>, List<T> {
    private class Node {
	T item;
	Node next;
	Node previous;
    }

    private Node head;
    private Node tail;
    private int length;

    public DoublyLinkedList() {
	head = null;
	tail = null;
	length = 0;
    }

    public boolean isEmpty() {
	return head == null;
    }

    public int length() {
	return length;
    }

    public int search (T item) {
	Node node = head;
	int position = 0;
	while (node != null && !node.item.equals(item)) {
	    node = node.next;
	    position++;
	}
	return node == null ? -1 : position;
    }

    public void insertFirst(T item) {
	Node newNode = new Node();
	newNode.item = item;
	newNode.next = head;
	newNode.previous = null;
	if (head == null) {
	    tail = newNode;
	}
	else {
	    newNode.next.previous = newNode;
	}
	head = newNode;
	length++;
    }

    public void insertLast(T item) {
	Node newNode = new Node();
	newNode.item = item;
	newNode.next = null;
	if (head == null) {
	    head = newNode;
	    newNode.previous = null;
	}
	else {
	    tail.next = newNode;
	    newNode.previous = tail;
	}
	tail = newNode;
	length++;
    }

    public void insert(int n, T item) {
	if (n < 0 || n > length) {
	    throw new IndexOutOfBoundsException(n);
	}
	else if (n == 0) {
	    insertFirst(item);
	}
	else if (n == length) {
	    insertLast(item);
	}
	else {
	    Node position = find(n);
	    Node newNode = new Node();
	    newNode.item = item;
	    position.previous.next = newNode;
	    newNode.previous = position.previous;
	    position.previous = newNode;
	    newNode.next = position;
	    length++;
	}
    }

    public T removeFirst() {
	if (head == null) {
	    throw new IndexOutOfBoundsException(0);
	}
	else {
	    T result = head.item;
	    head = head.next;
	    if (head != null) {
		head.previous = null;
	    } 
	    else {
		tail = null;
	    }
	    length--;
	    return result;
	}
    }	

    public T removeLast() {
	if (head == null) {
	    throw new IndexOutOfBoundsException(length());
	}
	else {
	    T result = tail.item;
	    tail = tail.previous;
	    if (tail != null) {
		tail.next = null;
	    }
	    else {
		head = null;
	    }
	    length--;
	    return result;
	}
    }

    public T remove(int n) {
	if (head == null) {
	    throw new IndexOutOfBoundsException(n);
	}
	else if (n == 0) {
	    return removeFirst();
	}
	else if (n == length - 1) {
	    return removeLast();
	}
	else {
	    Node node = find(n);
	    T result = node.item;
	    node.previous.next = node.next;
	    node.next.previous = node.previous;
	    length--;
	    return result;
	}
    }

    private Node find(int n) {
	Node node = head;
	int i = n;
	while (node != null && i > 0) {
	    node = node.next;
	    i--;
	}
	if (node == null) {
	    throw new IndexOutOfBoundsException(n);
	}
	else {
	    return node;
	}
    }

    public T getFirst() {
	if (head == null) {
	    throw new IndexOutOfBoundsException(length());
	}
	else {
	    return head.item;
	}
    }

    public T getLast() {
	if (tail == null) {
	    throw new IndexOutOfBoundsException(0);
	}
	else {
	    return tail.item;
	}
    }

    public T get(int n) {
	if (n < 0) {
	    throw new IndexOutOfBoundsException(n);
	}
	else {
	    return find(n).item;
	}
    }

    public void set(int n, T item) {
	if (head == null) {
	    throw new IndexOutOfBoundsException(n);
	}
	else {
	    find(n).item = item;
	}
    }

    private class DoublyLinkedListIterator implements Iterator<T> {
	private DoublyLinkedList<T> list;
	private Node next;

	DoublyLinkedListIterator(DoublyLinkedList<T> list) {
	    this.list = list;
	    this.next = head;
	}

	public boolean hasNext() {
	    return next != null;
	}

	public T next() {
	    T result = next.item;
	    next = next.next;
	    return result;
	}
    }

    public DoublyLinkedListIterator iterator() {
	return new DoublyLinkedListIterator(this);
    }
}
