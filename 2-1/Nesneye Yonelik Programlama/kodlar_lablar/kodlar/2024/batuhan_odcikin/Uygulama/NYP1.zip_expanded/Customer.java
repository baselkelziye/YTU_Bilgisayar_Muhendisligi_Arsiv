package nyp1;

import java.util.ArrayList;
import java.util.List;

public class Customer {

	private String name;
	private String phoneNumber;
	private List<Reservation> reservations;
	
	
	public Customer(String name, String phoneNumber) {
		this.name = name;
		this.phoneNumber = phoneNumber;
		this.reservations = new ArrayList<>();
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public String getPhoneNumber() {
		return phoneNumber;
	}


	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}
	
	// methods to manage reservations
	public void addReservation(Reservation reservation) {
		reservations.add(reservation);
	}
	
	public void removeReservation(Reservation reservation) {
		reservations.remove(reservation);
	}
	
	
    public void listReservations() {
        if (reservations.isEmpty()) {
            System.out.println("No reservations for this customer.");
        } else {
            System.out.println("Reservations for customer " + name + ":");
            for (Reservation reservation : reservations) {
                System.out.println(reservation.toString());
            }
        }
    }
	
}
