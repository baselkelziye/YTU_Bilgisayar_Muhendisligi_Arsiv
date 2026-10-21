package gui;

import backend.Distributor;
import backend.Journal;
import backend.Subscription;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.HashSet;

public class odemeleri_goster_gui extends JFrame{
    private Distributor distributor ;

    public odemeleri_goster_gui() {
        super("Odemeleri Goster");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        getContentPane().setBackground(Color.LIGHT_GRAY);

        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));
        panel.setBackground(Color.LIGHT_GRAY);

        JLabel baslangicYili = new JLabel("Baslangic Yili: ");
        JTextField baslangicTextField = new JTextField(15);

        JLabel bitisYili = new JLabel("Bitis Yili:");
        JTextField bitisTextField = new JTextField(15);

        JButton ara_btn = new JButton("Ara");

        addLabelAndInput(panel, baslangicYili, baslangicTextField);
        addLabelAndInput(panel, bitisYili, bitisTextField);

        panel.add(ara_btn);

        add(panel);

        ara_btn.setBackground(Color.BLUE);


        ara_btn.setForeground(Color.WHITE);


        Font font = new Font("Arial", Font.PLAIN, 14);
        baslangicYili.setFont(font);
        baslangicTextField.setFont(font);

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

                int inputBaslangicYili = Integer.parseInt(baslangicTextField.getText());
                int inputBitisYili = Integer.parseInt(bitisTextField.getText());

                int subscriptionStartYear = subscription.getDates().getStartYear();

                if (inputBaslangicYili <= subscriptionStartYear && inputBitisYili >= subscriptionStartYear) {
                    filteredSubscriptions.add(subscription);
                }

            }

            for (Subscription subscription : filteredSubscriptions) {
                info +=   "Ad: "+subscription.getSubscriber().getName()+"\n"+
                        "Journal: "+subscription.getJournal().getName()+"\n"+
                        "Tarih: "+subscription.getDates().getStartMonth()+"/"+subscription.getDates().getStartYear()+"\n"+
                        "Odeme: "+subscription.getPayment().getReceivedPayment()+"\n---------------------------------------------------"+"\n";
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
