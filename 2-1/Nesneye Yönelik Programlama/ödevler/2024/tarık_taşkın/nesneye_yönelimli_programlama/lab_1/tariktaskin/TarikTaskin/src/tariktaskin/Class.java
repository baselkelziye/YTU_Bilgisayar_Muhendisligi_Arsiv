package tariktaskin;

public class Class {
	private static int counter = 0;
	private String name;
	private int duration;
	private String instructor;
	Student st[];

	public Class(String name, int duration, String instructor) {
		this.name = name;
		this.duration = duration;
		this.instructor = instructor;
		st = new Student[2]; //en fazla 2 ogrenci olabildigi belirtilmis
	}

	public void addStudent(Student student) {
		if (counter < 2) {
			st[counter] = student;
			counter++;
		} else {
			System.out.println("Course capacity is full");
		}
	}

	public double calculateAverageAge() {
		double averageAge = 0;
		int i = 0;

		while (i < 2 && st[i] != null) {
			averageAge = averageAge + st[i].getAge();
			i++;
		}
		return averageAge/(i);
	}

	public void classInfo() {
		System.out.println("Class name:" + name + "  " + "Number of students:" + counter + "  " + "Average age: " + calculateAverageAge());
	}
}
