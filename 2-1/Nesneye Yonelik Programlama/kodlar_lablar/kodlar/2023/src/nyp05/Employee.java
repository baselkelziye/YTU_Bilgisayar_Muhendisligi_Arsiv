package nyp05;

public class Employee extends Person {
	private int salary;

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
	
	/*public String toString() {
		return getName() + " " + getSalary();
	}*/
	
}
