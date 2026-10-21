package com.airline.test;

import com.airline.model.Seat;
import com.airline.model.enums.SeatClass;
import com.airline.service.PriceCalculator;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.*;

/**
 * PriceCalculator sınıfı için JUnit 5 testleri.
 * Fiyat hesaplama işlemlerinin doğruluğunu test eder.
 */
public class PriceCalculatorTest {

    private PriceCalculator calculator;
    private Seat economySeat;
    private Seat businessSeat;

    @BeforeEach
    void setUp() {
        calculator = new PriceCalculator(450.0, 0.20); // 450 TL baz, %20 vergi
        economySeat = new Seat("15A", SeatClass.ECONOMY, 450);
        businessSeat = new Seat("3A", SeatClass.BUSINESS, 450);
    }

    @Test
    @DisplayName("Economy sınıfı fiyat hesaplama testi")
    void testCalculateEconomyPrice() {
        double price = calculator.calculateEconomyPrice(450);
        // 450 * 1.0 + 35 (hizmet bedeli) = 485 TL
        assertEquals(485.0, price, 0.01, "Economy fiyatı baz + hizmet bedeli olmalı");
    }

    @Test
    @DisplayName("Business sınıfı fiyat hesaplama testi")
    void testCalculateBusinessPrice() {
        double price = calculator.calculateBusinessPrice(450);
        // (450 * 2.8) + 35 (hizmet) + (450 * 0.15 konfor) = 1260 + 35 + 67.5 = 1362.5 TL
        assertEquals(1362.5, price, 0.01, "Business fiyatı (baz*2.8) + hizmet + konfor primi olmalı");
    }

    @Test
    @DisplayName("Vergi hesaplama testi")
    void testCalculateTax() {
        double tax = calculator.calculateTax(1000);
        assertEquals(200.0, tax, 0.01, "1000 TL için %20 vergi = 200 TL olmalı");
    }

    @Test
    @DisplayName("Vergi dahil toplam fiyat testi")
    void testCalculateTotalWithTax() {
        double total = calculator.calculateTotalWithTax(1000);
        assertEquals(1200.0, total, 0.01, "1000 TL + %20 vergi = 1200 TL olmalı");
    }

    @Test
    @DisplayName("Economy koltuk için tam fiyat hesaplama testi")
    void testCalculatePriceForEconomySeat() {
        double price = calculator.calculatePrice(economySeat);
        // (450 * 1.0 + 35) * 1.20 = 485 * 1.20 = 582 TL
        assertEquals(582.0, price, 0.01, "Economy koltuk fiyatı vergi dahil 582 TL olmalı");
    }

    @Test
    @DisplayName("Business koltuk için tam fiyat hesaplama testi")
    void testCalculatePriceForBusinessSeat() {
        double price = calculator.calculatePrice(businessSeat);
        // ((450 * 2.8) + 35 + (450*0.15)) * 1.20 = 1362.5 * 1.20 = 1635 TL
        assertEquals(1635.0, price, 0.01, "Business koltuk fiyatı vergi dahil 1635 TL olmalı");
    }

    @Test
    @DisplayName("İndirim uygulama testi")
    void testApplyDiscount() {
        double discountedPrice = calculator.applyDiscount(1000, 20);
        assertEquals(800.0, discountedPrice, 0.01, "%20 indirimle 1000 TL = 800 TL olmalı");
    }

    @Test
    @DisplayName("Sıfır indirim testi")
    void testApplyZeroDiscount() {
        double price = calculator.applyDiscount(1000, 0);
        assertEquals(1000.0, price, 0.01, "%0 indirimle fiyat değişmemeli");
    }

    @Test
    @DisplayName("Tam indirim testi")
    void testApplyFullDiscount() {
        double price = calculator.applyDiscount(1000, 100);
        assertEquals(0.0, price, 0.01, "%100 indirimle fiyat 0 olmalı");
    }

    @Test
    @DisplayName("Negatif fiyat için exception testi")
    void testNegativePriceThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            calculator.calculateTax(-100);
        }, "Negatif fiyat için exception fırlatılmalı");
    }

    @Test
    @DisplayName("Geçersiz indirim oranı için exception testi")
    void testInvalidDiscountThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            calculator.applyDiscount(1000, 150);
        }, "150% indirim için exception fırlatılmalı");

        assertThrows(IllegalArgumentException.class, () -> {
            calculator.applyDiscount(1000, -10);
        }, "Negatif indirim için exception fırlatılmalı");
    }

    @Test
    @DisplayName("Null koltuk için exception testi")
    void testNullSeatThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            calculator.calculatePrice(null);
        }, "Null koltuk için exception fırlatılmalı");
    }

    @Test
    @DisplayName("Bagaj ek ücreti hesaplama testi")
    void testCalculateBaggageFee() {
        // İlk 5 kg normal fiyat testi
        double fee = calculator.calculateBaggageFee(5, 50);
        assertEquals(250.0, fee, 0.01, "5 kg fazla * 50 TL/kg = 250 TL olmalı");

        // Kademeli tarife testi: 10 kg = (5*50) + (5*62.5) = 250 + 312.5 = 562.5
        fee = calculator.calculateBaggageFee(10, 50);
        assertEquals(562.5, fee, 0.01, "10 kg için kademeli tarife uygulanmalı");
    }

    @Test
    @DisplayName("Fiyat yuvarlama testi")
    void testRoundPrice() {
        double rounded = calculator.roundPrice(123.456);
        assertEquals(123.46, rounded, 0.001, "123.456 -> 123.46 olarak yuvarlanmalı");

        rounded = calculator.roundPrice(123.454);
        assertEquals(123.45, rounded, 0.001, "123.454 -> 123.45 olarak yuvarlanmalı");
    }

    @Test
    @DisplayName("Sınıfa göre fiyat hesaplama testi")
    void testCalculatePriceByClass() {
        double economyPrice = calculator.calculatePriceByClass(SeatClass.ECONOMY);
        double businessPrice = calculator.calculatePriceByClass(SeatClass.BUSINESS);

        assertTrue(businessPrice > economyPrice,
                "Business fiyatı Economy'den yüksek olmalı");
        assertEquals(582.0, economyPrice, 0.01);  // (450+35) * 1.20
        assertEquals(1635.0, businessPrice, 0.01); // 1362.5 * 1.20
    }
}
