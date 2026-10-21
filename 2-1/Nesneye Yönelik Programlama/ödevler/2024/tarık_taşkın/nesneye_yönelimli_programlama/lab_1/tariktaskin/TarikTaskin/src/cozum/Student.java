package cozum;

public class Student {
	private int stdNo;
	private String name;
	private int age;
	private double discountPercentage;
	private Exam exam;


	
	
	public Student(int stdNo, String name, int age) {
		this.stdNo = stdNo;
		this.name = name;
		this.age = age;
	}

	
	public void setExamScore(Exam exam, int i) {
		setExam(exam);
		exam.setScore(i);
		
	}
	
	public void calculateDiscount() {
		if(exam!=null && exam.getScore()>=70 ) 
			discountPercentage = 20;
		else if(exam!=null && exam.getScore()>=50)
			discountPercentage = 10;
		else
			System.out.println("no discount opportunity ");	
		
	}


	@Override
	public String toString() {
		return "Student [stdNo=" + stdNo + ", name=" + name + ", age=" + age + ", exam=" + exam + "]";
	}




	public int getStdNo() {
		return stdNo;
	}


	public void setStdNo(int stdNo) {
		this.stdNo = stdNo;
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public int getAge() {
		return age;
	}


	public void setAge(int age) {
		this.age = age;
	}


	public Exam getExam() {
		return exam;
	}


	public void setExam(Exam exam) {
		this.exam = exam;
	}

	

	public double getDiscountPercentage() {
		return discountPercentage;
	}


	public void setDiscountPercentage(double discountPercentage) {
		this.discountPercentage = discountPercentage;
	}


	




	
	
	
	

}
