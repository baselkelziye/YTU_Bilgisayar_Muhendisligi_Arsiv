package gui;

import javax.swing.*;

public class subscription_gui extends JFrame {
    public subscription_gui() {
        super("Subscription Menu");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        JButton subscription_ekle = new JButton("Subscription Ekle");
        JButton ada_gore_listele = new JButton("Subscription Listele(Ada gore)");
        JButton issn_gore_listele = new JButton("Subscription Listele(Issn gore)");
        JButton ana_menu_btn = new JButton("Ana Menu");


        add(subscription_ekle);
        add(ada_gore_listele);
        add(issn_gore_listele);
        add(ana_menu_btn);

        subscription_ekle.addActionListener(e -> {
            dispose();
            new subscription_ekle_gui().setVisible(true);
        });

        ada_gore_listele.addActionListener(e -> {
            dispose();
            new subscription_listele_ad().setVisible(true);
        });

        issn_gore_listele.addActionListener(e -> {
            dispose();
            new subscription_listele_issn().setVisible(true);
        });
        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
}
