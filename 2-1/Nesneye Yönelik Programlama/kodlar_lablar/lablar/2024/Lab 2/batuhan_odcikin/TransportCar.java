package batuhanodcikin;

public class TransportCar extends Car {
	// fuel usage 0.2
	private int passangerCapacity;
	
	public TransportCar(int Id, String brand, String model, double dailyRentalPrice , int passangerCapacity) {
		super(Id, brand, model, dailyRentalPrice);
		this.passangerCapacity = passangerCapacity;
	}

	@Override
	public double calculateFuelCosts(int distance, double fuel_cost) {
		return distance * 0.2 * fuel_cost;
	}
}
