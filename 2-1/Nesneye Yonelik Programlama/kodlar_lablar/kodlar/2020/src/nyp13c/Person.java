package nyp13c;
public class Person {
	private String name;
	private Employee employee;
	public Person(String name) { this.name = name; }
	public void enlist( int salary ) { 
		employee = new Employee( salary ); }
	public String toString( ) {
		String mesaj = name;
		if( employee != null )
			mesaj += " " + employee.getSalary( );
		return mesaj;
	}
//	@SuppressWarnings("unused")
	private class Employee {
		private int salary;
		public Employee( int salary ) { this.salary = salary; }
		public int getSalary() { return salary; }
		@SuppressWarnings("unused")
		public void setSalary(int salary) { this.salary = salary; }
	}
}
