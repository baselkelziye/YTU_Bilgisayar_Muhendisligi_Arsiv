package selahattinyasincayci;

public class Room {
	private int roomNumber;
	private String roomType;
	private double price;
	private boolean isAvailable = true;
	
	public Room(int roomNumber, String roomType, double price) {
		this.roomNumber = roomNumber;
		this.roomType = roomType;
		this.price = price;
	}

	public int getRoomNumber() {
		return roomNumber;
	}

	public void setRoomNumber(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public String getRoomType() {
		return roomType;
	}

	public void setRoomType(String roomType) {
		this.roomType = roomType;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public void setAvailable(boolean isAvailable) {
		this.isAvailable = isAvailable;
	}
	
	public boolean isAvailable() {
		return isAvailable;
	}
	
	
}
