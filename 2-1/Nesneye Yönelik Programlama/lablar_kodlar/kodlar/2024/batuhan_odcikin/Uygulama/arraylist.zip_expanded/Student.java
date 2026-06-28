package arraylist_kullanim;

import java.util.ArrayList;

public class Student {
	private int no;
	private String name;
	private ArrayList<Class1> liste;
	
	public Student(int no, String name) {
		this.no = no;
		this.name = name;
		liste = new ArrayList<>();
	}

	public int getNo() {
		return no;
	}

	public void setNo(int no) {
		this.no = no;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
	
	

}
