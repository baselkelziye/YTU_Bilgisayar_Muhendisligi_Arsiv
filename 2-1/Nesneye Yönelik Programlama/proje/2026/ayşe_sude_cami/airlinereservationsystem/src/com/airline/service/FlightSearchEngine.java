package com.airline.service;

import com.airline.manager.FlightManager;
import com.airline.model.Flight;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Uçuş arama ve filtreleme işlemlerini gerçekleştirir.
 * JUnit testleri için kullanılacak ana sınıflardan biridir.
 */
public class FlightSearchEngine {

    private FlightManager flightManager;

    /**
     * FlightSearchEngine oluşturur.
     * @param flightManager Uçuş yöneticisi
     */
    public FlightSearchEngine(FlightManager flightManager) {
        this.flightManager = flightManager;
    }

    /**
     * Kalkış ve varış şehrine göre uçuş arar.
     * @param from Kalkış şehri
     * @param to Varış şehri
     * @param date Tarih (null ise tüm tarihler)
     * @return Bulunan uçuşlar
     */
    public List<Flight> searchFlights(String from, String to, LocalDate date) {
        if (from == null || to == null) {
            throw new IllegalArgumentException("Kalkış ve varış şehri boş olamaz!");
        }

        List<Flight> results = flightManager.getAllFlights().stream()
                .filter(f -> f.getDeparturePlace().equalsIgnoreCase(from.trim()))
                .filter(f -> f.getArrivalPlace().equalsIgnoreCase(to.trim()))
                .filter(f -> !f.isExpired()) // Süresi geçmiş uçuşları çıkar
                .collect(Collectors.toList());

        // Tarih filtresi varsa uygula
        if (date != null) {
            results = results.stream()
                    .filter(f -> f.getDate().equals(date))
                    .collect(Collectors.toList());
        }

        // Saate göre sırala
        results.sort(Comparator.comparing(Flight::getDepartureDateTime));

        return results;
    }

    /**
     * Sadece kalkış ve varış şehrine göre arar (tüm tarihler).
     */
    public List<Flight> searchFlights(String from, String to) {
        return searchFlights(from, to, null);
    }

    /**
     * Kalkış şehrine göre filtreler.
     * @param city Kalkış şehri
     * @return Filtrelenmiş uçuşlar
     */
    public List<Flight> filterByDeparture(String city) {
        if (city == null || city.trim().isEmpty()) {
            throw new IllegalArgumentException("Şehir adı boş olamaz!");
        }

        return flightManager.getAllFlights().stream()
                .filter(f -> f.getDeparturePlace().equalsIgnoreCase(city.trim()))
                .filter(f -> !f.isExpired())
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Varış şehrine göre filtreler.
     * @param city Varış şehri
     * @return Filtrelenmiş uçuşlar
     */
    public List<Flight> filterByArrival(String city) {
        if (city == null || city.trim().isEmpty()) {
            throw new IllegalArgumentException("Şehir adı boş olamaz!");
        }

        return flightManager.getAllFlights().stream()
                .filter(f -> f.getArrivalPlace().equalsIgnoreCase(city.trim()))
                .filter(f -> !f.isExpired())
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Tarihe göre filtreler.
     * @param date Tarih
     * @return Filtrelenmiş uçuşlar
     */
    public List<Flight> filterByDate(LocalDate date) {
        if (date == null) {
            throw new IllegalArgumentException("Tarih boş olamaz!");
        }

        return flightManager.getAllFlights().stream()
                .filter(f -> f.getDate().equals(date))
                .filter(f -> !f.isExpired())
                .sorted(Comparator.comparing(Flight::getHour))
                .collect(Collectors.toList());
    }

    /**
     * Süresi geçmiş uçuşları listeden çıkarır.
     * @return Aktif uçuşlar
     */
    public List<Flight> removeExpiredFlights() {
        return flightManager.getAllFlights().stream()
                .filter(f -> !f.isExpired())
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Kalkış saati geçmiş uçuşları döndürür.
     * @return Süresi geçmiş uçuşlar
     */
    public List<Flight> getExpiredFlights() {
        return flightManager.getAllFlights().stream()
                .filter(Flight::isExpired)
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Müsait (boş koltuk olan) uçuşları döndürür.
     * @return Müsait uçuşlar
     */
    public List<Flight> getAvailableFlights() {
        return flightManager.getAllFlights().stream()
                .filter(f -> !f.isExpired())
                .filter(f -> f.getAvailableSeatCount() > 0)
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Bugünkü uçuşları döndürür.
     * @return Bugünkü uçuşlar
     */
    public List<Flight> getTodaysFlights() {
        return filterByDate(LocalDate.now());
    }

    /**
     * Yarınki uçuşları döndürür.
     * @return Yarınki uçuşlar
     */
    public List<Flight> getTomorrowsFlights() {
        return filterByDate(LocalDate.now().plusDays(1));
    }

    /**
     * Belirli bir tarih aralığındaki uçuşları döndürür.
     * @param startDate Başlangıç tarihi
     * @param endDate Bitiş tarihi
     * @return Tarih aralığındaki uçuşlar
     */
    public List<Flight> getFlightsBetweenDates(LocalDate startDate, LocalDate endDate) {
        if (startDate == null || endDate == null) {
            throw new IllegalArgumentException("Tarihler boş olamaz!");
        }
        if (startDate.isAfter(endDate)) {
            throw new IllegalArgumentException("Başlangıç tarihi bitiş tarihinden sonra olamaz!");
        }

        return flightManager.getAllFlights().stream()
                .filter(f -> !f.getDate().isBefore(startDate))
                .filter(f -> !f.getDate().isAfter(endDate))
                .filter(f -> !f.isExpired())
                .sorted(Comparator.comparing(Flight::getDepartureDateTime))
                .collect(Collectors.toList());
    }

    /**
     * Uçuş numarasına göre arar.
     * @param flightNum Uçuş numarası
     * @return Bulunan uçuş veya null
     */
    public Flight findByFlightNumber(String flightNum) {
        if (flightNum == null || flightNum.trim().isEmpty()) {
            return null;
        }
        return flightManager.getFlightByNumber(flightNum.trim());
    }

    /**
     * Tüm benzersiz kalkış şehirlerini döndürür.
     * @return Kalkış şehirleri listesi
     */
    public List<String> getAllDepartureCities() {
        return flightManager.getAllFlights().stream()
                .map(Flight::getDeparturePlace)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
    }

    /**
     * Tüm benzersiz varış şehirlerini döndürür.
     * @return Varış şehirleri listesi
     */
    public List<String> getAllArrivalCities() {
        return flightManager.getAllFlights().stream()
                .map(Flight::getArrivalPlace)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
    }

    /**
     * Belirli bir rotadaki en ucuz uçuşu bulur.
     * @param from Kalkış
     * @param to Varış
     * @return En ucuz uçuş veya null
     */
    public Flight findCheapestFlight(String from, String to) {
        List<Flight> flights = searchFlights(from, to);
        if (flights.isEmpty()) {
            return null;
        }

        // En az dolu (en çok boş koltuk olan) uçuşu döndür
        // Gerçek uygulamada fiyat karşılaştırması yapılır
        return flights.stream()
                .max(Comparator.comparing(Flight::getAvailableSeatCount))
                .orElse(null);
    }

    /**
     * FlightManager'ı döndürür.
     */
    public FlightManager getFlightManager() {
        return flightManager;
    }

    /**
     * FlightManager'ı ayarlar.
     */
    public void setFlightManager(FlightManager flightManager) {
        this.flightManager = flightManager;
    }
}
