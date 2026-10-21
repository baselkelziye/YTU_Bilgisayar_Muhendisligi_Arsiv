package gui;

import backend.Distributor;
import backend.Journal;
import backend.Subscription;

import javax.swing.*;
import java.util.ArrayList;

public class payment_gui extends JFrame {

    private Distributor distributor = new Distributor();

    public payment_gui() {
        super("Odeme Ekrani");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        distributor.loadState("db.bin");

        JPanel panel = new JPanel();

        JLabel subscriberNameLabel = new JLabel("Subscriber Name:");
        JTextField subscriberName = new JTextField(10);
        JLabel journalIssnLabel = new JLabel("Journal ISSN:");
        JTextField journalIssn = new JTextField(10);
        JLabel paymentAmountLabel = new JLabel("Payment Amount:");
        JTextField paymentAmount = new JTextField(10);

        addLabelAndInput(panel, subscriberNameLabel, subscriberName);
        addLabelAndInput(panel, journalIssnLabel, journalIssn);
        addLabelAndInput(panel, paymentAmountLabel, paymentAmount);

        JButton ode_btn = new JButton("Odeme Yap");
        JButton ana_menu_btn = new JButton("Ana Menu");

        panel.add(ode_btn);
        panel.add(ana_menu_btn);

        add(panel);

        ode_btn.addActionListener(e -> {
            String subscriberNameText = subscriberName.getText();
            String journalIssnText = journalIssn.getText();
            String paymentAmountText = paymentAmount.getText();

            if (subscriberNameText.equals("") || journalIssnText.equals("") || paymentAmountText.equals("")) {
                JOptionPane.showMessageDialog(null, "Tum alanlari doldurunuz.");
            } else {
                if (distributor.searchSubscriber(subscriberNameText) == null) {
                    JOptionPane.showMessageDialog(null, "Eslesen abone bulunamadi.");
                } else if (distributor.searchJournal(journalIssnText) == null) {
                    JOptionPane.showMessageDialog(null, "Bu issnye sahip journal bulunamadi.");
                } else {

                    Journal journal = distributor.searchJournal(journalIssnText);
                    ArrayList<Subscription> subscriptions = journal.getSubscriptions();
                    for (Subscription subscription : subscriptions) {
                        if (subscription.getSubscriber().getName().equals(subscriberNameText)) {

                            subscription.acceptPayment(Double.parseDouble(paymentAmountText));
                            distributor.saveState("db.bin");
                            JOptionPane.showMessageDialog(null, "Odeme basarili.");
                            break;
                        }
                    }
                }
            }
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
