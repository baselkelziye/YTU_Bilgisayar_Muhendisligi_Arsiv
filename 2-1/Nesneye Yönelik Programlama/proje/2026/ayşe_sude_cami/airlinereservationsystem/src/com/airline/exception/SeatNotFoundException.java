package com.airline.exception;

/**
 * Koltuk bulunamadığında fırlatılan exception.
 * Geçersiz koltuk numarası girildiğinde kullanılır.
 */
public class SeatNotFoundException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String seatNumber;

    public SeatNotFoundException(String seatNumber) {
        super("Koltuk bulunamadı: " + seatNumber, "SE-002");
        this.seatNumber = seatNumber;
    }

    public String getSeatNumber() {
        return seatNumber;
    }
}
