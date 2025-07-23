package paket1;

public class Car {
	private String plate;
	private String brand;
	private String model;
	private Person owner;
	/**
	 * @param plate
	 * @param brand
	 * @param model
	 */
	public Car(String plate, String brand, String model) {
		this.plate = plate;
		this.brand = brand;
		this.model = model;
	}
	
	public Car() {
		this.owner = new Person();
	}
	
	public String getPlate() {
		return plate;
	}
	public void setPlate(String plate) {
		this.plate = plate;
	}
	public String getBrand() {
		return brand;
	}
	public void setBrand(String brand) {
		this.brand = brand;
	}
	public String getModel() {
		return model;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public Person getOwner() {
		if(this.owner != null) {
			return this.owner;
		}
		else {
			return null;
		}
	}
	public void setOwner(Person owner) {
		this.owner = owner;
		
	}
	
}
