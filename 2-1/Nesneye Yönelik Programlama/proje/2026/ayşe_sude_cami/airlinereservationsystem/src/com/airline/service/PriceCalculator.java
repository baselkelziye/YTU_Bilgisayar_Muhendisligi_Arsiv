package com.airline.service;

import com.airline.model.Flight;
import com.airline.model.Seat;
import com.airline.model.enums.AdditionalService;
import com.airline.model.enums.SeatClass;

import java.util.Set;

/**
 * Bilet fiyatı hesaplama işlemlerini gerçekleştirir.
 * JUnit testleri için kullanılacak ana sınıflardan biridir.
 */
public class PriceCalculator {

    private double basePrice; // Baz fiyat (TL)
    private double taxRate; // Vergi oranı (örn: 0.20 = %20)
    private double businessMultiplier; // Business sınıf çarpanı
    private double economyMultiplier; // Economy sınıf çarpanı
    private double serviceFee; // Sabit hizmet bedeli

    // Varsayılan değerler
    private static final double DEFAULT_BASE_PRICE = 450.0;
    private static final double DEFAULT_TAX_RATE = 0.20;
    private static final double DEFAULT_BUSINESS_MULTIPLIER = 2.8;
    private static final double DEFAULT_ECONOMY_MULTIPLIER = 1.0;
    private static final double DEFAULT_SERVICE_FEE = 35.0;

    /**
     * Varsayılan değerlerle PriceCalculator oluşturur.
     */
    public PriceCalculator() {
        this.basePrice = DEFAULT_BASE_PRICE;
        this.taxRate = DEFAULT_TAX_RATE;
        this.businessMultiplier = DEFAULT_BUSINESS_MULTIPLIER;
        this.economyMultiplier = DEFAULT_ECONOMY_MULTIPLIER;
        this.serviceFee = DEFAULT_SERVICE_FEE;
    }

    /**
     * Özel değerlerle PriceCalculator oluşturur.
     */
    public PriceCalculator(double basePrice, double taxRate) {
        this.basePrice = basePrice;
        this.taxRate = taxRate;
        this.businessMultiplier = DEFAULT_BUSINESS_MULTIPLIER;
        this.economyMultiplier = DEFAULT_ECONOMY_MULTIPLIER;
        this.serviceFee = DEFAULT_SERVICE_FEE;
    }

    /**
     * Koltuk ve uçuş bilgisine göre fiyat hesaplar.
     * 
     * @param seat   Koltuk
     * @param flight Uçuş
     * @return Hesaplanan fiyat (vergi dahil)
     */
    public double calculatePrice(Seat seat, Flight flight) {
        if (seat == null) {
            throw new IllegalArgumentException("Koltuk bilgisi boş olamaz!");
        }

        double price;
        if (seat.getClass_() == SeatClass.BUSINESS) {
            price = calculateBusinessPrice(basePrice);
        } else {
            price = calculateEconomyPrice(basePrice);
        }

        // Uçuş süresine göre logaritmik ek ücret hesaplama
        // Kısa uçuşlarda düşük, uzun uçuşlarda kademeli artış
        if (flight != null) {
            int durationMinutes = flight.getDuration();
            double durationFactor = Math.log1p(durationMinutes / 30.0) * 0.08;
            price += price * durationFactor;
        }

        return calculateTotalWithTax(price);
    }

    /**
     * Sadece koltuk bilgisine göre fiyat hesaplar.
     * 
     * @param seat Koltuk
     * @return Hesaplanan fiyat (vergi dahil)
     */
    public double calculatePrice(Seat seat) {
        return calculatePrice(seat, null);
    }

    /**
     * Business sınıfı fiyatını hesaplar.
     * Formül: (baz * çarpan) + sabit hizmet bedeli + konfor primi
     * 
     * @param base Baz fiyat
     * @return Business fiyatı (vergi hariç)
     */
    public double calculateBusinessPrice(double base) {
        if (base < 0) {
            throw new IllegalArgumentException("Baz fiyat negatif olamaz!");
        }
        double comfortPremium = base * 0.15; // %15 konfor primi
        return (base * businessMultiplier) + serviceFee + comfortPremium;
    }

    /**
     * Economy sınıfı fiyatını hesaplar.
     * Formül: (baz * çarpan) + sabit hizmet bedeli
     * 
     * @param base Baz fiyat
     * @return Economy fiyatı (vergi hariç)
     */
    public double calculateEconomyPrice(double base) {
        if (base < 0) {
            throw new IllegalArgumentException("Baz fiyat negatif olamaz!");
        }
        return (base * economyMultiplier) + serviceFee;
    }

    /**
     * İndirim uygular.
     * 
     * @param price           Orijinal fiyat
     * @param discountPercent İndirim yüzdesi (0-100 arası)
     * @return İndirimli fiyat
     */
    public double applyDiscount(double price, double discountPercent) {
        if (price < 0) {
            throw new IllegalArgumentException("Fiyat negatif olamaz!");
        }
        if (discountPercent < 0 || discountPercent > 100) {
            throw new IllegalArgumentException("İndirim oranı 0-100 arasında olmalıdır!");
        }
        return price * (1 - discountPercent / 100);
    }

