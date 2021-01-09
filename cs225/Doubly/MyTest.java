
import java.util.Scanner;

public class MyTest {
    public static void main(String args[]) {
	int choice = 1;
	Scanner keyboard = new Scanner(System.in);
	DoublyLinkedList<Integer> list = new DoublyLinkedList<>();
	while(choice != 0) {
	    System.out.println("Choice: Test 1 Add 2 Remove 3 Exit 0");
	    choice = keyboard.nextInt();
	    switch (choice) {
	    case 1:
		list.insertFirst(0);
		System.out.println(list.remove(0));
		System.out.println(list.length());
		System.out.println(list.isEmpty());
		list.insertFirst(0);
		list.remove(1);
		break;
	    case 2:
		list.insertFirst(1);
		break;
	    case 3:
		for(int x = 0; x < 4; x++) {
		    System.out.println(list.removeFirst());
		}
		break;
	    default:
		break;
	    }
	}
    }
}
