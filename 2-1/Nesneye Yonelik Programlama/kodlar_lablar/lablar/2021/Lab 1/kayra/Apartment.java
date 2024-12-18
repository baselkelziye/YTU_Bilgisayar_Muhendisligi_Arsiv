package muhammetkayrabulut;

public class Apartment extends Home{
	private double dues;
	public Apartment(double price,String location,double dues) {
		super(price, location);
		this.dues=dues;
	}
	public String toString() {
		return "Evin kategorisi: Apartman, Ucreti " + super.getPrice() + " ,Lokasyonu: "+ super.getLocation() + " Aylik kirasi: " + dues;
	}
	public double discountedPrice() {
		return super.getPrice()*0.95;
	}
	public double getDues() {
		return dues;
	}
	public void setDues(double dues) {
		this.dues = dues;
	}
	
	
}
