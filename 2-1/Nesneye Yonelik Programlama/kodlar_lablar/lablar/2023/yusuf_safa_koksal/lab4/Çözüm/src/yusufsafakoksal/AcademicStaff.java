package yusufsafakoksal;

public class AcademicStaff extends Staff{
	private int numberOfCourses;
	
	public AcademicStaff(String name, double salary, int numberOfCourses) {
		super(name, salary);
		this.numberOfCourses=numberOfCourses;
	}
	
	public int getNumberOfCourses() {
		return numberOfCourses;
	}

	public void increaseSalary(double percentage) {
		double newSalary=this.getSalary()+this.getSalary()*percentage/100;
		newSalary+=numberOfCourses*1000;
		super.setSalary(newSalary);
	}
}
