package tariktaskin;

public class Manager extends Employee{
	private double bonus;

	public Manager(String name, double salary, double bonus) {
		super(name, salary);
		this.bonus = bonus;
	}
	
	public void increaseSalary(double percentage) {
		setSalary(getSalary()*(percentage+100)/100.0+ bonus);
	}
	
	public double getBonus() {
		return bonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}

	@Override
	public String toString() {
		return "Manager [name=" + getName() + ", salary=" + getSalary() + ", bonus=" + bonus +"]";
	}
}
