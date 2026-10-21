package com.airline.gui;

import com.airline.models.*;
import com.airline.managers.*;
import javax.swing.*;
import java.awt.*;
import java.util.List;

public class SeatMapPanel extends JPanel {
    private Flight flight;
    private ReservationManager reservationManager;
    private boolean isSelectionMode;
    private String selectedSeatNum = null;
    private Runnable onSelectionCallback;
    private JDialog parentDialog;

    private static final int COLS = 6;

    public SeatMapPanel(Flight flight, ReservationManager reservationManager, boolean isSelectionMode, JDialog parentDialog){
        this.flight = flight;
        this.reservationManager = reservationManager;
        this.isSelectionMode = isSelectionMode;
        this.parentDialog = parentDialog;

        int capacity = flight.getPlane().getCapacity();
        int dynamicRows = (int) Math.ceil((double) capacity / COLS);
        if (dynamicRows < 1)
            dynamicRows = 1;

        setLayout(new BorderLayout());

        JPanel gridPanel = new JPanel(new GridLayout(dynamicRows, COLS, 5, 5));
        gridPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        List<Reservation> reservations = reservationManager.getReservations();
        List<String> reservedSeats = new java.util.ArrayList<>();
        for (Reservation r : reservations) {
            if (r.getFlight().getFlightNum().equals(flight.getFlightNum()) &&
                    r.getFlight().getDate().equals(flight.getDate())) {
                reservedSeats.add(r.getSeat().getSeatNum());
            }
        }

        char[] colLabels = { 'A', 'B', 'C', 'D', 'E', 'F' };
        for (int r = 1; r <= dynamicRows; r++) {
            for (int c = 0; c < COLS; c++) {
                int seatIndex = ((r - 1) * COLS) + c;
                if (seatIndex >= capacity) {
                    gridPanel.add(new JLabel("")); // Empty placeholder
                    continue;
                }

                String seatNum = r + "" + colLabels[c];
                JButton btn = new JButton(seatNum);
                btn.setPreferredSize(new Dimension(60, 40)); // Increased width from 50 to 60 for "10A"
                btn.setMargin(new Insets(2, 2, 2, 2)); // Reduce margin to show text better

                boolean isReserved = reservedSeats.contains(seatNum);

                if (isReserved) {
                    btn.setBackground(Color.RED);
                    btn.setEnabled(false); // Can't select occupied
                    btn.setToolTipText("Occupied");
                } else {
                    btn.setBackground(Color.GREEN);
                    if (isSelectionMode) {
                        btn.addActionListener(e -> handleSeatSelection(seatNum));
                    } else {
                        btn.setEnabled(false); // View only, vacant but not interactive
                    }
                }

                gridPanel.add(btn);
            }
        }

        JScrollPane scrollPane = new JScrollPane(gridPanel);
        scrollPane.getVerticalScrollBar().setUnitIncrement(16);
        add(scrollPane, BorderLayout.CENTER);

        JPanel legend = new JPanel();
        JLabel l1 = new JLabel("Green: Available");
        l1.setForeground(new Color(0, 128, 0));
        JLabel l2 = new JLabel("Red: Occupied");
        l2.setForeground(Color.RED);
        legend.add(l1);
        legend.add(new JLabel(" | "));
        legend.add(l2);
        add(legend, BorderLayout.SOUTH);
    }

    public void setOnSelectionCallback(Runnable callback) {
        this.onSelectionCallback = callback;
    }

    private void handleSeatSelection(String seatNum) {
        this.selectedSeatNum = seatNum;
        if (onSelectionCallback != null) {
            onSelectionCallback.run();
        }
        if (parentDialog != null) {
            parentDialog.dispose();
        }
    }

    public String getSelectedSeatNum() {
        return selectedSeatNum;
    }
}