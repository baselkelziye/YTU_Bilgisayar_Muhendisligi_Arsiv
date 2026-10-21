package kemalselcuk;

public class Room implements java.io.Serializable{
	private int no;
	private float price;
	public Room(int no, float price) {
		this.no = no;
		this.price = price;
	}
	public int getNo() {
		return no;
	}
	public void setNo(int no) {
		this.no = no;
	}
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	
}
