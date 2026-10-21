package com.airline.gui;

import com.airline.models.*;
import com.airline.managers.*;
import java.util.List;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.GridLayout;

public class AdminPanel extends JPanel {
    private ReservationManager reservationManager;
    private FlightManager flightManager;
    private JTable flightTable;
    private DefaultTableModel tableModel;
    private JLabel statusLabel;

    public AdminPanel(MainFrame mainFrame, FlightManager flightManager, ReservationManager reservationManager) {
        this.flightManager = flightManager;
        this.reservationManager = reservationManager;
        setLayout(new BorderLayout());

        // Header
        JPanel header = new JPanel(new BorderLayout());
        header.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        header.add(new JLabel("<html><h2>Admin Dashboard</h2></html>"), BorderLayout.WEST);

        JButton logoutBtn = new JButton("Logout");
        logoutBtn.addActionListener(e -> mainFrame.showCard("LOGIN"));
        header.add(logoutBtn, BorderLayout.EAST);
        add(header, BorderLayout.NORTH);

        // Table
        // Table
        String[] columns = { "Flight Num", "From", "To", "Date", "Hour", "Pilot", "Status" };
        tableModel = new DefaultTableModel(columns, 0) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        flightTable = new JTable(tableModel);

        flightTable.setDefaultRenderer(Object.class, new javax.swing.table.DefaultTableCellRenderer() {
            @Override
            public java.awt.Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                java.awt.Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

                String status = (String) table.getModel().getValueAt(row, 6);
                if ("Completed".equals(status)) {
                    c.setForeground(java.awt.Color.GRAY);
                } else {
                    c.setForeground(java.awt.Color.BLACK);
                }

                if (isSelected) {
                    c.setForeground(table.getSelectionForeground());
                }
                return c;
            }
        });

        add(new JScrollPane(flightTable), BorderLayout.CENTER);

        // Controls
        JPanel controlPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        JButton addBtn = new JButton("Add Flight");
        JButton editBtn = new JButton("Edit Selected");
        JButton detailsBtn = new JButton("View Details");
        JButton refreshBtn = new JButton("Refresh");

        // Scenario Buttons
        JButton simBtn = new JButton("Run Seat Simulation (Scenario 1)");
        JButton reportBtn = new JButton("Generate Report (Scenario 2)");

        addBtn.addActionListener(e -> showFlightDialog(null));
        editBtn.addActionListener(e -> handleEditAction());
        detailsBtn.addActionListener(e -> showFlightDetails());
        refreshBtn.addActionListener(e -> refreshTable());

        simBtn.addActionListener(e -> mainFrame.showCard("SIMULATION"));
        reportBtn.addActionListener(e -> generateReport());

        controlPanel.add(addBtn);
        controlPanel.add(editBtn);
        controlPanel.add(detailsBtn);
        controlPanel.add(refreshBtn);
        controlPanel.add(simBtn);
        controlPanel.add(reportBtn);

        JPanel bottomPanel = new JPanel(new BorderLayout());
        statusLabel = new JLabel("System Ready");
        statusLabel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        bottomPanel.add(controlPanel, BorderLayout.CENTER);
        bottomPanel.add(statusLabel, BorderLayout.SOUTH);

        add(bottomPanel, BorderLayout.SOUTH);

