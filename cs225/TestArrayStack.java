import org.junit.Test;
import org.junit.Assert;
import java.util.EmptyStackException;

public class TestArrayStack {
  
  @Test
  public void testisEmpty() {
    ArrayStack<Integer> s = new ArrayStack<>();
    Assert.assertTrue(s.isEmpty());
    s.push(1);
    Assert.assertFalse(s.isEmpty());
  }

  @Test
  public void testEmptyStack() {
    ArrayStack<Integer> s = new ArrayStack<>();
    for (int i = 0; i < 10; i++) {
      s.push(i);
    }
    for (int i = 9; i >= 0; i--) {
      Assert.assertEquals(i, (long) s.pop());
    }
  }

  @Test
  public void testConstructor1() {
    ArrayStack<Integer> s = new ArrayStack<>(5, 5);
    for (int i = 0; i < 10; i++) {
      s.push(i);
    }
    for (int i = 9; i >= 0; i--) {
      Assert.assertEquals(i, (long) s.pop());
    }
  }

  @Test
  public void testConstructor2() {
    ArrayStack<Integer> s = new ArrayStack<>(5);
    for (int i = 0; i < 10; i++) {
      s.push(i);
    }
    for (int i = 9; i >= 0; i--) {
      Assert.assertEquals(i, (long) s.pop());
    }
  }
  
  @Test
  public void testException() {
    boolean thrown = false;
    ArrayStack<Integer> s = new ArrayStack<>();
    try {
      s.pop();
    }
    catch (EmptyStackException e) {
      thrown = true;
    }
    Assert.assertTrue(thrown);
  }

  @Test
  public void testPushAndPop() {
    ArrayStack<String> s = new ArrayStack<String>(5);
    for (int i = 0; i < 5; i++) {
      s.push(Integer.toString(2*i));
      s.push(Integer.toString(2*i+1));
      Assert.assertEquals(Integer.toString(2*i+1), s.pop());
    }
    for (int i = 8; i >= 0; i-=2) {
      Assert.assertEquals(Integer.toString(i), s.pop());
    }
  }

  @Test
  public void testArgs() {
    boolean thrown = false;
    try {
      ArrayStack<Integer> s = new ArrayStack<>(0);
    }
    catch (IllegalArgumentException e) {
      thrown = true;
    }
    Assert.assertTrue(thrown);
  }
}
