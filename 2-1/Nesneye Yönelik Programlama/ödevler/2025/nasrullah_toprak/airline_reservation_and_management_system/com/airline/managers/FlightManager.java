package com.airline.managers;

import com.airline.models.Flight;
import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;
import java.time.LocalTime;
import com.airline.util.FileUtil;
import com.airline.models.*;
import java.util.*;

public class FlightManager {
    private List<Flight> flights;
    private static final String FILE = "data/flights.txt";

    public FlightManager() {
        this.flights = new ArrayList<>();
        loadFlights();
    }

    public FlightManager(boolean skipFileLoading) {
        this.flights = new ArrayList<>();
        if (!skipFileLoading) {
            loadFlights();
        }
    }

    public void addFlight(Flight flight) {
        if (!flights.contains(flight)) {
            flights.add(flight);
            saveFlights();
        }
    }

    public void updateFlight(Flight flight) {
        if (flights.contains(flight)) {
            saveFlights();
        }
    }

    public void removeFlight(String flightNum) {
        flights.removeIf(f -> f.getFlightNum().equals(flightNum));
        saveFlights();
    }

    public Flight getFlight(String flightNum) {
        for (Flight f : flights) {
            if (f.getFlightNum().equalsIgnoreCase(flightNum)) {
                return f;
            }
        }
        return null;
    }

    public Flight getFlight(String flightNum, String date) {
        for (Flight f : flights) {
            if (f.getFlightNum().equalsIgnoreCase(flightNum) && f.getDate().equals(date)) {
                return f;
            }
        }
        return null;
    }

    public List<Flight> getAllFlights() {
        return new ArrayList<>(flights);
    }

    public List<Flight> searchFlights(String departure, String arrival) {
        List<Flight> result = new ArrayList<>();

        for (Flight f : flights) {
            if (!isFlightInPast(f) && f.getRoute().getDepartureCity().equalsIgnoreCase(departure)
                    && f.getRoute().getArrivalCity().equalsIgnoreCase(arrival)) {
                result.add(f);
            }
        }
        return result;
    }

    public boolean isFlightInPast(Flight flight) {
        try {
            LocalDate flightDate = LocalDate.parse(flight.getDate());
            LocalTime flightTime = LocalTime.parse(flight.getHour());
            LocalDate today = LocalDate.now();
            LocalTime now = LocalTime.now();

            if (flightDate.isBefore(today)) {
                return true;
            }
            if (flightDate.isEqual(today) && flightTime.isBefore(now)) {
                return true;
            }
            return false;
        } catch (Exception e) {
            return false;
        }
    }

    private void loadFlights() {
        List<String> lines = FileUtil.readAllLines(FILE);

        for (String line : lines) {
            if (line == null || line.trim().isEmpty())
                continue;
            String[] p = line.split(";");
            if (p.length < 9)
                continue;
            try {
                Route route = new Route(p[1], p[2]);
                Plane plane = new Plane(p[6], p[7], Integer.parseInt(p[8]));
                String pilot = (p.length >= 10) ? p[9] : "Unknown Pilot";
                Flight flight = new Flight(p[0], route, p[3], p[4], p[5], plane, pilot);
                flights.add(flight);
            } catch (Exception e) {
                System.out.println("Skipping invalid flight line: " + line);
            }
        }
    }

    private void saveFlights() {
        List<String> lines = new ArrayList<>();
        for (Flight f : flights) {
            lines.add(f.getFlightNum() + ";" + f.getRoute().getDepartureCity() + ";" + f.getRoute().getArrivalCity()
                    + ";" + f.getDate() + ";" + f.getHour() + ";" + f.getDuration() + ";" + f.getPlane().getPlaneID()
                    + ";" + f.getPlane().getPlaneModel() + ";" + f.getPlane().getCapacity() + ";" + f.getPilotName());
        }
        FileUtil.writeAllLines(FILE, lines);
    }

    public List<String> getAllCities() {
        Set<String> cities = new HashSet<>();
        for (Flight f : flights) {
            cities.add(f.getRoute().getDepartureCity());
            cities.add(f.getRoute().getArrivalCity());
        }
        List<String> sortedCities = new ArrayList<>(cities);
        Collections.sort(sortedCities);
        return sortedCities;
    }
}