        refreshTable();
    }

    private void showFlightDetails() {
        int selectedRow = flightTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Please select a flight to view details.");
            return;
        }

        String flightNum = (String) tableModel.getValueAt(selectedRow, 0);
        String date = (String) tableModel.getValueAt(selectedRow, 3);

        Flight flight = flightManager.getFlight(flightNum, date);
        if (flight == null)
            return;

        List<Reservation> allReservations = reservationManager.getReservations();
        List<Reservation> flightReservations = new ArrayList<>();
        for (Reservation r : allReservations) {
            if (r.getFlight().getFlightNum().equals(flight.getFlightNum()) &&
                    r.getFlight().getDate().equals(flight.getDate())) {
                flightReservations.add(r);
            }
        }

        int totalSeats = flight.getPlane().getCapacity();
        int reservedSeats = flightReservations.size();
        double occupancyRate = totalSeats > 0 ? ((double) reservedSeats / totalSeats) * 100 : 0;

        JDialog dialog = new JDialog((Frame) SwingUtilities.getWindowAncestor(this),"Flight Details: " + flightNum,true);
        dialog.setSize(900, 500);
        dialog.setLocationRelativeTo(this);
        dialog.setLayout(new BorderLayout());

        JPanel leftPanel = new JPanel(new BorderLayout());

        JPanel infoPanel = new JPanel(new GridLayout(3, 1));
        infoPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        infoPanel.add(new JLabel("Plane: " + flight.getPlane().getPlaneModel() + " (" + flight.getPlane().getPlaneID() + ")"));
        infoPanel.add(new JLabel(String.format("Occupancy: %d / %d (%.1f%%)", reservedSeats, totalSeats, occupancyRate)));

        JProgressBar progressBar = new JProgressBar(0, totalSeats);
        progressBar.setValue(reservedSeats);
        progressBar.setStringPainted(true);
        infoPanel.add(progressBar);
        leftPanel.add(infoPanel, BorderLayout.NORTH);

        String[] cols = { "Seat", "Passenger Name", "Contact", "Res Code" };
        DefaultTableModel model = new DefaultTableModel(cols, 0);
        for (Reservation r : flightReservations) {
            model.addRow(new Object[] {
                    r.getSeat().getSeatNum(), r.getPassenger().getName() + " " + r.getPassenger().getSurname(),r.getPassenger().getContactInfo(),r.getReservationCode()
            });
        }
        JTable table = new JTable(model);
        leftPanel.add(new JScrollPane(table), BorderLayout.CENTER);

        SeatMapPanel seatMap = new SeatMapPanel(flight, reservationManager, false, null); // View Only
        seatMap.setBorder(BorderFactory.createTitledBorder("Seat Map"));

        JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, seatMap);
        splitPane.setDividerLocation(500);
        dialog.add(splitPane, BorderLayout.CENTER);

        JButton closeBtn = new JButton("Close");
        closeBtn.addActionListener(e -> dialog.dispose());
        JPanel btnPanel = new JPanel();
        btnPanel.add(closeBtn);
        dialog.add(btnPanel, BorderLayout.SOUTH);

        dialog.setVisible(true);
    }

    private void generateReport() {
        statusLabel.setText("Preparing admin report...");

        ReportGenerator rg = new ReportGenerator(result -> {statusLabel.setText("System Ready");
            JTextArea textArea = new JTextArea(result);
            textArea.setEditable(false);
            JScrollPane scrollPane = new JScrollPane(textArea);
            scrollPane.setPreferredSize(new Dimension(500, 400));

            JOptionPane.showMessageDialog(this, scrollPane, "Admin Report", JOptionPane.INFORMATION_MESSAGE);
        }, flightManager, reservationManager);

        rg.execute();
    }

    private void handleEditAction() {
        int selectedRow = flightTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Please select a flight to edit.");
            return;
        }
        String flightNum = (String) tableModel.getValueAt(selectedRow, 0);
        Flight flight = flightManager.getFlight(flightNum);
        showFlightDialog(flight);
    }

    private void showFlightDialog(Flight existingFlight) {
        boolean isEdit = (existingFlight != null);
        String title = isEdit ? "Edit Flight: " + existingFlight.getFlightNum() : "Add New Flight";

        JDialog dialog = new JDialog((Frame) SwingUtilities.getWindowAncestor(this), title, true);
        dialog.setLayout(new GridLayout(7, 2, 10, 10));

        JTextField numField = new JTextField(isEdit ? existingFlight.getFlightNum() : "");
        if (isEdit)
            numField.setEditable(false);
        JTextField fromField = new JTextField(isEdit ? existingFlight.getRoute().getDepartureCity() : "");
        JTextField toField = new JTextField(isEdit ? existingFlight.getRoute().getArrivalCity() : "");
        JTextField dateField = new JTextField(isEdit ? existingFlight.getDate() : "2026-01-01");
        JTextField hourField = new JTextField(isEdit ? existingFlight.getHour() : "12:00");
        JTextField pilotField = new JTextField(isEdit ? existingFlight.getPilotName() : "Unknown");
        dialog.add(new JLabel("Flight Num:"));
        dialog.add(numField);
        dialog.add(new JLabel("From:"));
        dialog.add(fromField);
        dialog.add(new JLabel("To:"));
        dialog.add(toField);
        dialog.add(new JLabel("Date (YYYY-MM-DD):"));
        dialog.add(dateField);
        dialog.add(new JLabel("Hour (HH:mm):"));
        dialog.add(hourField);
        dialog.add(new JLabel("Pilot Name:"));
        dialog.add(pilotField);

        JButton saveBtn = new JButton(isEdit ? "Update" : "Save");
        saveBtn.addActionListener(e -> {
            try {
                Route route = new Route(fromField.getText(), toField.getText());
                if (isEdit) {
                    existingFlight.setRoute(route);
                    existingFlight.setDate(dateField.getText());
                    existingFlight.setHour(hourField.getText());
                    existingFlight.setPilotName(pilotField.getText());
                    flightManager.updateFlight(existingFlight); // Fix: Force save updates
                } else {
                    Plane plane = new Plane("P" + System.currentTimeMillis(), "Boeing 737", 180);
                    Flight newFlight = new Flight(numField.getText(), route, dateField.getText(), hourField.getText(),
                            "2h", plane, pilotField.getText());
                    flightManager.addFlight(newFlight);
                }
                refreshTable();
                dialog.dispose();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(dialog, "Error saving flight: " + ex.getMessage());
            }
        });

        dialog.add(new JLabel(""));
        dialog.add(saveBtn);
        dialog.pack();
        dialog.setLocationRelativeTo(this);
        dialog.setVisible(true);
    }

    public void refreshTable() {
        tableModel.setRowCount(0);
        for (Flight f : flightManager.getAllFlights()) {
            boolean isPast = flightManager.isFlightInPast(f);
            String status = isPast ? "Completed" : "Active";

            tableModel.addRow(new Object[] {
                    f.getFlightNum(),
                    f.getRoute().getDepartureCity(),
                    f.getRoute().getArrivalCity(),
                    f.getDate(),
                    f.getHour(),
                    f.getPilotName(),
                    status
            });
        }
    }
}