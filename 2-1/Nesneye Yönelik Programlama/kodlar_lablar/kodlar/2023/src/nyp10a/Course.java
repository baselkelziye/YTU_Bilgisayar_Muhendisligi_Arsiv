package nyp10a;
import java.util.*;

public class Course {
	private String code; private String name; private int capacity;
	private ArrayList<Student> students;
	
	public Course(String code, String name, int capacity) {
		this.code = code; this.name = name; this.capacity = capacity;
		students = new ArrayList<Student>();
	}
	public String getCode() { return code; }
	public String getName() { return name; }
	public int getCapacity() { return capacity; }
	public int getStudentCount() {
		return students.size();
	}
	public boolean addStudent( Student aStudent ) {
		if( getStudentCount() == capacity || 
				findStudent(aStudent.getNumber()) != null )
			return false;
		students.add(aStudent);
		return true;
	}
	public Student findStudent( String number ) {
		for( Student aStudent : students )
			if( aStudent.getNumber().compareTo(number) == 0 )
				return aStudent;
		return null;
	}
	public void increaseCapacity( int newCapacity ) {
		if( newCapacity <= capacity )
			return;
		capacity = newCapacity;
	}
	public void showClassList( ) {
		System.out.println("Class List of "+code+" "+name);
		System.out.println("Student#  Name, Surname");
		System.out.println("--------  -----------------------------");
		for( Student aStudent : students )
			System.out.println(aStudent.getNumber()+ 
			"  " + aStudent.getName());
		
	}
}
