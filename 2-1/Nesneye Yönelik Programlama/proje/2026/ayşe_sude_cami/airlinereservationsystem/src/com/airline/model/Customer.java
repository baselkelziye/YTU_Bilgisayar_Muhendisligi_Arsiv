package com.airline.model;

import com.airline.model.enums.UserRole;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Customer extends User {
	private static final long serialVersionUID = 1L;

	private Passenger passenger;
	private List<Reservation> reservationHistory;

	public Customer(String username, String password, String email) {
		super(username, password, email, UserRole.CUSTOMER);
		this.reservationHistory = new ArrayList<>();
	}

	public Customer(String username, String password, String email, Passenger passenger) {
		super(username, password, email, UserRole.CUSTOMER);
		this.passenger = passenger;
		this.reservationHistory = new ArrayList<>();
	}

	public Customer(String userId, String username, String password, String email) {
		super(userId, username, password, email, UserRole.CUSTOMER);
		this.reservationHistory = new ArrayList<>();
	}

	@Override
	public List<String> getPermissions() {
		return Arrays.asList(
			"SEARCH_FLIGHTS",
			"VIEW_FLIGHT_DETAILS",
			"MAKE_RESERVATION",
			"VIEW_OWN_RESERVATIONS",
			"CANCEL_OWN_RESERVATION",
			"VIEW_TICKET",
			"UPDATE_PROFILE"
		);
	}

	/**
	 * Müşterinin rezervasyonlarını döndürür.
	 */
	public List<Reservation> viewReservations() {
		return new ArrayList<>(reservationHistory);
	}

	/**
	 * Yeni rezervasyon ekler.
	 */
	public void addReservation(Reservation reservation) {
		if (reservation != null) {
			reservationHistory.add(reservation);
		}
	}

	/**
	 * Rezervasyonu geçmişten kaldırır.
	 */
	public void removeReservation(Reservation reservation) {
		reservationHistory.remove(reservation);
	}

	/**
	 * Aktif rezervasyon sayısını döndürür.
	 */
	public int getActiveReservationCount() {
		int count = 0;
		java.util.Iterator<Reservation> iterator = reservationHistory.iterator();
		while (iterator.hasNext()) {
			Reservation r = iterator.next();
			if (r.isActive()) {
				count++;
			}
		}
		return count;
	}

	// Getter ve Setter metodları
	public Passenger getPassenger() {
		return passenger;
	}

	public void setPassenger(Passenger passenger) {
		this.passenger = passenger;
	}

	public List<Reservation> getReservationHistory() {
		return reservationHistory;
	}

	public void setReservationHistory(List<Reservation> reservationHistory) {
		this.reservationHistory = reservationHistory;
	}

	@Override
	public String toString() {
		return String.format("Customer{id='%s', username='%s', passenger='%s', reservations=%d}",
				getUserId(), getUsername(),
				passenger != null ? passenger.getFullName() : "N/A",
				reservationHistory.size());
	}
}
