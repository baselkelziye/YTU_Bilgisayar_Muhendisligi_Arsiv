package com.airline.managers;

import com.airline.models.Seat;
import com.airline.models.Baggage;

public class CalculatePrice {
    public static double calculateTicketPrice(Seat seat, Baggage baggage) {
        double basePrice = seat.getPrice();
        double baggageFee = 0;
        if (baggage != null && baggage.getWeight() > 15) {
            baggageFee = (baggage.getWeight() - 15) * 10;
        }
        return basePrice + baggageFee;
    }
}