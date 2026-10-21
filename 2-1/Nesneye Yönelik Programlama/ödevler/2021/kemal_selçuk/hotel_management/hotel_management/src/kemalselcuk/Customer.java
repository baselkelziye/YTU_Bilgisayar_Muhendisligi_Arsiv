package kemalselcuk;

public class Customer implements java.io.Serializable {
	private int id;
	private String name;
	private int days;
	private Room r;
	public Customer(int id, String name, int days, Room r) {
		this.id = id;
		this.name = name;
		this.days = days;
		this.r = r;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getDays() {
		return days;
	}
	public void setDays(int days) {
		this.days = days;
	}
	public Room getR() {
		return r;
	}
	public void setR(Room r) {
		this.r = r;
	}
	public int getId() {
		return id;
	}
	@Override
	public String toString() {
		return "Customer [id=" + id + ", name=" + name + ", days=" + days + ", r=" + r.getNo() + "]";
	}
	
	
	
}
