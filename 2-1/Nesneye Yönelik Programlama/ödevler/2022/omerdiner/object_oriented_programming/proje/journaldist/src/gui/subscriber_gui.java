package gui;

import javax.swing.*;

public class subscriber_gui  extends JFrame {

    public subscriber_gui() {
        super("Subscriber Menu");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        JButton individual_btn = new JButton("Individual Ekle");
        JButton corporation_btn = new JButton("Corporation Ekle");

        JButton search_btn = new JButton("Subscriber Ara");
        JButton ana_menu_btn = new JButton("Ana Menu");


        add(individual_btn);
        add(corporation_btn);
        add(search_btn);
        add(ana_menu_btn);
        individual_btn.addActionListener(e -> {
            dispose();
            new individual_gui().setVisible(true);
        });

        corporation_btn.addActionListener(e -> {
            dispose();
            new corporation_gui().setVisible(true);
        });

        search_btn.addActionListener(e -> {
            dispose();
            new search_subscriber_gui().setVisible(true);
        });
        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
}
