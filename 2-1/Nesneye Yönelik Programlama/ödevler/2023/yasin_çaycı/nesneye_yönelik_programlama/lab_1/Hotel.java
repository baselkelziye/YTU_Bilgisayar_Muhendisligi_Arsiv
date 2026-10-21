package selahattinyasincayci;

import java.util.ArrayList;

public class Hotel {
	private String hotelName;
	private String adress;
	private String telephone;
	private ArrayList<Room> rooms;
	
	public Hotel(String hotelName, String adress, String telephone) {
		this.hotelName = hotelName;
		this.adress = adress;
		this.telephone = telephone;
		rooms = new ArrayList<>();
		
		Room a = new Room(101, "standart",100);
		Room b = new Room(201, "family",200);
		Room c = new Room(301,"suit",400);
		Room d = new Room(302,"suit",400);
		rooms.add(a);
		rooms.add(b);
		rooms.add(c);
		rooms.add(d);
	}

	public String getHotelName() {
		return hotelName;
	}

	public void setHotelName(String hotelName) {
		this.hotelName = hotelName;
	}

	public String getAdress() {
		return adress;
	}

	public void setAdress(String adress) {
		this.adress = adress;
	}

	public String getTelephone() {
		return telephone;
	}

	public void setTelephone(String telephone) {
		this.telephone = telephone;
	}

	public ArrayList<Room> getRooms() {
		return rooms;
	}

	public void setRooms(ArrayList<Room> rooms) {
		this.rooms = rooms;
	}

	@Override
	public String toString() {
		return "Hotel [hotelName=" + hotelName + "]";
	}
	
	
	
	
	
	
}
