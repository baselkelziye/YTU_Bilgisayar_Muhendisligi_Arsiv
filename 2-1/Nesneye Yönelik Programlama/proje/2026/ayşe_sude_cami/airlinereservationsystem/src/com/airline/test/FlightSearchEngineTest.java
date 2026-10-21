package com.airline.test;

import com.airline.manager.FlightManager;
import com.airline.model.Flight;
import com.airline.model.Plane;
import com.airline.model.Route;
import com.airline.service.FlightSearchEngine;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

/**
 * FlightSearchEngine sınıfı için JUnit 5 testleri.
 * Uçuş arama ve filtreleme işlemlerinin doğruluğunu test eder.
 */
public class FlightSearchEngineTest {

    private FlightManager flightManager;
    private FlightSearchEngine searchEngine;
    private Plane testPlane;

    @BeforeEach
    void setUp() {
        // Her test için temiz bir FlightManager oluştur
        flightManager = new FlightManager();
        flightManager.clearAllData();

        searchEngine = new FlightSearchEngine(flightManager);
        testPlane = new Plane("TEST-001", "Boeing 737", 500);

        // Test verileri oluştur
        createTestFlights();
    }

    private void createTestFlights() {
        LocalDate today = LocalDate.now();
        LocalDate tomorrow = today.plusDays(1);

        // Istanbul -> Ankara uçuşları (saat 23:59 - her zaman gelecek)
        Route route1 = new Route("İstanbul", "IST", "Ankara", "ESB");
        flightManager.createFlight("TK101", route1, today, LocalTime.of(23, 59), 60, testPlane);
        flightManager.createFlight("TK102", route1, tomorrow, LocalTime.of(14, 0), 60,
                new Plane("TEST-002", "Airbus A320", 450));

        // Istanbul -> Izmir uçuşları (saat 23:59 - her zaman gelecek)
        Route route2 = new Route("İstanbul", "IST", "İzmir", "ADB");
        flightManager.createFlight("TK201", route2, today, LocalTime.of(23, 59), 75, testPlane);

        // Ankara -> Antalya uçuşları
        Route route3 = new Route("Ankara", "ESB", "Antalya", "AYT");
        flightManager.createFlight("TK301", route3, tomorrow, LocalTime.of(9, 0), 90, testPlane);

        // Geçmiş uçuş (test için - normalde geçmiş uçuş oluşturulmaz)
        // Not: Bu uçuş expired olarak işaretlenecek
    }

