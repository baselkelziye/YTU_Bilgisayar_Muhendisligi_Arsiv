package arraylist_kullanim;

import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		Student s1 = new Student(101, "Ahmet Kara");
		Student s2 = new Student(201, "Ali Demir");
		
		ArrayList<Student> listem = new ArrayList<>();
		
		listem.add(s1);
		listem.add(s2);
		
		for(Student s:listem)
			System.out.println(s.getName());
		
		
		if(!listem.contains(s1))
			listem.add(s1);
		
		for(Student s:listem)
			System.out.println(s.getName());
		
		System.out.println(listem.size());
		
	}

}
