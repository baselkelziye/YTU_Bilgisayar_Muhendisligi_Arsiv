package batuhanodcikin;

public class CommercialCar extends Car{
	// fuel usage 0.1
	public CommercialCar(int Id, String brand, String model, double dailyRentalPrice ) {
		super(Id, brand, model, dailyRentalPrice);
	}

	@Override
	public double calculateFuelCosts(int distance, double fuel_cost) {
		return distance * 0.1 * fuel_cost;
	}
	
}
