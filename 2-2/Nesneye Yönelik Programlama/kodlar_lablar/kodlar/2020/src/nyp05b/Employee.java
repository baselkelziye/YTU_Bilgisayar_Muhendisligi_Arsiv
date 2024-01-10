package nyp05b;

public class Employee extends Person {
	private int salary;
	//protected int age;

	public Employee( String name, int salary ) {
		super( name );
		this.salary = salary;
	}

	public int getSalary( ) {
		return salary;
	}

	public void setSalary( int salary ) {
		this.salary = salary;
	}
	
}
