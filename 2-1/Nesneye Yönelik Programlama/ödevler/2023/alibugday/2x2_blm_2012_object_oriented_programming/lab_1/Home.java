package lab1_19011076;

public abstract class Home {
	protected double price;
	protected String location;
	
	
	public Home(double price, String location) {
		this.location = location;
		this.price = price;
	}
	
	public abstract double discountedPrice();

	public double getPrice() {
		return price;
	}

	public String getLocation() {
		return location;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	
	
	
	
}
