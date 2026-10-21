package com.airline.model;

import com.airline.model.enums.ReservationStatus;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Random;

/**
 * Bir rezervasyonu temsil eder.
 * Uçuş, yolcu ve koltuk bilgilerini içerir.
 */
public class Reservation implements Serializable {
    private static final long serialVersionUID = 1L;

    private String reservationCode;
    private Flight flight;
    private Passenger passenger;
    private Seat seat;
    private LocalDateTime dateOfReservation;
    private ReservationStatus status;

    /**
     * Yeni bir rezervasyon oluşturur.
     */
    public Reservation(Flight flight, Passenger passenger, Seat seat) {
        this.reservationCode = generateReservationCode();
        this.flight = flight;
        this.passenger = passenger;
        this.seat = seat;
        this.dateOfReservation = LocalDateTime.now();
        this.status = ReservationStatus.PENDING;
    }

    /**
     * 6 karakterlik benzersiz rezervasyon kodu üretir.
     * Örn: "ABC123"
     */
    private String generateReservationCode() {
        String chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        StringBuilder code = new StringBuilder();
        Random random = new Random();
        int i = 0;
        while (i < 6) {
            code.append(chars.charAt(random.nextInt(chars.length())));
            i++;
        }
        return code.toString();
    }

    /**
     * Rezervasyonu onaylar ve koltuğu rezerve eder.
     */
    public void confirm() {
        this.status = ReservationStatus.CONFIRMED;
        if (seat != null) {
            seat.reserve();
        }
    }

    /**
     * Rezervasyonu iptal eder ve koltuğu serbest bırakır.
     */
    public void cancel() {
        this.status = ReservationStatus.CANCELLED;
        if (seat != null) {
            seat.release();
        }
    }

    /**
     * Rezervasyonu tamamlanmış olarak işaretler.
     */
    public void complete() {
        this.status = ReservationStatus.COMPLETED;
    }

    /**
     * Rezervasyonun aktif olup olmadığını kontrol eder.
     */
    public boolean isActive() {
        return status == ReservationStatus.PENDING || status == ReservationStatus.CONFIRMED;
    }

    /**
     * Rezervasyon tarihini formatlanmış olarak döndürür.
     */
    public String getFormattedDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy HH:mm");
        return dateOfReservation.format(formatter);
    }

    /**
     * Rezervasyon özetini döndürür.
     */
    public String getSummary() {
        return String.format("Kod: %s | %s | %s → %s | Koltuk: %s | Durum: %s",
                reservationCode,
                passenger.getFullName(),
                flight.getDeparturePlace(),
                flight.getArrivalPlace(),
                seat.getSeatNum(),
                status.getDescription());
    }

    // Getter ve Setter metodları
    public String getReservationCode() {
        return reservationCode;
    }

    public void setReservationCode(String reservationCode) {
        this.reservationCode = reservationCode;
    }

    public Flight getFlight() {
        return flight;
    }

    public void setFlight(Flight flight) {
        this.flight = flight;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public void setPassenger(Passenger passenger) {
        this.passenger = passenger;
    }

    public Seat getSeat() {
        return seat;
    }

    public void setSeat(Seat seat) {
        this.seat = seat;
    }

    public LocalDateTime getDateOfReservation() {
        return dateOfReservation;
    }

    public void setDateOfReservation(LocalDateTime dateOfReservation) {
        this.dateOfReservation = dateOfReservation;
    }

    public ReservationStatus getStatus() {
        return status;
    }

    public void setStatus(ReservationStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return String.format("Reservation{code='%s', passenger='%s', flight='%s', seat='%s', status=%s}",
                reservationCode, passenger.getFullName(), flight.getFlightNum(),
                seat.getSeatNum(), status);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Reservation that = (Reservation) o;
        return reservationCode != null && reservationCode.equals(that.reservationCode);
    }

    @Override
    public int hashCode() {
        return reservationCode != null ? reservationCode.hashCode() : 0;
    }
}
