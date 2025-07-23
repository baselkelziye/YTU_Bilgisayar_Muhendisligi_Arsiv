package batuhanodcikin;

public class PassengerCar extends Car{
	// fuel usage 0.05
	public PassengerCar(int Id, String brand, String model, double dailyRentalPrice ) {
		super(Id, brand, model, dailyRentalPrice);
	}

	@Override
	public double calculateFuelCosts(int distance, double fuel_cost) {
		return distance * 0.05 * fuel_cost;
	}
	
}
