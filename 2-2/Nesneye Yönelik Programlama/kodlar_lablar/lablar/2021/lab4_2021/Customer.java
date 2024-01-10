package lab4_2021;

public class Customer implements java.io.Serializable {


	private static final long serialVersionUID = 1L;
	private int SSN;
	private String name;
	private int days;
	Room room;

	public Customer(int SSN, String name, int days, Room room) {
		this.SSN = SSN;
		this.name = name;
		this.days = days;
		this.room = room;
	}
	
	public Customer(String name, int days) {

		this.name = name;
		this.days = days;
		
	}

	
	
	public int getSSN() {
		return SSN;
	}

	public void setSSN(int sSN) {
		SSN = sSN;
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

	public Room getRoom() {
		return room;
	}

	public void setRoom(Room room) {
		this.room = room;
	}

	
	


	

}
