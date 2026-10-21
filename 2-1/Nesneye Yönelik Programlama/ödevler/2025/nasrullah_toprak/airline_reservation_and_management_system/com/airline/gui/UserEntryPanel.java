package com.airline.gui;

import com.airline.managers.PassengerManager;
import com.airline.models.Passenger;

import javax.swing.*;
import java.awt.*;
import java.util.UUID;

public class UserEntryPanel extends JPanel {

    private PassengerManager passengerManager;
    private MainFrame mainFrame;

    private JTextField nameField;
    private JTextField surnameField;
    private JPasswordField passwordField;

    public UserEntryPanel(MainFrame mainFrame, PassengerManager passengerManager) {
        this.mainFrame = mainFrame;
        this.passengerManager = passengerManager;

        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        nameField = new JTextField(15);
        surnameField = new JTextField(15);
        passwordField = new JPasswordField(15);

        addField("Name:", nameField, gbc, 0);
        addField("Surname:", surnameField, gbc, 1);
        addField("Contact Info:", passwordField, gbc, 2);

        JButton loginBtn = new JButton("Login");
        JButton registerBtn = new JButton("Register");
        JButton backBtn = new JButton("Back");

        JPanel btnPanel = new JPanel();
        btnPanel.add(loginBtn);
        btnPanel.add(registerBtn);
        btnPanel.add(backBtn);

        gbc.gridy = 3;
        gbc.gridwidth = 2;
        add(btnPanel, gbc);

        loginBtn.addActionListener(e -> login());
        registerBtn.addActionListener(e -> register());
        backBtn.addActionListener(e -> mainFrame.showCard("LOGIN"));
    }

    private void addField(String label,JTextField field,GridBagConstraints gbc, int row) {
        gbc.gridx = 0;
        gbc.gridy = row;
        add(new JLabel(label), gbc);
        gbc.gridx = 1;
        add(field, gbc);
    }

    private void login() {
        Passenger p = findPassenger();
        if (p == null) {
            JOptionPane.showMessageDialog(this, "Passenger not found.");
            return;
        }
        mainFrame.setCurrentPassenger(p);
        mainFrame.showCard("SEARCH");
    }

    private void register() {
        Passenger p = findPassenger();
        if (p != null) {
            JOptionPane.showMessageDialog(this, "Passenger already exists.");
            return;
        }

        String contactInfo = new String(passwordField.getPassword());

        Passenger newP = new Passenger(
                "P-" + UUID.randomUUID().toString().substring(0, 5),
                nameField.getText(),
                surnameField.getText(),
                contactInfo);

        passengerManager.addPassenger(newP);
        mainFrame.setCurrentPassenger(newP);
        mainFrame.showCard("SEARCH");
    }

    private Passenger findPassenger() {
        for (Passenger p : passengerManager.getAllPassengers()){
            if (p.getName().equalsIgnoreCase(nameField.getText()) &&
                    p.getSurname().equalsIgnoreCase(surnameField.getText()) &&
                    p.getContactInfo().equals(new String(passwordField.getPassword()))) {
                return p;
            }
        }
        return null;
    }
}