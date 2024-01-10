package nyp09x;

public class Course {
	private String code; private String name; private int capacity, studentCount;
	private Student[ ] students;
	public Course(String code, String name, int capacity) {
		this.code = code; this.name = name; this.capacity = capacity;
		students = new Student[capacity]; studentCount = 0;
	}
	public String getCode() { return code; }
	public String getName() { return name; }
	public int getCapacity() { return capacity; }
	public int getStudentCount() { return studentCount; }
	public boolean addStudent( Student aStudent ) {
		if( studentCount == capacity || findStudent(aStudent.getNumber()) != null )
			return false;
		students[studentCount] = aStudent;
		studentCount++;
		return true;
	}
	public Student findStudent( String number ) {
		for( int i = 0; i < studentCount; i++ )
			if( students[i].getNumber().compareTo(number) == 0 )
				return students[i];
		return null;
	}
	public void increaseCapacity( int newCapacity ) {
		if( newCapacity <= capacity )
			return;
		Student[ ] geciciDizi = new Student[ newCapacity ];
		for( int i = 0; i < studentCount; i++ )
			geciciDizi[i] = students[i];
		students = geciciDizi;
		capacity = newCapacity;
	}
	public void showClassList( ) {
		System.out.println("Class List of "+code+" "+name);
		System.out.println("Student#  Name, Surname");
		System.out.println("--------  -------------------------------");
		for( Student aStudent : students )
			if( aStudent != null ) //dizi gerçeklemesinde gerekli!
				System.out.println(aStudent.getNumber()+" "+aStudent.getName());
	}


}
