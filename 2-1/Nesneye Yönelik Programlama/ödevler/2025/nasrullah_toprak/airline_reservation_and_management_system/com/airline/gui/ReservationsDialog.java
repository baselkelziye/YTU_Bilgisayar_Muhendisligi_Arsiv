package com.airline.gui;

import com.airline.managers.ReservationManager;
import com.airline.models.Passenger;
import com.airline.models.Reservation;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.List;

public class ReservationsDialog extends JDialog {

    private ReservationManager reservationManager;
    private Passenger currentPassenger;
    private JTable activeTable;
    private DefaultTableModel activeModel;
    private JTable historyTable;
    private DefaultTableModel historyModel;

    public ReservationsDialog(Frame owner, ReservationManager reservationManager, Passenger currentPassenger) {
        super(owner, "My Reservations & History", true);
        this.reservationManager = reservationManager;
        this.currentPassenger = currentPassenger;

        setSize(700, 500);
        setLocationRelativeTo(owner);
        setLayout(new BorderLayout());

        JTabbedPane tabbedPane = new JTabbedPane();

        String[] columns = { "Code", "Flight", "Route", "Date", "Seat" };
        activeModel = new DefaultTableModel(columns, 0);
        activeTable = new JTable(activeModel);

        JPanel activePanel = new JPanel(new BorderLayout());
        activePanel.add(new JScrollPane(activeTable), BorderLayout.CENTER);

        JButton cancelBtn = new JButton("Cancel Selected Reservation");
        cancelBtn.addActionListener(e -> cancelReservation());
        JPanel activeBtnPanel = new JPanel();
        activeBtnPanel.add(cancelBtn);
        activePanel.add(activeBtnPanel, BorderLayout.SOUTH);

        tabbedPane.addTab("Active Reservations", activePanel);

        historyModel = new DefaultTableModel(columns, 0);
        historyTable = new JTable(historyModel);
        historyTable.setEnabled(false);

        JPanel historyPanel = new JPanel(new BorderLayout());
        historyPanel.add(new JScrollPane(historyTable), BorderLayout.CENTER);

        tabbedPane.addTab("Flight History", historyPanel);

        add(tabbedPane, BorderLayout.CENTER);

        JButton closeBtn = new JButton("Close");
        closeBtn.addActionListener(e -> dispose());
        JPanel bottomPanel = new JPanel();
        bottomPanel.add(closeBtn);
        add(bottomPanel, BorderLayout.SOUTH);

        loadReservations();
    }

    private void loadReservations() {
        activeModel.setRowCount(0);
        historyModel.setRowCount(0);

        List<Reservation> all = reservationManager.getReservations();
        com.airline.managers.FlightManager fm = new com.airline.managers.FlightManager(); // For date check logic

        for (Reservation r : all) {
            if (r.getPassenger().getPassengerID().equals(currentPassenger.getPassengerID())) {
                boolean isPast = fm.isFlightInPast(r.getFlight());

                Object[] rowData = new Object[] {
                        r.getReservationCode(),
                        r.getFlight().getFlightNum(),
                        r.getFlight().getRoute().getDepartureCity() + " -> "
                                + r.getFlight().getRoute().getArrivalCity(),
                        r.getFlight().getDate() + " " + r.getFlight().getHour(),
                        r.getSeat().getSeatNum()
                };

                if (isPast) {
                    historyModel.addRow(rowData);
                } else {
                    activeModel.addRow(rowData);
                }
            }
        }
    }

    private void cancelReservation() {
        int row = activeTable.getSelectedRow();
        if (row == -1) {
            JOptionPane.showMessageDialog(this, "Select a reservation to cancel.");
            return;
        }

        String code = (String) activeModel.getValueAt(row, 0);
        int confirm = JOptionPane.showConfirmDialog(this, "Cancel reservation " + code + "?", "Confirm",
                JOptionPane.YES_NO_OPTION);

        if (confirm == JOptionPane.YES_OPTION) {
            reservationManager.cancelReservation(code);
            loadReservations(); // Refresh
            JOptionPane.showMessageDialog(this, "Reservation cancelled.");
        }
    }
}
