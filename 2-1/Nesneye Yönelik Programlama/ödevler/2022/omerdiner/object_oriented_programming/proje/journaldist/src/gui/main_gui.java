package gui;

import backend.Distributor;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class main_gui extends JFrame {


    public main_gui() {
        super("Ana Menu");
        setLayout(new FlowLayout());
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        JButton subscriber_btn = new JButton("Subscriber Menu");
        JButton journal_btn = new JButton("Journal Menu");
        JButton subscription_btn = new JButton("Subscription Menu");
        JButton payment_btn = new JButton("Odeme Yap");
        JButton list_incomplete_payment_btn = new JButton("Odemesi Eksik Aboneler");
        JButton list_sending_orders_btn = new JButton("Giden Siparisler ISSN");
        JButton list_all_sending_orders_btn = new JButton("Giden Tum Siparisler");

        JButton cikis_btn = new JButton("CIKIS");


        cikis_btn.setBackground(Color.RED);

        add(subscriber_btn);
        add(journal_btn);
        add(subscription_btn);
        add(payment_btn);
        add(list_incomplete_payment_btn);
        add(list_sending_orders_btn);
        add(list_all_sending_orders_btn);

        add(cikis_btn);

        subscriber_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new subscriber_gui().setVisible(true);

            }
        });

        journal_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new journal_gui().setVisible(true);

            }
        });

        subscription_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new subscription_gui().setVisible(true);

            }
        });

        payment_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new payment_gui().setVisible(true);

            }
        });

        list_incomplete_payment_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                Distributor distributor = new Distributor();
                distributor.loadState("db.bin");
                String message = distributor.listIncompletePayments();
                JOptionPane.showMessageDialog(null, message);


            }
        });

        list_sending_orders_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new list_sending_orders_gui().setVisible(true);


            }
        });


        list_all_sending_orders_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                new list_all_sending_orders_gui().setVisible(true);

            }
        });




        cikis_btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose();
                System.exit(0);

            }
        });
    }



}