    @Test
    @DisplayName("Kalkış ve varış şehrine göre uçuş arama testi")
    void testSearchFlightsByRoute() {
        List<Flight> results = searchEngine.searchFlights("İstanbul", "Ankara");

        assertNotNull(results, "Sonuç null olmamalı");
        assertFalse(results.isEmpty(), "En az bir uçuş bulunmalı");

        // Tüm sonuçlar Istanbul -> Ankara olmalı
        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertEquals("İstanbul", flight.getDeparturePlace());
            assertEquals("Ankara", flight.getArrivalPlace());
        }
    }

    @Test
    @DisplayName("Tarih ile uçuş arama testi")
    void testSearchFlightsWithDate() {
        LocalDate today = LocalDate.now();
        List<Flight> results = searchEngine.searchFlights("İstanbul", "Ankara", today);

        assertFalse(results.isEmpty(), "Bugün için uçuş bulunmalı");

        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertEquals(today, flight.getDate(), "Tüm uçuşlar bugüne ait olmalı");
        }
    }

    @Test
    @DisplayName("Bulunamayan rota testi")
    void testSearchFlightsNoResults() {
        List<Flight> results = searchEngine.searchFlights("İstanbul", "Tokyo");

        assertTrue(results.isEmpty(), "Tokyo uçuşu bulunmamalı");
    }

    @Test
    @DisplayName("Kalkış şehrine göre filtreleme testi")
    void testFilterByDeparture() {
        List<Flight> results = searchEngine.filterByDeparture("İstanbul");

        assertFalse(results.isEmpty(), "İstanbul'dan kalkan uçuş bulunmalı");

        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertEquals("İstanbul", flight.getDeparturePlace());
        }
    }

    @Test
    @DisplayName("Varış şehrine göre filtreleme testi")
    void testFilterByArrival() {
        List<Flight> results = searchEngine.filterByArrival("Ankara");

        assertFalse(results.isEmpty(), "Ankara'ya giden uçuş bulunmalı");

        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertEquals("Ankara", flight.getArrivalPlace());
        }
    }

    @Test
    @DisplayName("Tarihe göre filtreleme testi")
    void testFilterByDate() {
        LocalDate tomorrow = LocalDate.now().plusDays(1);
        List<Flight> results = searchEngine.filterByDate(tomorrow);

        assertFalse(results.isEmpty(), "Yarın için uçuş bulunmalı");

        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertEquals(tomorrow, flight.getDate());
        }
    }

    @Test
    @DisplayName("Süresi geçmiş uçuşları çıkarma testi")
    void testRemoveExpiredFlights() {
        List<Flight> activeFlights = searchEngine.removeExpiredFlights();

        java.util.Iterator<Flight> iterator = activeFlights.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertFalse(flight.isExpired(), "Expired uçuş olmamalı");
        }
    }

    @Test
    @DisplayName("Müsait uçuşları getirme testi")
    void testGetAvailableFlights() {
        List<Flight> availableFlights = searchEngine.getAvailableFlights();

        java.util.Iterator<Flight> iterator = availableFlights.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertTrue(flight.getAvailableSeatCount() > 0,
                    "Her uçuşta boş koltuk olmalı");
            assertFalse(flight.isExpired(), "Expired uçuş olmamalı");
        }
    }

    @Test
    @DisplayName("Uçuş numarasına göre arama testi")
    void testFindByFlightNumber() {
        Flight found = searchEngine.findByFlightNumber("TK101");

        assertNotNull(found, "TK101 uçuşu bulunmalı");
        assertEquals("TK101", found.getFlightNum());
    }

    @Test
    @DisplayName("Bulunamayan uçuş numarası testi")
    void testFindByFlightNumberNotFound() {
        Flight found = searchEngine.findByFlightNumber("NOTEXIST");

        assertNull(found, "Olmayan uçuş null dönmeli");
    }

    @Test
    @DisplayName("Null kalkış şehri için exception testi")
    void testSearchWithNullDepartureThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            searchEngine.searchFlights(null, "Ankara");
        });
    }

    @Test
    @DisplayName("Null varış şehri için exception testi")
    void testSearchWithNullArrivalThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            searchEngine.searchFlights("İstanbul", null);
        });
    }

    @Test
    @DisplayName("Boş şehir adı için exception testi")
    void testFilterWithEmptyCityThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            searchEngine.filterByDeparture("");
        });
    }

    @Test
    @DisplayName("Tarih aralığı ile arama testi")
    void testGetFlightsBetweenDates() {
        LocalDate start = LocalDate.now();
        LocalDate end = LocalDate.now().plusDays(7);

        List<Flight> results = searchEngine.getFlightsBetweenDates(start, end);

        java.util.Iterator<Flight> iterator = results.iterator();
        while (iterator.hasNext()) {
            Flight flight = iterator.next();
            assertTrue(!flight.getDate().isBefore(start), "Tarih başlangıçtan önce olmamalı");
            assertTrue(!flight.getDate().isAfter(end), "Tarih bitişten sonra olmamalı");
        }
    }

    @Test
    @DisplayName("Geçersiz tarih aralığı için exception testi")
    void testInvalidDateRangeThrowsException() {
        LocalDate start = LocalDate.now().plusDays(7);
        LocalDate end = LocalDate.now();

        assertThrows(IllegalArgumentException.class, () -> {
            searchEngine.getFlightsBetweenDates(start, end);
        }, "Başlangıç bitişten sonra olamaz");
    }

    @Test
    @DisplayName("Tüm kalkış şehirlerini getirme testi")
    void testGetAllDepartureCities() {
        List<String> cities = searchEngine.getAllDepartureCities();

        assertFalse(cities.isEmpty(), "En az bir kalkış şehri olmalı");
        assertTrue(cities.contains("İstanbul"), "İstanbul listede olmalı");
    }

    @Test
    @DisplayName("Tüm varış şehirlerini getirme testi")
    void testGetAllArrivalCities() {
        List<String> cities = searchEngine.getAllArrivalCities();

        assertFalse(cities.isEmpty(), "En az bir varış şehri olmalı");
        assertTrue(cities.contains("Ankara"), "Ankara listede olmalı");
    }
}
