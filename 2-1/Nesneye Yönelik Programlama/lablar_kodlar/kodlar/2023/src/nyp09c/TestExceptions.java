package nyp09c;

import java.util.*;

public class TestExceptions {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
			System.out.print("Enter person's name: ");
			String name = in.nextLine();
			Person insan = new Person(name);
			System.out.print("Enter age: ");
			int age = in.nextInt();
			insan.setAge(age);
			System.out.println(insan);
			in.close();
	}

}
