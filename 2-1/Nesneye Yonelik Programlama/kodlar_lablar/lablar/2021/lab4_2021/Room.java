package lab4_2021;

@SuppressWarnings("serial")
public class Room implements java.io.Serializable{

	protected int number;
	protected double price;

	public Room(int number, double price) {
		this.number = number;
		this.price = price;
	}

	public int getNumber() {
		return number;
	}

	public void setNumber(int number) {
		this.number = number;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}


	
	
}