    /**
     * Vergi miktarını hesaplar.
     * 
     * @param price Fiyat (vergi hariç)
     * @return Vergi miktarı
     */
    public double calculateTax(double price) {
        if (price < 0) {
            throw new IllegalArgumentException("Fiyat negatif olamaz!");
        }
        return price * taxRate;
    }

    /**
     * Vergi dahil toplam fiyatı hesaplar.
     * 
     * @param price Fiyat (vergi hariç)
     * @return Toplam fiyat (vergi dahil)
     */
    public double calculateTotalWithTax(double price) {
        if (price < 0) {
            throw new IllegalArgumentException("Fiyat negatif olamaz!");
        }
        return price + calculateTax(price);
    }

    /**
     * Sınıfa göre fiyat hesaplar.
     * 
     * @param seatClass Koltuk sınıfı
     * @return Hesaplanan fiyat (vergi dahil)
     */
    public double calculatePriceByClass(SeatClass seatClass) {
        double price;
        if (seatClass == SeatClass.BUSINESS) {
            price = calculateBusinessPrice(basePrice);
        } else {
            price = calculateEconomyPrice(basePrice);
        }
        return calculateTotalWithTax(price);
    }

    /**
     * Bagaj ek ücreti hesaplar (kademeli sistem).
     * İlk 5 kg: normal fiyat, sonraki kg'lar: %25 zamlı
     * 
     * @param extraKg    Fazla kilo miktarı
     * @param pricePerKg Kilo başına ücret
     * @return Toplam ek ücret
     */
    public double calculateBaggageFee(double extraKg, double pricePerKg) {
        if (extraKg < 0 || pricePerKg < 0) {
            throw new IllegalArgumentException("Değerler negatif olamaz!");
        }
        if (extraKg <= 5) {
            return extraKg * pricePerKg;
        }
        // İlk 5 kg normal, geri kalanı %25 zamlı
        double firstTierFee = 5 * pricePerKg;
        double secondTierFee = (extraKg - 5) * (pricePerKg * 1.25);
        return firstTierFee + secondTierFee;
    }

    /**
     * Fiyatı yuvarlar (2 ondalık basamak).
     * 
     * @param price Yuvarlanacak fiyat
     * @return Yuvarlanmış fiyat
     */
    public double roundPrice(double price) {
        return Math.round(price * 100.0) / 100.0;
    }

    /**
     * Seçilen ek hizmetlerin toplam fiyatını hesaplar.
     * 
     * @param services Seçilen ek hizmetler
     * @return Toplam ek hizmet fiyatı
     */
    public double calculateServicesTotal(Set<AdditionalService> services) {
        if (services == null || services.isEmpty()) {
            return 0;
        }
        double total = 0;
        java.util.Iterator<AdditionalService> iterator = services.iterator();
        while (iterator.hasNext()) {
            AdditionalService service = iterator.next();
            total += service.getPrice();
        }
        return total;
    }

    /**
     * Koltuk, uçuş ve ek hizmetler dahil toplam fiyat hesaplar.
     * 
     * @param seat     Koltuk
     * @param flight   Uçuş
     * @param services Seçilen ek hizmetler
     * @return Toplam fiyat (vergi dahil)
     */
    public double calculatePriceWithServices(Seat seat, Flight flight, Set<AdditionalService> services) {
        double baseTotal = calculatePrice(seat, flight);
        double servicesTotal = calculateServicesTotal(services);
        return roundPrice(baseTotal + servicesTotal);
    }

    // Getter ve Setter metodları
    public double getBasePrice() {
        return basePrice;
    }

    public void setBasePrice(double basePrice) {
        if (basePrice < 0) {
            throw new IllegalArgumentException("Baz fiyat negatif olamaz!");
        }
        this.basePrice = basePrice;
    }

    public double getTaxRate() {
        return taxRate;
    }

    public void setTaxRate(double taxRate) {
        if (taxRate < 0 || taxRate > 1) {
            throw new IllegalArgumentException("Vergi oranı 0-1 arasında olmalıdır!");
        }
        this.taxRate = taxRate;
    }

    public double getBusinessMultiplier() {
        return businessMultiplier;
    }

    public void setBusinessMultiplier(double businessMultiplier) {
        this.businessMultiplier = businessMultiplier;
    }

    public double getEconomyMultiplier() {
        return economyMultiplier;
    }

    public void setEconomyMultiplier(double economyMultiplier) {
        this.economyMultiplier = economyMultiplier;
    }

    public double getServiceFee() {
        return serviceFee;
    }

    public void setServiceFee(double serviceFee) {
        if (serviceFee < 0) {
            throw new IllegalArgumentException("Hizmet bedeli negatif olamaz!");
        }
        this.serviceFee = serviceFee;
    }
}
