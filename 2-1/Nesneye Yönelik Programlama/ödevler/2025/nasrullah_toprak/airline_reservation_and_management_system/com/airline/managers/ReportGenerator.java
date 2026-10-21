package com.airline.managers;

import javax.swing.SwingWorker;
import com.airline.models.*;
import java.util.List;

public class ReportGenerator extends SwingWorker<String, Void> {

    public interface ReportListener {
        void onReportFinished(String result);
    }

    private ReportListener listener;
    private FlightManager flightManager;
    private ReservationManager reservationManager;

    public ReportGenerator(ReportListener listener, FlightManager flightManager,
            ReservationManager reservationManager) {
        this.listener = listener;
        this.flightManager = flightManager;
        this.reservationManager = reservationManager;
    }

    @Override
    protected String doInBackground() throws Exception {
        Thread.sleep(1500);

        StringBuilder report = new StringBuilder();
        report.append("=== Airline Occupancy Report ===\n\n");

        List<Flight> flights = flightManager.getAllFlights();
        List<Reservation> allReservations = reservationManager.getReservations();

        int totalSeatsAll = 0;
        int totalReservedAll = 0;

        for (Flight f : flights) {
            int capacity = f.getPlane().getCapacity();
            int reserved = 0;

            for (Reservation r : allReservations) {
                if (r.getFlight().getFlightNum().equals(f.getFlightNum()) &&
                        r.getFlight().getDate().equals(f.getDate())) {
                    reserved++;
                }
            }

            double rate = capacity > 0 ? ((double) reserved / capacity) * 100 : 0;

            report.append(String.format("Flight %s (%s -> %s)\n", f.getFlightNum(), f.getRoute().getDepartureCity(),
                    f.getRoute().getArrivalCity()));
            report.append(String.format("   Date: %s %s\n", f.getDate(), f.getHour()));
            report.append(String.format("   Occupancy: %d / %d (%.1f%%)\n", reserved, capacity, rate));
            report.append("------------------------------------------------\n");

            totalSeatsAll += capacity;
            totalReservedAll += reserved;
        }

        double globalRate = totalSeatsAll > 0 ? ((double) totalReservedAll / totalSeatsAll) * 100 : 0;
        report.append(String.format("\nOverall System Occupancy: %.1f%%\n", globalRate));
        report.append(String.format("Total Revenue (Est.): $%d\n", totalReservedAll * 100)); // Dummy revenue logic

        return report.toString();
    }

    @Override
    protected void done() {
        try {
            String result = get();
            listener.onReportFinished(result);
        } catch (Exception e) {
            listener.onReportFinished("Error generating report: " + e.getMessage());
        }
    }
}