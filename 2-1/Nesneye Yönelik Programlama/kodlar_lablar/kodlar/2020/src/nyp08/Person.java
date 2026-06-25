package nyp08;

public class Person {
	private String name;
	private Subscription subscription;

	public Person(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}
	
	public String toString( ) {
		return name + ", " + subscription;
	}

	public void subscribeTo(Tariff aTariff) {
		subscription = new Subscription(aTariff);
	}

}
