package gui;


import backend.Distributor;

import javax.swing.*;
import java.awt.*;


public class list_all_sending_orders_gui extends JFrame {
    private Distributor distributor;

    public list_all_sending_orders_gui() {
        super("All Sending Orders List");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        getContentPane().setBackground(Color.LIGHT_GRAY);

        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));
        panel.setBackground(Color.LIGHT_GRAY);

        JLabel ayLabel = new JLabel("Ay:");
        JTextField ayTextField = new JTextField(15);


        JLabel yilLabel = new JLabel("Yil:");
        JTextField yilTextField = new JTextField(15);


        JButton listele_btn = new JButton("Listele");
        JButton ana_menu_btn = new JButton("Ana Menu");

        addLabelAndInput(panel, ayLabel, ayTextField);
        addLabelAndInput(panel, yilLabel, yilTextField);

        panel.add(listele_btn);
        panel.add(ana_menu_btn);


        add(panel);


        listele_btn.setBackground(Color.BLUE);
        ana_menu_btn.setBackground(Color.GREEN);


        listele_btn.setForeground(Color.WHITE);
        ana_menu_btn.setForeground(Color.WHITE);

        Font font = new Font("Arial", Font.PLAIN, 14);
        ayLabel.setFont(font);
        ayTextField.setFont(font);

        listele_btn.addActionListener(e -> {
            dispose();
            distributor = new Distributor();
            distributor.loadState("db.bin");

            String paragraph = distributor.listAllSendingOrders(Integer.parseInt(ayTextField.getText()), Integer.parseInt(yilTextField.getText()));

            JOptionPane.showMessageDialog(null, paragraph);


            new main_gui().setVisible(true);
        });

        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }

    public void addLabelAndInput(JPanel panel, JLabel label, JTextField input) {
        panel.add(label);
        panel.add(input);
    }
}
