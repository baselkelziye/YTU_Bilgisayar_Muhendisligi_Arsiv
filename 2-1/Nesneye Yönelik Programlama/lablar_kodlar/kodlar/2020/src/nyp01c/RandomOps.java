package nyp01c;
import java.util.*;
public class RandomOps {
	public static void main(String[] args) {
		Random generator = new Random();
		int intVal = generator.nextInt();
		System.out.println("I have got " + Math.abs(intVal) + " pebbles.");
		int bounded = generator.nextInt(11);
		System.out.println("I have painted my " + bounded + " fingers.");
	}
}
