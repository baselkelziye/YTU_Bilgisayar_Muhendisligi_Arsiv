package com.airline.model.enums;

/**
 * Rezervasyon durumlarını tanımlar.
 */
public enum ReservationStatus {
    PENDING("Beklemede"),
    CONFIRMED("Onaylandı"),
    CANCELLED("İptal Edildi"),
    COMPLETED("Tamamlandı");

    private final String description;

    ReservationStatus(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}
