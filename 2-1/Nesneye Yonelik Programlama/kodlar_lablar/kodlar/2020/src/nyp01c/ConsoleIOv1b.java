package nyp01c;

import java.util.Scanner;

public class ConsoleIOv1b {

	public static void main(String[] args) {
	      Scanner in = new Scanner(System.in);
	      System.out.print("How old are you? ");
	      int age = in.nextInt();
	      in.nextLine();
	      System.out.print("What is your name? ");
	      String name = in.nextLine();
	      System.out.println("Hello, " + name + 
	    		  ". Next year, you'll be " + (age + 1) + ".");
	      in.close();
	}

}
