package tariktaskin;

public class Student {
	private int stdNo;
	private String name;
	private int age;
	private double discountPercentage;
	Exam exam;
	
	public Student(int stdNo, String name, int age) {
		this.stdNo = stdNo;
		this.name = name;
		this.age = age;
	}
	
	public void setExamScore(Exam exam, double score) { //uml'de score int olarak gozukuyor ama exam classında double oldugu icin double olarak aldim
		setExam(exam);
		this.exam.setScore(score);
	}
	
	public void calculateDiscount() {
		if(exam.getScore() >= 70) {
			discountPercentage = 20;
		}
		else if(exam.getScore() > 50) {
			discountPercentage = 10;
		}
	}

	public void setExam(Exam exam) {
		this.exam = exam;
	}

	public int getAge() {
		return age;
	}

	public double getDiscountPercentage() {
		return discountPercentage;
	}

	@Override
	public String toString() {
		return "Student [stdNo=" + stdNo + ", name=" + name + ", age=" + age + ", exam=" + exam + "]";
	}
	
	
}
