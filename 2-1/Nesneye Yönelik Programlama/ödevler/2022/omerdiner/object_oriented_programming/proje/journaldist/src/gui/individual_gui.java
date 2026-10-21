package gui;

import backend.Distributor;
import backend.Individual;

import javax.swing.*;
import java.awt.*;

public class individual_gui extends JFrame {

private Distributor distributor = new Distributor();
    public individual_gui() {
        super("Kisi Ekle");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        distributor.loadState("db.bin");

        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));


        JLabel nameLabel = new JLabel("Name:");
        JLabel addressLabel = new JLabel("Address:");
        JLabel creditCardNrLabel = new JLabel("Credit Card Number:");
        JLabel expireMonthLabel = new JLabel("Expire Month:");
        JLabel expireYearLabel = new JLabel("Expire Year:");
        JLabel CCVLabel = new JLabel("CCV:");


        JTextField name = new JTextField(10);
        JTextField address = new JTextField(10);
        JTextField creditCardNr = new JTextField(10);
        JTextField expireMonth = new JTextField(10);
        JTextField expireYear = new JTextField(10);
        JTextField CCV = new JTextField(10);
        JButton olustur_btn = new JButton("Olustur");
        JButton ana_menu_btn = new JButton("Ana menu");

        addLabelAndInput(panel, nameLabel, name);
        addLabelAndInput(panel, addressLabel, address);
        addLabelAndInput(panel, creditCardNrLabel, creditCardNr);
        addLabelAndInput(panel, expireMonthLabel, expireMonth);
        addLabelAndInput(panel, expireYearLabel, expireYear);
        addLabelAndInput(panel, CCVLabel, CCV);

        panel.add(olustur_btn);
        panel.add(ana_menu_btn);

        add(panel);

        olustur_btn.addActionListener(e -> {
            dispose();
            Individual individual = new Individual(name.getText(), address.getText(), creditCardNr.getText(), Integer.parseInt(expireMonth.getText()), Integer.parseInt(expireYear.getText()), Integer.parseInt(CCV.getText()));
            distributor.addSubscriber(individual);
            distributor.saveState("db.bin");
            JOptionPane.showMessageDialog(null, "Kisi ekleme basarili.");

            new main_gui().setVisible(true);
        });

        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
    public void addLabelAndInput(JPanel panel, JLabel label, JTextField input){
        panel.add(label);
        panel.add(input);
    }


}
