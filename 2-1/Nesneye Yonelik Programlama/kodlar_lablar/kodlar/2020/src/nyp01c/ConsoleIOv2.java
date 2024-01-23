package nyp01c;

import java.util.Scanner;

public class ConsoleIOv2 {

	public static void main(String[] args) {
	      Scanner in = new Scanner(System.in);
	      System.out.print("How old are you? ");
	      int age = in.nextInt();
	      System.out.print("What is your name? ");
	      in.nextLine(); //workaround for the bug
	      String name = in.nextLine();
	      System.out.print("What is your surname? ");
	      String surname = in.nextLine();
	      System.out.println("Hello, " + name + " " + surname +
	    		  ". Next year, you'll be " + (age + 1) + ".");
	      in.close();
	}

}
