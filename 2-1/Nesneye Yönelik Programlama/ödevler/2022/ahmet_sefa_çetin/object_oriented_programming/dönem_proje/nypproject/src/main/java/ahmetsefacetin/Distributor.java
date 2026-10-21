package ahmetsefacetin;

import GUI.ReportPanel;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Hashtable;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Distributor implements Serializable, Runnable {

    private final long serialVersionUID = 1L;
    private Hashtable<String, Journal> journals = new Hashtable<String, Journal>();
    private Vector<Subscriber> subscribers = new Vector<Subscriber>();
    private String incompletePayments = "";
    private String annualPayments = "";

    public Distributor() {

    }

    public Hashtable<String, Journal> getJournals() {
        return journals;
    }

    public Vector<Subscriber> getSubscribers() {
        return subscribers;
    }

    public String getAnnualPayments() {
        return annualPayments;
    }

    public void listSubscribers() {
        String list = "";
        System.out.println("Subscriber List");
        for (Subscriber subscriber : subscribers) {
            System.out.println(subscriber);
            list += subscriber + "\n";
        }
        System.out.println("");
        JOptionPane.showMessageDialog(null, list, "Subscriber List", JOptionPane.INFORMATION_MESSAGE);
    }

    public void listJournals() {
        String list = "";
        System.out.println("Journal List");
        for (String issn : journals.keySet()) {
            System.out.println(journals.get(issn));
            list += journals.get(issn) + "\n";
        }
        System.out.println("");
        JOptionPane.showMessageDialog(null, list, "Journal List", JOptionPane.INFORMATION_MESSAGE);
    }

    public boolean addJournal(Journal journal) {
        if (searchJournal(journal.getIssn()) != null) {
            System.out.println("There is a journal with the same ISSN!");
            return false;
        }

        journals.put(journal.getIssn(), journal);
        return true;
    }

    public Journal searchJournal(String issn) {
        return journals.get(issn);
    }

    public boolean addSubscriber(Subscriber subscriber) {
        if (searchSubscriber(subscriber.getId()) != null) {
            System.out.println("There is a subscriber with the same ID!");
            return false;
        }

        subscribers.add(subscriber);
        return true;
    }

    public Subscriber searchSubscriber(int id) {
        for (Subscriber subscriber : subscribers) {
            if (id == subscriber.getId()) {
                return subscriber;
            }
        }
        return null;
    }

    public boolean addSubscription(String issn, int subscriberId, PaymentInfo payment) {
        Journal journal = searchJournal(issn);
        if (journal == null) {
            System.out.println("Journal doesn't exist.");
            return false;
        }
        Subscriber subscriber = searchSubscriber(subscriberId);
        if (subscriber == null) {
            System.out.println("Subscriber doesn't exist.");
            return false;
        }

        for (Subscription subscription : journal.getSubscriptions()) {
            if (subscription.getJournal() == journal && subscription.getSubscriber() == subscriber) {
                subscription.setCopies(subscription.getCopies() + 1);
                System.out.println("Copies field of subscription increased to " + subscription.getCopies());
                System.out.println(subscription);
                JOptionPane.showMessageDialog(null, subscription, "Copies field of subscription increased to " + subscription.getCopies(), JOptionPane.INFORMATION_MESSAGE);
                return true;
            }
        }

        Subscription newSubscription = new Subscription(journal, subscriber, payment);
        journals.get(issn).addSubscription(newSubscription);
        System.out.println("Created New Subscription");
        System.out.println(newSubscription);
        JOptionPane.showMessageDialog(null, newSubscription, "Created New Subscription.", JOptionPane.INFORMATION_MESSAGE);
        return true;
    }

    public void listAllSendingOrders(int month, int year) {
        String list = "";
        System.out.println("All Sending Orders: ");
        for (String issn : journals.keySet()) {
            list += listSendingOrders(issn, month, year);
        }
        JOptionPane.showMessageDialog(null, list, "All Sending Orders: ", JOptionPane.INFORMATION_MESSAGE);
        saveState("distributorData.ser");
    }

    public String listSendingOrders(String issn, int month, int year) {
        Journal journal = searchJournal(issn);
        if (journal == null) {
            System.out.println("There is no Journal with this ISSN!");
            JOptionPane.showMessageDialog(null, "There is no Journal with this ISSN!", "Try again", JOptionPane.ERROR_MESSAGE);
            return "";
        }

        String list = "";
        System.out.println("Sending Orders for Journal with ISSN: " + issn);
        if (month % (12 / journal.getFrequency()) == 1) {
            for (Subscription subscription : journal.getSubscriptions()) {
                if ((year == subscription.getDates().getStartYear() && month >= subscription.getDates().getStartMonth())
                        || (year == (subscription.getDates().getEndYear()) && month <= subscription.getDates().getEndMonth())) {
                    if (subscription.canSend()) {
                        double amount = journal.getIssuePrice() * (1 - subscription.getPayment().getDiscountRatio()) * subscription.getCopies();
                        subscription.acceptPayment(amount);
                        System.out.println("(month: " + month + ", year: " + year + ")" + subscription);
                        list += "(month: " + month + ", year: " + year + ")" + subscription + "\n";
                        annualPayments += subscription + "\n";
                    } else {
                        incompletePayments += "(month: " + month + ", year: " + year + ")" + subscription + "\n";
                    }
                }
            }
        }
        System.out.println("");
        saveState("distributorData.ser");
        return list;
    }

    public void listIncompletePayments() {
        System.out.println("Incomplete Payments");
        System.out.println(incompletePayments);
        JOptionPane.showMessageDialog(null, incompletePayments, "Incomplete Payments", JOptionPane.INFORMATION_MESSAGE);
    }

    public void listSubcriptionsBySubscriber(int subscriberId) {
        Subscriber subscriber = searchSubscriber(subscriberId);
        if (subscriber == null) {
            System.out.println("There is no subscriber with this ID!");
            JOptionPane.showMessageDialog(null, "There is no subscriber with this ID!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String list = "";
        System.out.println("Subscribtion List By Subscriber with the ID: " + subscriberId);
        for (String issn : journals.keySet()) {
            for (Subscription subscription : journals.get(issn).getSubscriptions()) {
                if (subscription.getSubscriber().getId() == subscriberId) {
                    System.out.println(subscription);
                    list += subscription + "\n";
                }
            }
        }
        System.out.println("");
        JOptionPane.showMessageDialog(null, list, "Subscribtion List By Subscriber with the ID: " + subscriberId, JOptionPane.INFORMATION_MESSAGE);
    }

    public void listSubcriptionsByJournal(String issn) {
        Journal journal = searchJournal(issn);
        if (journal == null) {
            System.out.println("There is no Journal with this ISSN!");
            JOptionPane.showMessageDialog(null, "There is no Journal with this ISSN!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String list = "";
        System.out.println("Subscribtion List By Journal with the ISSN: " + issn);
        for (Subscription subscription : journal.getSubscriptions()) {
            System.out.println(subscription);
            list += subscription + "\n";
        }
        System.out.println("");
        JOptionPane.showMessageDialog(null, list, "Subscribtion List By Journal with the ISSN: " + issn, JOptionPane.INFORMATION_MESSAGE);
    }

    public void saveState(String fileName) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(journals);
            oos.writeObject(subscribers);
            oos.writeObject(incompletePayments);
            oos.writeObject(annualPayments);
            System.out.println("Distributor class successfully saved to file: " + fileName);
        } catch (IOException e) {
            System.err.println("Error saving to file: " + e.getMessage());
        }
    }

    public void loadState(String fileName) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            journals = (Hashtable<String, Journal>) ois.readObject();
            subscribers = (Vector<Subscriber>) ois.readObject();
            incompletePayments = (String) ois.readObject();
            annualPayments = (String) ois.readObject();
            System.out.println("Distributor class successfully loaded from file: " + fileName);
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error loading from file: " + e.getMessage());
        }
    }

    public void report() {
        ReportPanel reportPanel = new ReportPanel();
        reportPanel.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        reportPanel.setVisible(true);
        reportPanel.pack();
        reportPanel.setLocationRelativeTo(null);
    }

    @Override
    public void run() {
        report();
    }

}
