package nyp01a;

public class Car {
	private String plate;

	public Car( String plateNr ) {
		plate = plateNr;
	}   
	public String getPlate() {
		return plate;
	}
	public void setPlate(String plate) {
		this.plate = plate;
	}
	public void introduceSelf( ) {
		System.out.println( "My plate: " + getPlate() );
	}
	public static void main( String[] args ) {
		Car aCar;
		aCar = new Car( "34 RA 440" );
		aCar.introduceSelf( );
		Car anotherCar = new Car("06 ANK 06");
		anotherCar.introduceSelf();
		aCar.setPlate( anotherCar.getPlate() );
		aCar.introduceSelf();
		System.out.println("The End");
	}
}
