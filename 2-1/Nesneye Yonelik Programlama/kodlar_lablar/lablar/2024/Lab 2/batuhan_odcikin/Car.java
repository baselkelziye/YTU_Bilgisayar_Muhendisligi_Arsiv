package batuhanodcikin;

public abstract class Car {
	protected int Id;
	protected String brand;
	protected String model;
	protected double dailyRentalPrice;
	
	public Car(int Id, String brand, String model, double dailyRentalPrice) {
		this.Id = Id;
		this.brand = brand;
		this.model = model;
		this.dailyRentalPrice = dailyRentalPrice;
	}
	
	public abstract double calculateFuelCosts(int distance, double fuel_cost);
}
