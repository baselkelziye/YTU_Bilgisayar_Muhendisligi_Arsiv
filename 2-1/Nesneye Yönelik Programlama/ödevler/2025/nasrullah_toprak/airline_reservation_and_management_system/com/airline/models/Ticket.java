package com.airline.models;

public class Ticket {
    private String ticketID;
    private Reservation reservation;
    private double price;
    private Baggage baggageAllowance;

    public Ticket(String ticketID, Reservation reservation, double price, Baggage baggageAllowance) {
        this.ticketID = ticketID;
        this.reservation = reservation;
        this.price = price;
        this.baggageAllowance = baggageAllowance;
    }

    public String getTicketID() {
        return ticketID;
    }

    public Reservation getReservation() {
        return reservation;
    }

    public double getPrice() {
        return price;
    }

    public Baggage getBaggageAllowance() {
        return baggageAllowance;
    }
}
