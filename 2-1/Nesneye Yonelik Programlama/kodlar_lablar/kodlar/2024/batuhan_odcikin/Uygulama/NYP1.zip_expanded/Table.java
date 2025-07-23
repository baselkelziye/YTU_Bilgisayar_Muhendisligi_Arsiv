package nyp1;

import java.util.ArrayList;

import java.util.List;

public class Table {

	private int tableNumber;
	private int seats;
	private boolean available;
	private List<Reservation> reservations;
	private static final int MAX_RESERVATIONS = 4;
	private int currentReservations;
	
	
	// constructor
	public Table(int tableNumber, int seats) {
		this.tableNumber = tableNumber;
		this.seats = seats;
		this.available = true;
		this.reservations = new ArrayList<>();
		this.currentReservations = 0;
	}


	public int getTableNumber() {
		return tableNumber;
	}


	public int getSeats() {
		return seats;
	}


	public boolean isAvailable() {
		return available;
	}


	public int getCurrentReservations() {
		return currentReservations;
	}


	public void setTableNumber(int tableNumber) {
		this.tableNumber = tableNumber;
	}


	public void setSeats(int seats) {
		this.seats = seats;
	}


	public void setAvailable(boolean available) {
		this.available = available;
	}


	public void setCurrentReservation(int currentReservations) {
		this.currentReservations = currentReservations;
	}
	
	
	// methods to manage reservations
	
	public void addReservation(Reservation reservation) {
		if (currentReservations < MAX_RESERVATIONS) {
			reservations.add(reservation);
			currentReservations++;
			
			if (currentReservations == MAX_RESERVATIONS) {
				this.available = false;
			}
			
			System.out.println("Reservation added. Current reservations:" + currentReservations);
		} else {
			
			System.out.println("Reservation cannot added. Maximum reservations reached!");
		}
	}
	
	
	public void removeReservation(Reservation reservation) {
        if (reservations.remove(reservation)) {
            currentReservations--;
            
            this.available = true;
            
            System.out.println("Reservation removed. Current reservations: " + currentReservations);
        } else {
            System.out.println("Reservation not found.");
        }
	}
	
	
    public void getReservations() {
        if (reservations.isEmpty()) {
            System.out.println("No reservations for this table.");
        } else {
            System.out.println("Reservations for table " + tableNumber + ":");
            for (Reservation reservation : reservations) {
                System.out.println(reservation.toString());
            }
        }
    }
	
	
}
 