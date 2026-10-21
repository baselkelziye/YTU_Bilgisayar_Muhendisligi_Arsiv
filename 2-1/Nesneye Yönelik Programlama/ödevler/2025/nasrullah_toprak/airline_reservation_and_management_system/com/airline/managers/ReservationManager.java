package com.airline.managers;

import com.airline.models.Flight;
import com.airline.models.Passenger;
import com.airline.models.Reservation;
import com.airline.models.Seat;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;
import com.airline.util.FileUtil;

public class ReservationManager {
    private static final String FILE = "data/reservations.txt";
    private List<Reservation> reservations;
    private SeatManager seatManager;

    public ReservationManager() {
        this.reservations = new ArrayList<>();
        this.seatManager = new SeatManager();
        loadReservations();
    }

    public synchronized Reservation createReservation(Flight flight, Passenger passenger, String seatNum) throws Exception{
        seatManager.reserveSeat(flight, seatNum);
        Reservation val = new Reservation(UUID.randomUUID().toString().substring(0, 8).toUpperCase(), flight, passenger, flight.getPlane().getSeat(seatNum));
        reservations.add(val);
        saveReservations();
        return val;
    }

    private void saveReservations() {
        List<String> lines = new ArrayList<>();

        for (Reservation r:reservations) {
            lines.add(r.getReservationCode() + ";" + r.getFlight().getFlightNum() + ";" + r.getPassenger().getPassengerID() + ";" + r.getSeat().getSeatNum() + ";" + r.getFlight().getDate()); // Add Date persistence
        }
        FileUtil.writeAllLines(FILE, lines);
    }

    public synchronized void cancelReservation(String reservationCode){
        Reservation toExclude = null;

        for (Reservation r : reservations) {
            if (toExclude == null && r.getReservationCode().equals(reservationCode)){
                toExclude = r;
            }
        }

        if (toExclude != null) {
            seatManager.cancelSeat(toExclude.getFlight(), toExclude.getSeat().getSeatNum());
            reservations.remove(toExclude);
            saveReservations();
        }
    }

    public List<Reservation> getReservations(){
        return new ArrayList<>(reservations);
    }

    private void loadReservations(){
        FlightManager flightManager = new FlightManager();
        PassengerManager passengerManager = new PassengerManager();

        List<String> lines = FileUtil.readAllLines(FILE);

        for (String line : lines){
            try {
                boolean validLine = true;
                if (line == null){
                    validLine = false;
                } else if (line.trim().isEmpty()){
                    validLine = false;
                }
                if (validLine){
                    String[] p = line.split(";");
                    if (p.length < 4) {
                        validLine = false;
                    }
                    if (validLine){
                        String resCode = p[0];
                        String flightNum = p[1];
                        String passId = p[2];
                        String seatNum = p[3];
                        String date = null;
                        if (p.length >= 5){
                            date = p[4];
                        }
                        Flight flight = null;
                        if (date != null){
                            flight = flightManager.getFlight(flightNum, date);
                        } else {
                            flight = flightManager.getFlight(flightNum);
                        }
                        Passenger passenger = null;
                        boolean foundPassenger = false;

                        for (Passenger pax : passengerManager.getAllPassengers()) {
                            if (!foundPassenger) {
                                if (pax.getPassengerID().equals(passId)) {
                                    passenger = pax;
                                    foundPassenger = true;
                                }
                            }
                        }
                        if (flight != null && passenger != null) {
                            Seat seat = flight.getPlane().getSeat(seatNum);
                            if (seat != null) {
                                seat.setReserved(true);
                                Reservation res = new Reservation(resCode, flight, passenger, seat);
                                reservations.add(res);
                            }
                        }
                    }
                }
            } catch (Exception e) {
                System.out.println("Error loading reservation: " + line);
            }
        }
    }
}