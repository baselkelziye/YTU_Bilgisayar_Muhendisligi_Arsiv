package lab1_19011076;

public class Villa extends Home{
	
	public Villa(double price, String location) {
		super(price,location);
	}
	
	public double discountedPrice() {
		return getPrice()-(getPrice()*0.1);
	}

	@Override
	public String toString() {
		return "Home catagory: Villa, price=" + price + ", location=" + location;
	}
	
	
	
	
}
