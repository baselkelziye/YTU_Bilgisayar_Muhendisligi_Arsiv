package res_sys_pkg;

import java.util.ArrayList;

public class Customer {
	private String name;
	private String phone_nbr;
	private ArrayList<Reservation> reservation_arr;
	
	public Customer(String name, String phone_nbr) {
		this.name = name;
		this.phone_nbr = phone_nbr;
		reservation_arr = new ArrayList<Reservation>();
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getPhone_nbr() {
		return this.phone_nbr;
	}
	
	public void addReservation(Reservation reservation) {
		reservation_arr.add(reservation);
	}
	public void removeReservation(Reservation reservation) {
		reservation_arr.remove(reservation);
	}
	
	public void listReservations() {
		if(reservation_arr.isEmpty() == true) {
			System.out.println("This customer does not have any Reservations !!");
		}
		else {
			System.out.println("Reservation list for " + this.name);
			for(Reservation res: reservation_arr) {
				System.out.println(res.toString());
			}
		}
	}
}
