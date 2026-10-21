package com.airline.gui;

import javax.swing.*;
import java.awt.*;

public class LoginPanel extends JPanel {

    public LoginPanel(MainFrame mainFrame) {
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(15, 15, 15, 15);

        JButton adminBtn = new JButton("Admin Entrance");
        JButton userBtn = new JButton("Passenger Entrance");

        adminBtn.setPreferredSize(new Dimension(200, 50));
        userBtn.setPreferredSize(new Dimension(200, 50));

        gbc.gridy = 0;
        add(adminBtn, gbc);
        gbc.gridy = 1;
        add(userBtn, gbc);

        adminBtn.addActionListener(e -> mainFrame.showCard("ADMIN"));
        userBtn.addActionListener(e -> mainFrame.showCard("USER_ENTRY"));
    }
}