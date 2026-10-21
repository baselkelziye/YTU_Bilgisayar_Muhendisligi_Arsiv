package com.airline.tests;

import com.airline.managers.*;
import com.airline.models.*;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

import java.util.List;

public class UnitTests{

    @Test
    @DisplayName("Calculate prices correctly for Economy and Business")
    public void testPriceCalculation(){
        Seat economySeat = new Seat("1A", Seat.SeatClass.ECONOMY, 100.0);
        Baggage normalBaggage = new Baggage(10.0);
        assertEquals(100.0,CalculatePrice.calculateTicketPrice(economySeat,normalBaggage),0.001);

        Baggage heavyBaggage = new Baggage(20.0);
        assertEquals(150.0,CalculatePrice.calculateTicketPrice(economySeat,heavyBaggage),0.001);

        Seat businessSeat = new Seat("1B",Seat.SeatClass.BUSINESS,200.0);
        assertEquals(200.0,CalculatePrice.calculateTicketPrice(businessSeat,normalBaggage));
    }

    @Test
    @DisplayName("Search engine should filter by city")
    public void testFlightSearchEngine(){
        FlightManager fm = new FlightManager(true);
        Route r1 = new Route("A","B");
        Plane p1 = new Plane("P1","M1",100);
        Flight f1 = new Flight("1",r1, "2026-12-12","10:00","1h",p1,"Ahmet");
        Route r2 = new Route("A","C");
        Flight f2 = new Flight("2",r2, "2026-12-12","10:00","1h",p1,"Ahmet");

        fm.addFlight(f1);
        fm.addFlight(f2);

        List<Flight> results = fm.searchFlights("A", "B");
        assertEquals(1, results.size());
        assertEquals("1", results.get(0).getFlightNum());
    }

    @Test
    @DisplayName("Seat count should decrease after reservation")
    public void testSeatManagerCount() throws Exception {
        SeatManager sm = new SeatManager();
        Plane p = new Plane("P1","M1",6);
        Flight f = new Flight("1",new Route("A", "B"),"date","time","dur",p,"Ahmet");

        assertEquals(6,sm.getAvailableSeatsCount(f));

        sm.reserveSeat(f, "1A");
        assertEquals(5,sm.getAvailableSeatsCount(f));
        assertTrue(f.getPlane().getSeat("1A").isReserved());
    }

    @Test
    @DisplayName("Should throw exception for invalid or duplicate seats")
    public void testSeatManagerExceptions() throws Exception{
        SeatManager sm = new SeatManager();
        Plane p = new Plane("P1","M1",6);
        Flight f = new Flight("1",new Route("A", "B"),"date","time","dur",p,"Ahmet");

        sm.reserveSeat(f,"1A");

        assertThrows(Exception.class, () -> {sm.reserveSeat(f,"1A");}, "Should throw exception when seat is already reserved");

        assertThrows(Exception.class, () -> {sm.reserveSeat(f, "99Z");}, "Should throw exception for non-existent seat");
    }

    @Test
    @DisplayName("Search engine should ignore flights in the past")
    public void testFlightSearchEngineEliminatePastFlights(){
        FlightManager fm = new FlightManager(true);
        Route route = new Route("A", "B");
        Plane plane = new Plane("P1", "M1", 100);

        Flight pastFlight = new Flight("PAST1", route, "2020-01-01", "08:00", "1h", plane, "Ahmet");
        Flight futureFlight = new Flight("FUTURE1", route, "2099-01-01", "10:00", "1h", plane, "Ahmet");

        fm.addFlight(pastFlight);
        fm.addFlight(futureFlight);

        List<Flight> results = fm.searchFlights("A","B");

        assertEquals(1,results.size());
        assertEquals("FUTURE1", results.get(0).getFlightNum());
    }
}