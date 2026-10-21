package com.airline.models;

import java.time.LocalDateTime;

public class Reservation {
    private String reservationCode;
    private Flight flight;
    private Passenger passenger;
    private Seat seat;
    private LocalDateTime dateOfReservation;

    public Reservation(String reservationCode, Flight flight, Passenger passenger, Seat seat) {
        this.reservationCode = reservationCode;
        this.flight = flight;
        this.passenger = passenger;
        this.seat = seat;
        this.dateOfReservation = LocalDateTime.now();
    }

    public String getReservationCode() {
        return reservationCode;
    }

    public Flight getFlight() {
        return flight;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public Seat getSeat() {
        return seat;
    }

    public LocalDateTime getDateOfReservation() {
        return dateOfReservation;
    }
}
