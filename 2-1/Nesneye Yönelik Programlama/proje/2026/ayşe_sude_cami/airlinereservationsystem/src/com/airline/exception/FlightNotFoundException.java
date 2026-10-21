package com.airline.exception;

/**
 * Uçuş bulunamadığında fırlatılan exception.
 * Geçersiz uçuş numarası sorgulandığında kullanılır.
 */
public class FlightNotFoundException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String flightNumber;

    public FlightNotFoundException(String flightNumber) {
        super("Uçuş bulunamadı: " + flightNumber, "FL-001");
        this.flightNumber = flightNumber;
    }

    public String getFlightNumber() {
        return flightNumber;
    }
}
