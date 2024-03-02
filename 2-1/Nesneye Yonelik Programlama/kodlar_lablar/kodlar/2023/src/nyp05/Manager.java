package nyp05;

public class Manager extends Employee {
	private int bonus;

	public Manager( String name, int salary ) {
		super( name, salary );
		bonus = 0;
	}
	public void setBonus( int bonus ) {
		this.bonus = bonus;
	}

	public int getSalary( ) {
		return super.getSalary() + bonus;
	}
	public Manager(String name, int salary, int bonus) {
		super(name, salary);
		this.bonus = bonus;
	}

}
