package nyp02;

public class Person {
	private String name;
	private Car car;

	public Person( String name ) {
		this.name = name;
	}
	public String getName( ) { return name; }
	public Car getCar( ) { return car; }
	public void setCar( Car car ) { this.car = car; }
	
	public String introduceSelf( ) {
		String intro;
		intro = "Hello, my name is " + getName();
		if( car != null )
			intro += " and I have a car with license plate " 
				+ car.getPlate();
		intro += ".";
		return intro;
	}
}
