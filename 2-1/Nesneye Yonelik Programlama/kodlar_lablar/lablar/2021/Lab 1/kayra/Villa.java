package muhammetkayrabulut;

public class Villa extends Home {
	public Villa(double price, String location) {
		super(price,location);
	}
	public double discountedPrice() {
		return super.getPrice()*0.9;
	}
	public String toString() {
		return "Evin kategorisi: Villa, Ucreti " + super.getPrice() + " ,Lokasyonu: "+ super.getLocation() ;
	}
}
