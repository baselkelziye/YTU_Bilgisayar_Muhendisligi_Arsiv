package res_sys_pkg;

import java.util.ArrayList;

public class Table {
	private int tableNumber;
	private int seats;
	private boolean available;
	private ArrayList<Reservation> reservations;
	private static final int MAX_RESERVATION = 4;
	private int currentReservations;

	public Table(int tableNumber, int seats) {
		this.tableNumber = tableNumber;
		this.seats = seats;
		this.available = true;
		this.reservations = new ArrayList<Reservation>();
		this.currentReservations = 0;
	}

	public int getTableNumber() {
		return tableNumber;
	}

	public void setTableNumber(int tableNumber) {
		this.tableNumber = tableNumber;
	}

	public int getSeats() {
		return seats;
	}

	public void setSeats(int seats) {
		this.seats = seats;
	}

	public boolean isAvailable() {
		return available;
	}

	public void setAvailable(boolean available) {
		this.available = available;
	}
	
	public void addReservation(Reservation reservation){
		if(currentReservations < MAX_RESERVATION) {
			reservations.add(reservation);
			currentReservations = reservations.size();
			System.out.println("Reservation added. Current reservations:" + currentReservations);
			
			if(currentReservations >= MAX_RESERVATION) {
				this.available = false;
				}
			
			}
		else {
			System.out.println("Can't add reservation, Table" + tableNumber + " is full!!");
		}
	}
	public void removeReservation(Reservation reservation){
		if(reservations.remove(reservation)) {
			currentReservations = reservations.size();
			System.out.println("Reservation removed. Current reservations:" + currentReservations);
			if(currentReservations < MAX_RESERVATION) {
				this.available = true;
			}
		}
		else {
			System.out.println("Reservation can't found.");
		}
	}
	
	public void getReservations() {
		if(reservations.isEmpty() == false) {
			System.out.println("Reservations for table " + tableNumber + ":");
			for(Reservation res:reservations) {
				System.out.println(res.toString());
			}
		}
		else {
			System.out.println("This table does not have any reservations to list!");
		}
	}
	
	
	
	
}
