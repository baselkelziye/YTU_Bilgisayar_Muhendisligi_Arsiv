package gui;

import backend.Distributor;
import backend.Journal;
import backend.Subscription;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.HashSet;

public class bitecek_abonelik_gui extends JFrame {
    private Distributor distributor ;

    public bitecek_abonelik_gui() {
        super("Bitecek Abonelikler");
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

        JButton ara_btn = new JButton("Ara");

        addLabelAndInput(panel, ayLabel, ayTextField);
        addLabelAndInput(panel, yilLabel, yilTextField);

        panel.add(ara_btn);

        add(panel);

        ara_btn.setBackground(Color.BLUE);


        ara_btn.setForeground(Color.WHITE);


        Font font = new Font("Arial", Font.PLAIN, 14);
        ayLabel.setFont(font);
        ayTextField.setFont(font);

        ara_btn.addActionListener(e -> {
            String info = "";
            dispose();
            distributor = new Distributor();
            distributor.loadState("db.bin");

            ArrayList<Journal> journals = new ArrayList<>(distributor.getJournals().values());
            ArrayList<Subscription> subscriptions = new ArrayList<>();

            for (Journal journal : journals) {
                subscriptions.addAll(journal.getSubscriptions());
            }

            HashSet<Subscription> filteredSubscriptions = new HashSet<>();

            for (Subscription subscription : subscriptions) {
                int subscriptionMonth = subscription.getDates().getStartMonth();
                int subscriptionYear = subscription.getDates().getStartYear();

                int inputMonth = Integer.parseInt(ayTextField.getText());
                int inputYear = Integer.parseInt(yilTextField.getText());

                if ( (inputYear*12 + inputMonth)-(subscriptionYear*12 + subscriptionMonth)  > 12) {
                    filteredSubscriptions.add(subscription);
                }



            }

            for (Subscription filteredSubscription : filteredSubscriptions) {
                info += filteredSubscription.getSubscriber().getName() +"\n"+filteredSubscription.getJournal().getName()+"\n"+"Abonelik Baslangic Tarihi:"+
                        filteredSubscription.getDates().getStartMonth()+"/"+filteredSubscription.getDates().getStartYear()+
                        "\n"+"---------------------------------------------------"+"\n";
            }


            JOptionPane.showMessageDialog(null, info);

            new report_gui().setVisible(true);
        });


    }

    public void addLabelAndInput(JPanel panel, JLabel label, JTextField input) {
        panel.add(label);
        panel.add(input);
    }
}
