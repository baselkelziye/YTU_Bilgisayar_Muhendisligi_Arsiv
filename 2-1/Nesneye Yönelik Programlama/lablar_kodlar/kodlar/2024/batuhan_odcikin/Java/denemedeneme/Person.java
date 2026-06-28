package paket1;

public class Person {
	private String name;
	private String surname;
	private int age;
	private Car car;
	
	public Person(String name,String surname,int age) {
		this.name = name;
		this.surname = surname;
		this.age = age;
	}
	
	public Person() {
		this.car = new Car();
	}
	
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return this.name;
	}
	
	public void setSurname(String surname) {
		this.surname = surname;
	}
	public String getSurname() {
		return this.surname;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	public int getAge() {
		return this.age;
	}
	
	public void setCar(Car car) {
		this.car = car;
	}
	public Car getCar() {
		if(this.car != null) {
			return this.car;
		}
		else{
			return null;
		}
	}
}
