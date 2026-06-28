package yusufsafakoksal;

public class Staff {
	private String name;
	private double salary;
	
	public Staff(String name, double salary) {
		this.name=name;
		this.salary=salary;
	}
	
	public String getName() {
		return name;
	}

	public double getSalary() {
		return salary;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public void increaseSalary(double percentage) {
		salary+=salary*percentage/100;
	}
}
