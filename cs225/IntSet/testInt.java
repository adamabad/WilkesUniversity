public class testInt {
	public static void main(String[] args) {
	    int[] a1 = {1, 2, 3, 4, 5};
		int[] a2 = {2, 3, 4, 5};
		IntSet s1 = IntSet.arrayToIntSet(a1);
		IntSet s2 = IntSet.arrayToIntSet(a2);
		System.out.println(IntSet.isSubsetOf(s1,s2));
	}	
}
