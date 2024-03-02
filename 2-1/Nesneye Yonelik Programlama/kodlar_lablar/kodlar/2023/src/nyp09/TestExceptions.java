package nyp09;

import java.util.*;

public class TestExceptions {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		try {
			System.out.print("Enter person's name: ");
			String name = in.nextLine();
			Person insan = new Person(name);
			System.out.print("Enter age: ");
			int age = in.nextInt();
			insan.setAge(age);
			System.out.println(insan);
		} 
		catch (ImpossibleInfo e) {
			//System.out.println(e.toString());
			e.printStackTrace();
		}
		finally {
			System.out.println("scanner closing");
			in.close();
		}
	}

}
