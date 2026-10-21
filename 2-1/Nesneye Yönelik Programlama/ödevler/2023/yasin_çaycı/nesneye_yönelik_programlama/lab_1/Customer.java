package selahattinyasincayci;

import java.util.ArrayList;

public class Customer {
	
	private String name;
	private int identityID;
	private ArrayList<Rezervation> rezervations;
	
	public Customer(String name, int identityID) {
		this.name = name;
		this.identityID = identityID;
		rezervations = new ArrayList<>();
	}
	
	public void makeRezervation(Hotel hotel, String roomType, int day) {
		for (Room room : hotel.getRooms()) {
			if(room.getRoomType().equalsIgnoreCase(roomType)) {
				if(room.isAvailable()) {
					Rezervation a = new Rezervation(hotel,room.getRoomNumber(),day);
					rezervations.add(a);
					break;
				} else {
					System.out.println("Sectiginiz oda tipi icin musaitlik bulunamadi.");
					room.setAvailable(false);
				}
			}
		}
	}
	
	public void getInvoice(int rezervationID) {
		for (Rezervation rezervation : rezervations) {
			if(rezervation.getRezervationID() == rezervationID) {
				rezervation.calculatePayment();
			}
		}
	}
	
	public void listCustomerRezervations() {
		for (Rezervation rezervation : rezervations) {
			System.out.println(rezervation);
		}
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getIdentityID() {
		return identityID;
	}

	public void setIdentityID(int identityID) {
		this.identityID = identityID;
	}

	public ArrayList<Rezervation> getRezervations() {
		return rezervations;
	}

	public void setRezervations(ArrayList<Rezervation> rezervations) {
		this.rezervations = rezervations;
	}
	
	
	
}
