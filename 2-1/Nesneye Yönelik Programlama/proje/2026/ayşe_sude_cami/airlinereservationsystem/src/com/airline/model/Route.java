package com.airline.model;

import java.io.Serializable;
import java.util.UUID;

/**
 * Uçuş rotasını temsil eder.
 * Kalkış ve varış şehir/havalimanı bilgilerini içerir.
 */
public class Route implements Serializable {
    private static final long serialVersionUID = 1L;

    private String routeId;
    private String departureCity;
    private String departureAirport;
    private String departureAirportCode;
    private String arrivalCity;
    private String arrivalAirport;
    private String arrivalAirportCode;
    private int distance; // km cinsinden

    /**
     * Yeni bir rota oluşturur.
     */
    public Route(String departureCity, String departureAirport, String departureAirportCode,
                 String arrivalCity, String arrivalAirport, String arrivalAirportCode) {
        this.routeId = generateRouteId();
        this.departureCity = departureCity;
        this.departureAirport = departureAirport;
        this.departureAirportCode = departureAirportCode;
        this.arrivalCity = arrivalCity;
        this.arrivalAirport = arrivalAirport;
        this.arrivalAirportCode = arrivalAirportCode;
        this.distance = 0;
    }

    /**
     * Basit constructor - sadece şehir ve havalimanı kodu ile.
     */
    public Route(String departureCity, String departureAirportCode,
                 String arrivalCity, String arrivalAirportCode) {
        this.routeId = generateRouteId();
        this.departureCity = departureCity;
        this.departureAirport = departureCity + " Havalimanı";
        this.departureAirportCode = departureAirportCode;
        this.arrivalCity = arrivalCity;
        this.arrivalAirport = arrivalCity + " Havalimanı";
        this.arrivalAirportCode = arrivalAirportCode;
        this.distance = 0;
    }

    private String generateRouteId() {
        return "RT-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase();
    }

    /**
     * Rota açıklamasını döndürür.
     * Örn: "IST → ESB (İstanbul - Ankara)"
     */
    public String getRouteDescription() {
        return String.format("%s → %s (%s - %s)",
                departureAirportCode, arrivalAirportCode,
                departureCity, arrivalCity);
    }

    /**
     * Kısa rota açıklaması.
     * Örn: "IST → ESB"
     */
    public String getShortDescription() {
        return departureAirportCode + " → " + arrivalAirportCode;
    }

    // Getter ve Setter metodları
    public String getRouteId() {
        return routeId;
    }

    public void setRouteId(String routeId) {
        this.routeId = routeId;
    }

    public String getDepartureCity() {
        return departureCity;
    }

    public void setDepartureCity(String departureCity) {
        this.departureCity = departureCity;
    }

    public String getDepartureAirport() {
        return departureAirport;
    }

    public void setDepartureAirport(String departureAirport) {
        this.departureAirport = departureAirport;
    }

    public String getDepartureAirportCode() {
        return departureAirportCode;
    }

    public void setDepartureAirportCode(String departureAirportCode) {
        this.departureAirportCode = departureAirportCode;
    }

    public String getArrivalCity() {
        return arrivalCity;
    }

    public void setArrivalCity(String arrivalCity) {
        this.arrivalCity = arrivalCity;
    }

    public String getArrivalAirport() {
        return arrivalAirport;
    }

    public void setArrivalAirport(String arrivalAirport) {
        this.arrivalAirport = arrivalAirport;
    }

    public String getArrivalAirportCode() {
        return arrivalAirportCode;
    }

    public void setArrivalAirportCode(String arrivalAirportCode) {
        this.arrivalAirportCode = arrivalAirportCode;
    }

    public int getDistance() {
        return distance;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }

    @Override
    public String toString() {
        return getRouteDescription();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Route route = (Route) o;
        return routeId != null && routeId.equals(route.routeId);
    }

    @Override
    public int hashCode() {
        return routeId != null ? routeId.hashCode() : 0;
    }
}
