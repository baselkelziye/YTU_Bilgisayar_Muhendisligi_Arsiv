package backend;

import java.io.File;
import java.io.Serial;
import java.io.Serializable;
import java.util.Hashtable;
import java.util.Vector;

public class Distributor implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private Hashtable<String, Journal> journals;
    private Vector<Subscriber> subscribers;

    public Distributor() {

    }

    public Distributor(Hashtable<String, Journal> journals, Vector<Subscriber> subscribers) {
        this.journals = journals;
        this.subscribers = subscribers;
    }

    public boolean addJournal(Journal journal) {
        if (journals == null) {
            journals = new Hashtable<>();
        }

        if (journal != null && !journals.containsKey(journal.getIssn())) {
            journals.put(journal.getIssn(), journal);
            return true;
        }


        return false;

    }

    public Journal searchJournal(String issn) {
        if (journals != null && journals.containsKey(issn)) {
            return journals.get(issn);
        }


        return null;

    }

    public boolean addSubscriber(Subscriber subscriber) {
        if (subscribers == null) {
            subscribers = new Vector<>();
        }

        if (subscriber != null && !subscribers.contains(subscriber)) {
            subscribers.add(subscriber);
            return true;
        }
        return false;

    }

    public Subscriber searchSubscriber(String name) {
        if (subscribers != null) {
            for (Subscriber subscriber : subscribers) {
                if (subscriber.getName().equals(name)) {
                    return subscriber;
                }
            }
        }
        return null;
    }

    public boolean addSubscription(String issn, Subscriber subscriber, Subscription subscription) {

        if (journals != null && journals.containsKey(issn)) {
            Journal journal = journals.get(issn);

            if (journal.getSubscriptions().contains(subscription)) {
                subscription.setCopies(subscription.getCopies() + 1);
            } else {
                journal.addSubscription(subscription);
            }

            return true;
        }

        return false;

    }

    public String listAllSendingOrders(int month, int year) {

        String info = month + "/" + year + "\n------------------------------------------\n";

        if (journals != null) {
            for (Journal journal : journals.values()) {
                for (Subscription subscription : journal.getSubscriptions()) {
                    if (subscription.canSend(month, year)) {
                        info += ("Ad :" + subscription.getSubscriber().getName() + "\nJournal issn:" + subscription.getJournal().getIssn() +
                                "\nAdet:" + subscription.getCopies() +
                                "\n------------------------------------------\n");
                    }
                }
            }
        }
        return info;

    }

    public String listSendingOrders(String issn, int month, int year) {
        String info = "ISSN: " + issn + " Tarih:" + month + "/" + year + "\n------------------------------------------\n ";
        if (journals != null && journals.containsKey(issn)) {
            Journal journal = journals.get(issn);
            for (Subscription subscription : journal.getSubscriptions()) {
                if (subscription.canSend(month, year)) {
                    info += ("Ad :" + subscription.getSubscriber().getName() + "\nJournal issn:" + subscription.getJournal().getIssn() +
                            "\nAdet:" + subscription.getCopies() +
                            "\n------------------------------------------\n");
                }
            }
        }

        return info;
    }

    public String listIncompletePayments() {
        String info = "";
        if (journals != null) {
            for (Journal journal : journals.values()) {
                for (Subscription subscription : journal.getSubscriptions()) {
                    if (subscription.getPayment().getReceivedPayment() < (journal.getIssuePrice() * (1.0 - subscription.getPayment().getDiscountRatio()) * subscription.getCopies())) {
                        info += ("Ad: " + subscription.getSubscriber().getName() +
                                "\nJournal issn:" + journal.getIssn() +
                                "\nToplam odenen:" +
                                subscription.getPayment().getReceivedPayment() + "\nToplam odenmesi gereken:" + (journal.getIssuePrice() * (1.0 - subscription.getPayment().getDiscountRatio()) * subscription.getCopies()) + "\n------------------------------------------\n");
                    }
                }
            }
        }
        return info;

    }

    //umlde iki aynı adda aynı parametreyi alan metot var, öyle olmayacağı için farklı adlar verdim
    public void listSubscriptionsbyName(String subscriptionName) {
        if (journals != null) {
            for (Journal journal : journals.values()) {
                for (Subscription subscription : journal.getSubscriptions()) {
                    if (subscription.getSubscriber().getName().equals(subscriptionName)) {
                        System.out.println(subscription.getJournal().getName() + " " + subscription.getJournal().getIssn());
                    }
                }
            }
        }

    }

    public void listSubscriptionsbyIssn(String issn) {
        if (journals != null && journals.containsKey(issn)) {
            Journal journal = journals.get(issn);
            for (Subscription subscription : journal.getSubscriptions()) {
                System.out.println(subscription.getSubscriber().getName() + " " + subscription.getSubscriber().getAddress());
            }
        }
    }

    public void saveState(String fileName) {

        File file = new File(fileName);

        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }


        try {
            java.io.FileOutputStream fileOut = new java.io.FileOutputStream(file);
            java.io.ObjectOutputStream out = new java.io.ObjectOutputStream(fileOut);
            out.writeObject(this);
            out.close();
            fileOut.close();
        } catch (Exception e) {

        }

    }

    public void loadState(String fileName) {

        File file = new File(fileName);
        if (!file.exists()) {
            return;
        }

        try {
            java.io.FileInputStream fileIn = new java.io.FileInputStream(fileName);
            java.io.ObjectInputStream in = new java.io.ObjectInputStream(fileIn);
            Distributor distributor = (Distributor) in.readObject();
            this.journals = distributor.getJournals();
            this.subscribers = distributor.getSubscribers();
            in.close();
            fileIn.close();
        } catch (Exception e) {


        }

    }

    public void report() {

        // bu fonksiyonun implementasyonu gui tarafında yapıldı

    }


    public Hashtable<String, Journal> getJournals() {
        return journals;
    }

    public void setJournals(Hashtable<String, Journal> journals) {
        this.journals = journals;
    }

    public Vector<Subscriber> getSubscribers() {
        return subscribers;
    }

    public void setSubscribers(Vector<Subscriber> subscribers) {
        this.subscribers = subscribers;
    }
}
