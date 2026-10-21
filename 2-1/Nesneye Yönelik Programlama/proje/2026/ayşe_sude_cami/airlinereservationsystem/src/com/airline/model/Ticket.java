package com.airline.model;

import com.airline.model.enums.TicketStatus;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.UUID;

/**
 * Bir bileti temsil eder.
 * Rezervasyon, fiyat ve bagaj bilgilerini içerir.
 */
public class Ticket implements Serializable {
    private static final long serialVersionUID = 2L;

    private String ticketId;
    private Reservation reservation;
    private double price;
    private Baggage baggage;
    private int baggageAllowance;
    private LocalDateTime issueDate;
    private TicketStatus ticketStatus;

    /**
     * Yeni bir bilet oluşturur.
     */
    public Ticket(Reservation reservation, double price) {
        this.ticketId = generateTicketId();
        this.reservation = reservation;
        this.price = price;
        this.issueDate = LocalDateTime.now();
        this.ticketStatus = TicketStatus.ISSUED;

        // Bagaj hakkını koltuk sınıfına göre ayarla
        this.baggageAllowance = reservation.getSeat().getClass_().getBaggageAllowance();
        this.baggage = new Baggage(0, baggageAllowance);
    }

    /**
     * Bagaj ile birlikte bilet oluşturur.
     */
    public Ticket(Reservation reservation, double price, Baggage baggage) {
        this.ticketId = generateTicketId();
        this.reservation = reservation;
        this.price = price;
        this.baggage = baggage;
        this.baggageAllowance = baggage != null ? baggage.getAllowance() : 0;
        this.issueDate = LocalDateTime.now();
        this.ticketStatus = TicketStatus.ISSUED;
    }

    private String generateTicketId() {
        return "TKT-" + UUID.randomUUID().toString().substring(0, 10).toUpperCase();
    }

    /**
     * Toplam fiyatı hesaplar (bilet + bagaj ek ücreti).
     */
    public double calculateTotalPrice() {
        double total = price;
        if (baggage != null) {
            total += baggage.getExtraFee();
        }
        return total;
    }

    /**
     * Check-in yapar.
     */
    public void checkIn() {
        this.ticketStatus = TicketStatus.CHECKED_IN;
    }

    /**
     * Uçağa biniş işlemini yapar.
     */
    public void board() {
        this.ticketStatus = TicketStatus.BOARDED;
    }

    /**
     * Bileti kullanılmış olarak işaretler.
     */
    public void use() {
        this.ticketStatus = TicketStatus.USED;
    }

    /**
     * Bileti iade eder.
     */
    public void refund() {
        this.ticketStatus = TicketStatus.REFUNDED;
        if (reservation != null) {
            reservation.cancel();
        }
    }

    /**
     * Bilet bilgilerini özet olarak döndürür.
     */
    public String getTicketSummary() {
        StringBuilder sb = new StringBuilder();
        sb.append("═══════════════════════════════════════\n");
        sb.append("           UÇAK BİLETİ\n");
        sb.append("═══════════════════════════════════════\n");
        sb.append(String.format("Bilet No    : %s\n", ticketId));
        sb.append(String.format("Yolcu       : %s\n", reservation.getPassenger().getFullName()));
        sb.append(String.format("Uçuş        : %s\n", reservation.getFlight().getFlightNum()));
        sb.append(String.format("Rota        : %s → %s\n",
                reservation.getFlight().getDeparturePlace(),
                reservation.getFlight().getArrivalPlace()));
        sb.append(String.format("Tarih       : %s\n", reservation.getFlight().getDate()));
        sb.append(String.format("Saat        : %s\n", reservation.getFlight().getHour()));
        sb.append(String.format("Koltuk      : %s (%s)\n",
                reservation.getSeat().getSeatNum(),
                reservation.getSeat().getClass_()));
        sb.append(String.format("Fiyat       : %.2f TL\n", price));
        if (baggage != null && baggage.getExtraFee() > 0) {
            sb.append(String.format("Bagaj Ek    : %.2f TL\n", baggage.getExtraFee()));
        }
        sb.append(String.format("TOPLAM      : %.2f TL\n", calculateTotalPrice()));
        sb.append("═══════════════════════════════════════\n");
        return sb.toString();
    }

    /**
     * Düzenleme tarihini formatlanmış olarak döndürür.
     */
    public String getFormattedIssueDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd.MM.yyyy HH:mm");
        return issueDate.format(formatter);
    }

    // Getter ve Setter metodları
    public String getTicketId() {
        return ticketId;
    }

    public void setTicketId(String ticketId) {
        this.ticketId = ticketId;
    }

    public Reservation getReservation() {
        return reservation;
    }

    public void setReservation(Reservation reservation) {
        this.reservation = reservation;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public Baggage getBaggage() {
        return baggage;
    }

    public void setBaggage(Baggage baggage) {
        this.baggage = baggage;
    }

    public int getBaggageAllowance() {
        return baggageAllowance;
    }

    public void setBaggageAllowance(int baggageAllowance) {
        this.baggageAllowance = baggageAllowance;
    }

    public LocalDateTime getIssueDate() {
        return issueDate;
    }

    public void setIssueDate(LocalDateTime issueDate) {
        this.issueDate = issueDate;
    }

    public TicketStatus getTicketStatus() {
        return ticketStatus;
    }

    public void setTicketStatus(TicketStatus ticketStatus) {
        this.ticketStatus = ticketStatus;
    }

    @Override
    public String toString() {
        return String.format("Ticket{id='%s', passenger='%s', flight='%s', price=%.2f, status=%s}",
                ticketId, reservation.getPassenger().getFullName(),
                reservation.getFlight().getFlightNum(), price, ticketStatus);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Ticket ticket = (Ticket) o;
        return ticketId != null && ticketId.equals(ticket.ticketId);
    }

    @Override
    public int hashCode() {
        return ticketId != null ? ticketId.hashCode() : 0;
    }
}
