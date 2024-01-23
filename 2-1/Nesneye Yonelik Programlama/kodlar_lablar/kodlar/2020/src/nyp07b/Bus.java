package nyp07b;

public class Bus implements CommercialVehicle {
	private String plate;
	private int modelYear;
	private double tonnage;

	public Bus(String plate, int modelYear, double tonnage) {
		this.plate = plate;
		this.modelYear = modelYear;
		this.tonnage = tonnage;
	}
	public double calculateAmortizedTax( double baseTax, int currentYear ) {
		double ratioTonnage, ratioAge;
		if( tonnage < 1.0 )
			ratioTonnage = 1.0;
		else if( tonnage < 5.0 )
			ratioTonnage = 1.2;
		else if( tonnage < 10.0 )
			ratioTonnage = 1.4;
		else
			ratioTonnage = 1.6;
		ratioAge = (currentYear - modelYear) * 0.05;
		if( ratioAge > 2.0 )
			ratioAge = 2.0;
		return baseTax * ratioTonnage * ratioAge;
	}
    public String getPlate() { return plate; }
	public int getModelYear() { return modelYear; }
	public double getEngineVolume() { return tonnage; }
}
