package nyp01b;

public class Car {
	private String plate;
	private int chassisNR;
	public Car( String plateNr ) {
		plate = plateNr;
	}   
	public Car( int chassisNR ) { 
		this.chassisNR = chassisNR;
	}   
	public String getPlate() {
		return plate;
	}
	public void setPlate(String plate) {
		this.plate = plate;
	}
	public int getChassisNR( ) {
		return chassisNR;
	}
	public void setChassisNR(int chassisNR) {
		this.chassisNR = chassisNR;
	}
	public void introduceSelf( ) {
		System.out.print( "My plate is " + getPlate() 
			+ " and my chassis nr is " + getChassisNR() );
	}
}
