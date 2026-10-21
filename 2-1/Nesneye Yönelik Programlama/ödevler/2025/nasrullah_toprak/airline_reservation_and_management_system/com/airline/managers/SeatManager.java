package com.airline.managers;

import com.airline.models.*;

public class SeatManager {

    public synchronized void reserveSeat(Flight flight, String seatNum) throws Exception{
        Seat seat = flight.getPlane().getSeat(seatNum);
        if (seat == null) {
            throw new Exception("Seat not found");
        }
        if (seat.isReserved()) {
            throw new Exception("Seat unavailable (Already Reserved)");
        }
        seat.setReserved(true);
    }

    public synchronized void cancelSeat(Flight flight, String seatNum){
        Seat seat = flight.getPlane().getSeat(seatNum);
        if (seat != null) {
            seat.setReserved(false);
        }
    }

    public int getAvailableSeatsCount(Flight flight){
        int count = 0;
        Seat[][] seats = flight.getPlane().getSeatMatrix();
        for (Seat[] row : seats) {
            for (Seat seat : row) {
                if (seat != null && !seat.isReserved()) {
                    count++;
                }
            }
        }
        return count;
    }
}