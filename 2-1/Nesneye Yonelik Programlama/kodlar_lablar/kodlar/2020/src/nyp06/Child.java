package nyp06;

public class Child {
	private final String name;
	private int ageInMonths;
	public Child(String name, int age) {
		this.name = name;
		this.ageInMonths = age;
	}
	public String getName() {
		return name;
	}
	public int getAgeInMonths() {
		return ageInMonths;
	}
	public void setAgeInMonths(int age) {
		this.ageInMonths = age;
	}
}
