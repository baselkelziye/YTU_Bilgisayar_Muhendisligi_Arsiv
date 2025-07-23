package java_deneme;

public class Car {
	private String plate;
	private String chassisNbr;
	public Car (String plateNbr, String chassisNbr) {
		plate = plateNbr;
		this.chassisNbr = chassisNbr;
	}
	public String getPlate() {
		return this.plate;
	}
	
	public void setPlate(String plate) {
		this.plate = plate;
	}
	
	public String getChassis() {
		return this.chassisNbr;
	}
}
	