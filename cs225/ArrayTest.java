
import java.util.*;

public class ArrayTest {
    static Scanner keyboard = new Scanner(System.in);
    public static void main(String[] args) {
	int value = 1;
	ArrayStack stack = new ArrayStack(1,0);
	while (value > 0) {
	    System.out.print("Push(1) Pop(2) Auto(3): ");
	    value = keyboard.nextInt();
     
	    if (value == 1) {
		stack.push(keyboard.nextInt());
	    }
	    if (value == 2) {
		System.out.println(stack.pop());
	    }
	    if (value == 0) {
		System.out.println(stack.isEmpty());
	    }
	}
    }
}