package cozum;

public class Class {
	private String name;
	private int duration;
	private String instructor;
	private Student st[] = new Student[2];
	
	
	public Class(String name, int duration, String instructor) {
		this.name = name;
		this.duration = duration;
		this.instructor = instructor;
	}
	
	public void addStudent(Student std) {
		int i=0;
		while(i<st.length && st[i]!=null)
			i++;
		
		if(i<st.length) 
			st[i] = std;
		else
			System.out.println("Course capacity is full");
		
		
	}
	
	public void classInfo() {
		int count=0,i=0;
		double avgAge,totalAge=0;
		
		while(i<st.length && st[i]!=null) {
			count++;
			totalAge += st[i].getAge();
			i++;
			
		}
		avgAge = totalAge/count;
		System.out.println("Class name:"+ name +"   " + "Number of students:"+count+"   "+ "Average age:"+ avgAge);
		
		
	}


	
	

}
