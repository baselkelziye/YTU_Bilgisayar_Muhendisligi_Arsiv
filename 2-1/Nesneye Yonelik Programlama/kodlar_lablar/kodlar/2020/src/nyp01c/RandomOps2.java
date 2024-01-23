package nyp01c;
import java.util.*;
public class RandomOps2 {
	public static void main(String[] args) {
		Random generator = new Random();
		int intVal = generator.nextInt();
		System.out.println("I have got " + Math.abs(intVal) + " pebbles.");
		int bounded = generator.nextInt(11);
		if ( bounded == 0 )
			System.out.println("I have not painted any fingers.");
		else if (bounded == 1)
			System.out.println("I have painted a finger.");
		else
			System.out.println("I have painted my " + bounded + " fingers.");
	}
}
