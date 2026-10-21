package com.airline.model;

import com.airline.model.enums.FlightStatus;
import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.List;

/**
 * Bir uçuşu temsil eder.
 * Uçuş numarası, tarih, saat, rota ve uçak bilgilerini içerir.
 */
public class Flight implements Serializable {
    private static final long serialVersionUID = 1L;

    private String flightNum;
    private String departurePlace;
    private String arrivalPlace;
    private LocalDate date;
    private LocalTime hour;
    private int duration; // dakika cinsinden
    private Plane plane;
    private Route route;
    private FlightStatus status;

    /**
     * Yeni bir uçuş oluşturur.
     */
    public Flight(String flightNum, Route route, LocalDate date, LocalTime hour,
            int duration, Plane plane) {
        this.flightNum = flightNum;
        this.route = route;
        this.departurePlace = route.getDepartureCity();
        this.arrivalPlace = route.getArrivalCity();
        this.date = date;
        this.hour = hour;
        this.duration = duration;
        this.plane = plane;
        this.status = FlightStatus.SCHEDULED;
    }

    /**
     * Basit constructor - rota olmadan.
     */
    public Flight(String flightNum, String departurePlace, String arrivalPlace,
            LocalDate date, LocalTime hour, int duration, Plane plane) {
        this.flightNum = flightNum;
        this.departurePlace = departurePlace;
        this.arrivalPlace = arrivalPlace;
        this.date = date;
        this.hour = hour;
        this.duration = duration;
        this.plane = plane;
        this.status = FlightStatus.SCHEDULED;
        this.route = null;
    }

    /**
     * Kalkış tarih ve saatini döndürür.
     */
    public LocalDateTime getDepartureDateTime() {
        return LocalDateTime.of(date, hour);
    }

    /**
     * Varış tarih ve saatini hesaplar.
     */
    public LocalDateTime getArrivalDateTime() {
        return getDepartureDateTime().plusMinutes(duration);
    }

    /**
     * Varış saatini döndürür.
     */
    public LocalTime getArrivalTime() {
        return getArrivalDateTime().toLocalTime();
    }

    /**
     * Uçuşun geçip geçmediğini kontrol eder.
     */
    public boolean isExpired() {
        return LocalDateTime.now().isAfter(getDepartureDateTime());
    }

    /**
     * Uçuşun bugün olup olmadığını kontrol eder.
     */
    public boolean isToday() {
        return date.equals(LocalDate.now());
    }

    /**
     * Boş koltukları döndürür.
     */
    public List<Seat> getAvailableSeats() {
        return plane.getAvailableSeats();
    }

    /**
     * Boş koltuk sayısını döndürür.
     */
    public int getAvailableSeatCount() {
        return plane.getAvailableSeatCount();
    }

    /**
     * Doluluk oranını hesaplar (0-100 arası).
     */
    public double getOccupancyRate() {
        if (plane.getCapacity() == 0)
            return 0;
        return ((double) plane.getReservedSeatCount() / plane.getCapacity()) * 100;
    }

    /**
     * Süreyi saat:dakika formatında döndürür.
     */
    public String getFormattedDuration() {
        int hours = duration / 60;
        int minutes = duration % 60;
        return String.format("%d sa %d dk", hours, minutes);
    }

    /**
     * Uçuş bilgilerini özet olarak döndürür.
     */
    public String getFlightSummary() {
        return String.format("%s: %s → %s (%s %s)",
                flightNum, departurePlace, arrivalPlace,
                date.toString(), hour.toString());
    }

    /**
     * Kalkış bilgisini havaalanı koduyla birlikte döndürür.
     * Örn: "İstanbul (IST)"
     */
    public String getDepartureWithAirport() {
        if (route != null && route.getDepartureAirportCode() != null) {
            return departurePlace + " (" + route.getDepartureAirportCode() + ")";
        }
        return departurePlace;
    }

    /**
     * Varış bilgisini havaalanı koduyla birlikte döndürür.
     * Örn: "Ankara (ESB)"
     */
    public String getArrivalWithAirport() {
        if (route != null && route.getArrivalAirportCode() != null) {
            return arrivalPlace + " (" + route.getArrivalAirportCode() + ")";
        }
        return arrivalPlace;
    }

    // Getter ve Setter metodları
    public String getFlightNum() {
        return flightNum;
    }

    public void setFlightNum(String flightNum) {
        this.flightNum = flightNum;
    }

    public String getDeparturePlace() {
        return departurePlace;
    }

    public void setDeparturePlace(String departurePlace) {
        this.departurePlace = departurePlace;
    }

    public String getArrivalPlace() {
        return arrivalPlace;
    }

    public void setArrivalPlace(String arrivalPlace) {
        this.arrivalPlace = arrivalPlace;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public LocalTime getHour() {
        return hour;
    }

    public void setHour(LocalTime hour) {
        this.hour = hour;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public Plane getPlane() {
        return plane;
    }

    public void setPlane(Plane plane) {
        this.plane = plane;
    }

    public Route getRoute() {
        return route;
    }

    public void setRoute(Route route) {
        this.route = route;
        if (route != null) {
            this.departurePlace = route.getDepartureCity();
            this.arrivalPlace = route.getArrivalCity();
        }
    }

    public FlightStatus getStatus() {
        return status;
    }

    public void setStatus(FlightStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return String.format("Flight{num='%s', %s→%s, date=%s, time=%s, status=%s}",
                flightNum, departurePlace, arrivalPlace, date, hour, status);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Flight flight = (Flight) o;
        return flightNum != null && flightNum.equals(flight.flightNum);
    }

    @Override
    public int hashCode() {
        return flightNum != null ? flightNum.hashCode() : 0;
    }
}
