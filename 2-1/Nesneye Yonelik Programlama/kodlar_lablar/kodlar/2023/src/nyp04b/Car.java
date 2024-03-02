package nyp04b;
public class Car {
	private String plate;
	private Person owner;
	private Gallery gallery;

	public Car( String plate, Person owner, Gallery gallery ) {
		this.plate = plate;
		this.owner = owner;
		this.gallery = gallery;
		this.gallery.addCar(this);
	}
	public void setOwner( Person owner ) { 
		this.owner = owner;
	}
	public Person getOwner() { return owner; }
	public String getPlate( ) { return plate; }
	public void setPlate( String plate ) { this.plate = plate; }
	public String introduceSelf( ) {
		String intro;
		intro = "[CAR] My license plate is " + getPlate();
		if( owner != null )
			intro += " and my owner is " + owner.getName();
		return intro;
	}
}
