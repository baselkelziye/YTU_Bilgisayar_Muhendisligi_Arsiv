package com.airline.model.enums;

/**
 * Bilet durumlarını tanımlar.
 */
public enum TicketStatus {
    ISSUED("Düzenlendi"),
    CHECKED_IN("Check-in Yapıldı"),
    BOARDED("Uçağa Bindi"),
    USED("Kullanıldı"),
    REFUNDED("İade Edildi");

    private final String description;

    TicketStatus(String description) {
        this.description = description;
    }

    public String getDescription() {
        return description;
    }
}
