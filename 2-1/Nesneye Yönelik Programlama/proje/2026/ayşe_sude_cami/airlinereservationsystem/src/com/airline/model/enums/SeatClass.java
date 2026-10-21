package com.airline.model.enums;

/**
 * Koltuk sınıflarını tanımlar.
 * ECONOMY: Ekonomi sınıfı - standart fiyat, 20kg bagaj hakkı
 * BUSINESS: Business sınıfı - 2x fiyat, 40kg bagaj hakkı
 */
public enum SeatClass {
    ECONOMY(1.0, 23, "Ekonomi"),
    BUSINESS(2.0, 35, "Business");

    private final double priceMultiplier;
    private final int baggageAllowance;
    private final String displayName;

    SeatClass(double priceMultiplier, int baggageAllowance, String displayName) {
        this.priceMultiplier = priceMultiplier;
        this.baggageAllowance = baggageAllowance;
        this.displayName = displayName;
    }

    public double getPriceMultiplier() {
        return priceMultiplier;
    }

    public int getBaggageAllowance() {
        return baggageAllowance;
    }

    public String getDisplayName() {
        return displayName;
    }

    @Override
    public String toString() {
        return displayName;
    }
}
