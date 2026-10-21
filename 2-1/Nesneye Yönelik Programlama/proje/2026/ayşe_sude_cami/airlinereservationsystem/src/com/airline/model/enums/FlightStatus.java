package com.airline.model.enums;

/**
 * Uçuş durumlarını tanımlar.
 */
public enum FlightStatus {
    SCHEDULED("Planlandı"),
    BOARDING("Biniş Başladı"),
    DEPARTED("Kalktı"),
    ARRIVED("Vardı"),
    CANCELLED("İptal Edildi"),
    DELAYED("Gecikti");

    private final String description;

    FlightStatus(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}
