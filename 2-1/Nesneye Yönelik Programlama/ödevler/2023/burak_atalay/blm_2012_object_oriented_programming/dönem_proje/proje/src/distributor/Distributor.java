package distributor;

import subscriber.Subscriber;

import java.io.*;
import java.util.*;
import javax.swing.*;


public class Distributor implements Runnable{
    private Hashtable<String, Journal> journals;
    private Vector<Subscriber> subscribers;
    private String incomplete; 
    
    public Distributor() {
        journals = new Hashtable<>();
        subscribers = new Vector<>();
        incomplete = "";
    }

    public Hashtable<String, Journal> getJournals() {
        return journals;
    }

    public Vector<Subscriber> getSubscribers() {
        return subscribers;
    }

    public boolean addJournal(Journal journal){
        if(searchJournal(journal.getIssn()) == null){
            journals.put(journal.getIssn(), journal);
            return true;
        }
        return false;
    }

    public Journal searchJournal(String issn){
        return journals.get(issn);
    }

    public boolean addSubscriber(Subscriber subscriber){
        if(searchSubscriber(subscriber.getId()) == null){
            subscribers.add(subscriber);
            return true;
        }
        return false;
    }

    public Subscriber searchSubscriber(int id){
        for(Subscriber s: subscribers){
            if(s.getId() == id) return s;
        }
        return null;
    }

    public boolean addSubscription(String issn, int id, int startMonth, int startYear, int copies){
        Journal journal = searchJournal(issn);
        Subscriber subscriber = searchSubscriber(id);
        if(journal == null || subscriber == null) return false;
        Subscription subscription = new Subscription(startMonth, startYear, journal, subscriber, copies);
        journal.addSubscription(subscription);
        subscriber.addSubscription(subscription);
        return true;
    }

    public void listAllSendingOrders(int month, int year){
        System.out.println("All sending orders...");
        Collection<Journal> journalArray = journals.values();
        for(Journal journal: journalArray){
            listSendingOrders(journal.getIssn(), month, year);
        }
    }

    public void listSendingOrders(String issn, int month, int year){
        String result = "";
        Journal journal = journals.get(issn);
        if(journal == null || ((month - 1) % (12 / journal.getFrequency())) != 0) return;
        for(Subscription s: journal.getSubscriptions()){
            if(s.getDates().betweenDate(month, year)){
                if(s.canSend(month)){
                    System.out.println(s);
                    result += s + "\n";
                }
                else incomplete += s + "\n";
            }
        }
        
        JTextArea textArea = new JTextArea(result);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        JOptionPane.showMessageDialog(null, scrollPane, "List Sending Orders for Journal with ISSN: " + issn
            + " for month: " + month + " year: " + year, JOptionPane.INFORMATION_MESSAGE);
    }

    public void listIncompletePayments(){
        System.out.println("Incomplete payments...");
        System.out.println(incomplete);
        JTextArea textArea = new JTextArea(incomplete);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        JOptionPane.showMessageDialog(null, scrollPane, "Incomplete Payments", JOptionPane.INFORMATION_MESSAGE);
    }

    public String listSubscriptionsOfSubscriber(int id){
        String result = "";
        Subscriber subscriber = searchSubscriber(id);
        if(subscriber == null) return null;
        System.out.println(subscriber);
        for(Subscription s: subscriber.getSubscriptions()){
            System.out.println(s);
            result += s + "\n";
        }
        return result;
    }

    public String listSubscriptionsOfJournal(String issn){
        String result = "";
        Journal journal = searchJournal(issn);
        if(journal == null) return null;
        System.out.println(journal);
        for(Subscription s: journal.getSubscriptions()) {
            System.out.println(s);
            result += s + "\n";
        }
        return result;
    }

    public void saveState(String fileName){
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName));
            oos.writeObject(journals);
            oos.writeObject(subscribers);
            oos.writeObject(incomplete);
            oos.close();
        } catch (IOException e) {
            System.out.println("An exception has occured during file reading.");
        }
    }
    
    @SuppressWarnings("unchecked")
    public void loadState(String fileName){
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName));
            journals = (Hashtable<String, Journal>) ois.readObject();
            subscribers = (Vector<Subscriber>) ois.readObject();
            incomplete = (String) ois.readObject();
            ois.close();
        }
        catch(IOException e) {
            System.out.println("An exception has occured during file reading.");
            e.printStackTrace();
        }
        catch(ClassNotFoundException e) {
            System.out.println("An exception has occured while processing read records.");
            e.printStackTrace();
        }
    }
    
    public void report(){
        SwingUtilities.invokeLater(() -> {
            String monthInput = JOptionPane.showInputDialog("Enter the month:");
            String yearInput = JOptionPane.showInputDialog("Enter the year:");
            int month = Integer.parseInt(monthInput);
            int year = Integer.parseInt(yearInput);

            String filename = "report.html";

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))){
                writer.write("<html>\n<head>\n<title>Expired Subscriptions</title>\n</head>\n<body>\n");
                writer.write("<h1>Expired Subscriptions on month: " + month + " year: " + year + "</h1>\n<ul>\n");
                Collection<Journal> journalArray = journals.values();
                for(Journal journal: journalArray){
                    ArrayList<Subscription> subscriptions = journal.getSubscriptions();
                    for(Subscription s: subscriptions){
                        if(!s.getDates().betweenDate(month, year)){
                            writer.write("<li>: " + s + "</li>\n");
                        }
                    }
                }
                writer.write("</ul>\n");
                writer.write("</body>\n</html>");
            }
            catch(IOException e){
                e.printStackTrace();
            }
        });
    }
    
    @Override
    public void run() {
        report();
    }
}
