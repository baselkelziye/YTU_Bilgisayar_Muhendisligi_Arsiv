package nyp01d;
import java.util.*;

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
		Scanner input = new Scanner( System.in );
		System.out.print("Enter a license plate: ");
		aCar = new Car( input.nextLine( ) );
		aCar.introduceSelf( );
		input.close();
	}
}
