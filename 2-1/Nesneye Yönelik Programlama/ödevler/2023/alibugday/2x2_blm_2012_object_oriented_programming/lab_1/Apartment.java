package lab1_19011076;

public class Apartment extends Home {
	private double dues;
	
	public Apartment(double price, String location, double dues) {
		super(price, location);
		this.dues = dues;
	}
	
	public double discountedPrice() {
		return getPrice()-(getPrice()*0.05);
	}

	public double getDues() {
		return dues;
	}

	public void setDues(double dues) {
		this.dues = dues;
	}

	@Override
	public String toString() {
		return "Home Category: Apartment dues=" + dues + ", price=" + price + ", location=" + location;
	}
	
	
}
