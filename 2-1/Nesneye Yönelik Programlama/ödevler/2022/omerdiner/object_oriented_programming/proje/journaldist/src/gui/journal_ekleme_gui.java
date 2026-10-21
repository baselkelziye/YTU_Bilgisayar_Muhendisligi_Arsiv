package gui;

import backend.Distributor;
import backend.Journal;

import javax.swing.*;
import java.awt.*;

public class journal_ekleme_gui extends JFrame {
    private  Distributor distributor = new Distributor();
    public journal_ekleme_gui() {
        super("Journal Ekle");

        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        distributor.loadState("db.bin");

        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));

        JLabel nameLabel = new JLabel("Name:");
        JLabel issnLabel = new JLabel("ISSN:");
        JLabel frequencyLabel = new JLabel("Frequency:");
        JLabel issuePriceLabel = new JLabel("Issue Price:");


        JTextField name = new JTextField(10);
        JTextField issn = new JTextField(10);
        JTextField frequency = new JTextField(10);
        JTextField issuePrice = new JTextField(10);

        JButton olustur_btn = new JButton("Create");
        JButton ana_menu_btn = new JButton("Main Menu");

        addLabelAndInput(panel, nameLabel, name);
        addLabelAndInput(panel, issnLabel, issn);
        addLabelAndInput(panel, frequencyLabel, frequency);
        addLabelAndInput(panel, issuePriceLabel, issuePrice);


        panel.add(olustur_btn);
        panel.add(ana_menu_btn);

        add(panel);

        olustur_btn.addActionListener(e -> {
            dispose();
            Journal journal = new Journal(name.getText(), issn.getText(), Integer.parseInt(frequency.getText()), Double.parseDouble(issuePrice.getText()));
            distributor.addJournal(journal);
            distributor.saveState("db.bin");
            JOptionPane.showMessageDialog(null, "Journal ekleme basarili.");

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

