package BerkayGumusay;

import java.util.Arrays;

public class Hotel {
	private String hotelName;
	private String adress;
	private String telephone;
	private Room[] rooms = new Room[4];
	
	
	
	public Hotel(String hotelName, String adress, String telephone) {
		super();
		this.hotelName = hotelName;
		this.adress = adress;
		this.telephone = telephone;
        rooms[0] = new Room(101, "standart",100);
        rooms[1] = new Room(201, "family",200);
        rooms[2] = new Room(301,"suit",400);
        rooms[3] = new Room(302,"suit",400);
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

	public Room[] getRooms() {
		return rooms;
	}

	public void setRooms(Room[] rooms) {
		this.rooms = rooms;
	}

	public String toString() {
		return "Hotel [hotelName=" + hotelName + ", adress=" + adress + ", telephone=" + telephone + ", rooms="
				+ Arrays.toString(rooms) + "]";
	}
}