package com.airline.exception;

/**
 * Koltuk müsait olmadığında fırlatılan exception.
 * Koltuk zaten rezerve edilmiş veya başka bir nedenle kullanılamaz durumda.
 */
public class SeatNotAvailableException extends AirlineException {
    private static final long serialVersionUID = 1L;

    private final String seatNumber;

    public SeatNotAvailableException(String seatNumber) {
        super("Koltuk müsait değil: " + seatNumber, "SE-001");
        this.seatNumber = seatNumber;
    }

    public SeatNotAvailableException(String seatNumber, String reason) {
        super("Koltuk müsait değil: " + seatNumber + " - " + reason, "SE-001");
        this.seatNumber = seatNumber;
    }

    public String getSeatNumber() {
        return seatNumber;
    }
}
