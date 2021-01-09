import java.util.Random;

public class Hash {
    public static int hash(String s) {
	int num = s.charAt(0);
	Random random = new Random(s.charAt(0));
	for(int i = 0; i < s.length(); i++) {
	    num = (num * 127) + ((s.charAt(i) * i >> 2) + (s.charAt(i) ^ i >> 2) + s.charAt(i) + random.nextInt());
	    num = num / (random.nextInt(9) + 1);
	}
	return num;
    }
}
