package tariktaskin;

import java.util.List;

public class SalaryIncreaseThread implements Runnable{
	private List<Employee> employees;
	private double increasePercentage;

	public SalaryIncreaseThread(List<Employee> employees, double increasePercentage) {
		super();
		this.employees = employees;
		this.increasePercentage = increasePercentage;
	}

	@Override
	public void run() {
		for(Employee i : employees) {
			i.increaseSalary(increasePercentage);
		}
		
	}
	
	
}
