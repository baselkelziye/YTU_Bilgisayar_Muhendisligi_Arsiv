package nyp07;

public class Car implements CommercialVehicle, PersonalVehicle {
	private String plate;
	private int modelYear;
	private double engineVolume;

	public Car(String plate, int modelYear, double engineVolume) {
		this.plate = plate;
		this.modelYear = modelYear;
		this.engineVolume = engineVolume;
	}
	public double calculateTax( double baseTax ) {
		return baseTax * engineVolume;
	}
	public double calculateAmortizedTax( double baseTax, int currentYear ) {
		//Tax can be reduced %10 for each year as amortization for light vehicles
		//%10 = 0.1 = ((double)1/CommercialVehicle.yearLimit)
		int age = currentYear - modelYear;
		if( age < CommercialVehicle.yearLimit )
			return baseTax * engineVolume * (1-age*((double)1/CommercialVehicle.yearLimit));
		return baseTax * engineVolume * ((double)1/CommercialVehicle.yearLimit);
	}
    public String getPlate() { return plate; }
	public int getModelYear() { return modelYear; }
	public double getEngineVolume() { return engineVolume; }
}
