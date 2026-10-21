package com.airline.model;

import java.io.Serializable;
import java.util.UUID;

/**
 * Bagaj bilgilerini temsil eder.
 * Ağırlık, hak ve ek ücret hesaplaması içerir.
 */
public class Baggage implements Serializable {
    private static final long serialVersionUID = 1L;

    private String baggageId;
    private double weight;      // kg cinsinden gerçek ağırlık
    private int allowance;      // kg cinsinden izin verilen ağırlık
    private double extraFee;    // Fazla bagaj ücreti
    private static final double EXTRA_FEE_PER_KG = 65.0; // Kg başına ek ücret (TL)
    private static final double SURCHARGE_THRESHOLD = 10.0; // Ek zam eşiği (kg)
    private static final double SURCHARGE_RATE = 1.40; // Eşik sonrası zam oranı

    /**
     * Yeni bagaj oluşturur.
     * @param weight Bagaj ağırlığı (kg)
     * @param allowance İzin verilen ağırlık (kg)
     */
    public Baggage(double weight, int allowance) {
        this.baggageId = generateBaggageId();
        this.weight = weight;
        this.allowance = allowance;
        this.extraFee = calculateExtraFee();
    }

    /**
     * Varsayılan bagaj (0 kg, 20 kg hak).
     */
    public Baggage() {
        this(0, 20);
    }

    private String generateBaggageId() {
        return "BAG-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase();
    }

    /**
     * Fazla bagaj ücretini hesaplar (kademeli tarife).
     * İlk 10 kg fazlalık: standart ücret
     * 10 kg üzeri: %40 zamlı ücret
     * @return Ek ücret (TL)
     */
    public double calculateExtraFee() {
        if (weight <= allowance) {
            return 0;
        }
        double extraWeight = weight - allowance;

        if (extraWeight <= SURCHARGE_THRESHOLD) {
            this.extraFee = extraWeight * EXTRA_FEE_PER_KG;
        } else {
            // İlk 10 kg normal, sonrası %40 zamlı
            double baseFee = SURCHARGE_THRESHOLD * EXTRA_FEE_PER_KG;
            double surgeFee = (extraWeight - SURCHARGE_THRESHOLD) * (EXTRA_FEE_PER_KG * SURCHARGE_RATE);
            this.extraFee = baseFee + surgeFee;
        }
        return this.extraFee;
    }

    /**
     * Bagajın fazla kilolu olup olmadığını kontrol eder.
     */
    public boolean isOverweight() {
        return weight > allowance;
    }

    /**
     * Fazla kilo miktarını döndürür.
     */
    public double getExtraWeight() {
        if (weight <= allowance) {
            return 0;
        }
        return weight - allowance;
    }

    /**
     * Kalan bagaj hakkını döndürür.
     */
    public double getRemainingAllowance() {
        if (weight >= allowance) {
            return 0;
        }
        return allowance - weight;
    }

    // Getter ve Setter metodları
    public String getBaggageId() {
        return baggageId;
    }

    public void setBaggageId(String baggageId) {
        this.baggageId = baggageId;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
        this.extraFee = calculateExtraFee();
    }

    public int getAllowance() {
        return allowance;
    }

    public void setAllowance(int allowance) {
        this.allowance = allowance;
        this.extraFee = calculateExtraFee();
    }

    public double getExtraFee() {
        return extraFee;
    }

    @Override
    public String toString() {
        return String.format("Baggage{id='%s', weight=%.1f kg, allowance=%d kg, extraFee=%.2f TL}",
                baggageId, weight, allowance, extraFee);
    }
}
