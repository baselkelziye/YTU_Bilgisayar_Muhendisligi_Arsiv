package selahattinyasincayci;

public class Rezervation {
	
	private static int counter = 20230001;
	private int rezervationID;
	private Hotel hotel;
	private int roomNumber;
	private int day;
	
	public Rezervation(Hotel hotel, int roomNumber, int day) {
		this.hotel = hotel;
		this.roomNumber = roomNumber;
		this.day = day;
		this.rezervationID = counter;
		counter++;
	}
	
	public void calculatePayment() {
		for (Room room : hotel.getRooms()) {
			if(room.getRoomNumber() == roomNumber) {
				double payment = day * room.getPrice();
				System.out.println(day + " gunluk odeme tutari: " + payment);
			}
		}
	}
	
	public int getRezervationID() {
		return rezervationID;
	}

	public void setRezervationID(int rezervationID) {
		this.rezervationID = rezervationID;
	}

	public Hotel getHotel() {
		return hotel;
	}

	public void setHotel(Hotel hotel) {
		this.hotel = hotel;
	}

	public int getRoomNumber() {
		return roomNumber;
	}

	public void setRoomNumber(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	@Override
	public String toString() {
		return "Rezervation [rezervationID=" + rezervationID + ", hotel=" + hotel + ", roomNumber=" + roomNumber
				+ ", day=" + day + "]";
	}
	
	
	
	
}
