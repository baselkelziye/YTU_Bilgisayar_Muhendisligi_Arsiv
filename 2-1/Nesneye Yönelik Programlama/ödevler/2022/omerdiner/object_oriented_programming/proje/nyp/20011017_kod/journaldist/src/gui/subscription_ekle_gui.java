package gui;

import backend.*;

import javax.swing.*;
import java.awt.*;


public class subscription_ekle_gui extends JFrame {
    private Distributor distributor = new Distributor();

    public subscription_ekle_gui() {
        super("Subscription Ekle");

        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        distributor.loadState("db.bin");

        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));


        JLabel startMonthLabel = new JLabel("Start Month:");
        JLabel endMonthLabel = new JLabel("End Month:");
        JLabel startYearLabel = new JLabel("Start Year:");
        JLabel copiesLabel = new JLabel("Copies:");
        JLabel journalIssnLabel = new JLabel("Journal ISSN:");
        JLabel subscriberNameLabel = new JLabel("Subscriber Name:");

        JTextField startMonth = new JTextField(10);

        JTextField endMonth = new JTextField(10);

        JTextField startYear = new JTextField(10);

        JTextField copies = new JTextField(10);

        JTextField journalIssn = new JTextField(10);

        JTextField subscriberName = new JTextField(10);


        addLabelAndInput(panel, startMonthLabel, startMonth);

        addLabelAndInput(panel, endMonthLabel, endMonth);

        addLabelAndInput(panel, startYearLabel, startYear);

        addLabelAndInput(panel, copiesLabel, copies);

        addLabelAndInput(panel, journalIssnLabel, journalIssn);

        addLabelAndInput(panel, subscriberNameLabel, subscriberName);


        JButton olustur_btn = new JButton("Olustur");
        JButton ana_menu_btn = new JButton("Ana Menu");

        panel.add(olustur_btn);
        panel.add(ana_menu_btn);

        add(panel);

        olustur_btn.addActionListener(e -> {
            dispose();
            DateInfo date = new DateInfo(Integer.parseInt(startMonth.getText()), Integer.parseInt(endMonth.getText()), Integer.parseInt(startYear.getText()));
            Journal journal = distributor.searchJournal(journalIssn.getText());
            Subscriber subscriber = distributor.searchSubscriber(subscriberName.getText());
            Subscription subscription = new Subscription(date, Integer.parseInt(copies.getText()), journal, subscriber);


            distributor.addSubscription(journalIssn.getText(), subscriber, subscription);
            distributor.saveState("db.bin");
            JOptionPane.showMessageDialog(null, "Subscription ekleme basarili.");

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
