package com.airline.gui;

import com.airline.managers.*;
import com.airline.models.*;
import javax.swing.*;
import java.awt.*;

public class MainFrame extends JFrame {

    private CardLayout cardLayout;
    private JPanel mainPanel;
    private FlightManager flightManager;
    private ReservationManager reservationManager;
    private PassengerManager passengerManager;
    private Passenger currentPassenger;

    public MainFrame(){
        flightManager = new FlightManager();
        reservationManager = new ReservationManager();
        passengerManager = new PassengerManager();

        setTitle("Airline Reservation System - Management Console");
        setSize(1000, 700);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);

        mainPanel.add(new LoginPanel(this), "LOGIN");
        mainPanel.add(new AdminPanel(this, flightManager, reservationManager), "ADMIN");
        mainPanel.add(new UserEntryPanel(this, passengerManager), "USER_ENTRY");
        mainPanel.add(new FlightSearchPanel(this, flightManager, reservationManager), "SEARCH");

        JPanel simWrapper = new JPanel(new BorderLayout());
        simWrapper.add(new SeatSimulationPanel(), BorderLayout.CENTER);
        JButton backBtn = new JButton("Return to Admin Dashboard");
        backBtn.setFont(new Font("Arial", Font.BOLD, 14));
        backBtn.addActionListener(e -> showCard("ADMIN"));
        simWrapper.add(backBtn, BorderLayout.SOUTH);

        mainPanel.add(simWrapper, "SIMULATION");

        add(mainPanel);
        showCard("LOGIN");
    }

    public void showCard(String name){
        cardLayout.show(mainPanel, name);
        if (name.equals("SEARCH")) {
            for (Component comp : mainPanel.getComponents()) {
                if (comp instanceof FlightSearchPanel) {
                    ((FlightSearchPanel) comp).refreshData();
                }
            }
        }
    }

    public void setCurrentPassenger(Passenger p){
        this.currentPassenger = p;
    }

    public Passenger getCurrentPassenger(){
        return currentPassenger;
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(() -> new MainFrame().setVisible(true));
    }
}