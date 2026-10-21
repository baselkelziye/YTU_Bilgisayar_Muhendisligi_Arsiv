package com.airline.gui;

import com.airline.managers.*;
import com.airline.models.*;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.List;

public class FlightSearchPanel extends JPanel {

    private FlightManager flightManager;
    private ReservationManager reservationManager;
    private MainFrame mainFrame;

    private JTable flightTable;
    private DefaultTableModel tableModel;
    private JComboBox<String> fromCombo, toCombo;

    public FlightSearchPanel(MainFrame mainFrame,
            FlightManager flightManager,
            ReservationManager reservationManager) {

        this.mainFrame = mainFrame;
        this.flightManager = flightManager;
        this.reservationManager = reservationManager;
        setLayout(new BorderLayout());
        JPanel topPanel = new JPanel(new BorderLayout());
        JPanel searchBar = new JPanel();

        List<String> cities = flightManager.getAllCities();
        String[] cityArray = cities.toArray(new String[0]);

        fromCombo = new JComboBox<>(cityArray);
        toCombo = new JComboBox<>(cityArray);

        if (cities.size() > 1) {
            toCombo.setSelectedIndex(1);
        }

        JButton searchBtn = new JButton("Search Flights");
        searchBtn.addActionListener(e -> search());

        JButton myResBtn = new JButton("My Reservations");
        myResBtn.addActionListener(e -> showMyReservations());

        searchBar.add(new JLabel("From:"));
        searchBar.add(fromCombo);
        searchBar.add(new JLabel("To:"));
        searchBar.add(toCombo);
        searchBar.add(searchBtn);
        searchBar.add(myResBtn);

        JButton logoutBtn = new JButton("Logout");
        logoutBtn.addActionListener(e -> mainFrame.showCard("LOGIN"));

        topPanel.add(searchBar, BorderLayout.CENTER);
        topPanel.add(logoutBtn, BorderLayout.EAST);
        add(topPanel, BorderLayout.NORTH);

        String[] columns = { "Flight Num", "From", "To", "Date", "Hour" };
        tableModel = new DefaultTableModel(columns, 0);
        flightTable = new JTable(tableModel);
        add(new JScrollPane(flightTable), BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel();
        JButton bookBtn = new JButton("Book Selected Flight");
        bookBtn.setPreferredSize(new Dimension(200, 30));
        bookBtn.addActionListener(e -> bookFlight());

        bottomPanel.add(bookBtn);
        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void search() {
        String from = (String) fromCombo.getSelectedItem();
        String to = (String) toCombo.getSelectedItem();

        List<Flight> results = flightManager.searchFlights(from, to);
        tableModel.setRowCount(0);
        for (Flight f : results) {
            tableModel.addRow(new Object[] {
                    f.getFlightNum(),
                    f.getRoute().getDepartureCity(),
                    f.getRoute().getArrivalCity(),
                    f.getDate(),
                    f.getHour()
            });
        }
    }

    private void showMyReservations() {
        Passenger p = mainFrame.getCurrentPassenger();
        new ReservationsDialog(mainFrame, reservationManager, p).setVisible(true);
    }

    private void bookFlight() {
        int row = flightTable.getSelectedRow();
        if (row == -1) {
            JOptionPane.showMessageDialog(this, "Select a flight first.");
            return;
        }

        String flightNum = (String) tableModel.getValueAt(row, 0);
        Flight flight = flightManager.getFlight(flightNum);

        JDialog seatDialog = new JDialog(mainFrame, "Select Seat", true);
        seatDialog.setSize(400, 500);
        seatDialog.setLocationRelativeTo(this);

        SeatMapPanel seatMap = new SeatMapPanel(flight, reservationManager, true, seatDialog);
        seatDialog.add(seatMap);

        seatMap.setOnSelectionCallback(() -> {
            String seat = seatMap.getSelectedSeatNum();
            if (seat != null) {
                try {
                    Passenger p = mainFrame.getCurrentPassenger();
                    reservationManager.createReservation(flight, p, seat);
                    JOptionPane.showMessageDialog(this, "Reservation Successful! Seat: " + seat);
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(this, ex.getMessage());
                }
            }
        });

        seatDialog.setVisible(true);
    }

    public void refreshData() {
        List<String> cities = flightManager.getAllCities();
        fromCombo.removeAllItems();
        toCombo.removeAllItems();

        for (String city : cities) {
            fromCombo.addItem(city);
            toCombo.addItem(city);
        }

        if (cities.size() > 1) {
            toCombo.setSelectedIndex(1);
        } else if (cities.size() > 0) {
            toCombo.setSelectedIndex(0);
        }

        tableModel.setRowCount(0);
    }
}