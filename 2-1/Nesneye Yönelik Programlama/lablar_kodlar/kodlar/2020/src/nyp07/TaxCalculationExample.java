package nyp07;

/* Class code is incomplete.
 * No need to dwell on arrays as we will move on to generic lists and maps. */
public class TaxCalculationExample {

	public static void main(String[] args) {
		//Bus aBus = new Bus("34 OB 1234", 2010, 1.6);
		Car aCar = new Car("34 A 4321", 2015, 1.8);
		System.out.println("Arabanýn vergisi: " + aCar.calculateTax(1000));
		System.out.println("Arabanýn vergisi: " + aCar.calculateAmortizedTax(1000,2017));
		CommercialVehicle myCar = new Car("34 B 123", 2014, 1.6);
		System.out.println("Arabanýn vergisi: " + myCar.calculateAmortizedTax(1000,2017));
		/*
		VehicleRegistrationSystem vrs = new VehicleRegistrationSystem();
		vrs.registerCommercialVehicle(aCar);*/
	}
}
