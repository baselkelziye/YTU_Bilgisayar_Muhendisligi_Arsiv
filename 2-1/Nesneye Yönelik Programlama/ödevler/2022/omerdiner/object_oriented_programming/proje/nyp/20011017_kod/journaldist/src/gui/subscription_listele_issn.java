package gui;

import backend.Distributor;
import backend.Journal;
import backend.Subscription;

import javax.swing.*;
import java.util.ArrayList;
import java.util.Hashtable;

public class subscription_listele_issn extends JFrame {
    private Distributor distributor = new Distributor();
    public subscription_listele_issn() {

        super("Subscription Listele(issn gore)");
        distributor.loadState("db.bin");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(500, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        String issn = JOptionPane.showInputDialog("issn: ");
        Journal journal = distributor.searchJournal(issn);

        if(journal == null){
            JOptionPane.showMessageDialog(null, "Verilen issn'e sahip journal bulunamadı:  " + issn);
            return;
        }
        ArrayList<Subscription> subscriptions = journal.getSubscriptions();

        JPanel panel = new JPanel();
        int i=1;
        for (Subscription subscription : subscriptions) {
            JLabel info = new JLabel(i + ". uyelik"  );
            JLabel uye= new JLabel("Abone:"+subscription.getSubscriber().getName());
            JLabel adres=new JLabel("Adres:"+subscription.getSubscriber().getAddress());
            JLabel journaladi=new JLabel("Journal:"+subscription.getJournal().getName());
            JLabel tarih=new JLabel("Baslangic ayi:"+subscription.getDates().getStartMonth()+" Baslangic yili:"+subscription.getDates().getStartYear()+"  Bitis ayi:"+subscription.getDates().getEndMonth());

            i++;
            panel.add(info);
            panel.add(uye);
            panel.add(adres);
            panel.add(journaladi);
            panel.add(tarih);


            add(panel);


        }

        JButton ana_menu_btn = new JButton("Ana Menu");
        add(ana_menu_btn);
        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });


    }
}
