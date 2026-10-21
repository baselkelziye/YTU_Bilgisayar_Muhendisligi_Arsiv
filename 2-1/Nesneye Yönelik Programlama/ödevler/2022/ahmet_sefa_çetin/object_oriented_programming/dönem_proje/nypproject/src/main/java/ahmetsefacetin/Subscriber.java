package ahmetsefacetin;

import java.io.Serializable;

public abstract class Subscriber implements Serializable {

    private static final long serialVersionUID = 1L;
    private static int counter = 1;
    private int id;
    private int subscriberNumber;
    private String name;
    private String adress;
    private double balance;

    public Subscriber(int id, String name, String adress, double balance) {
        this.id = id;
        this.name = name;
        this.adress = adress;
        subscriberNumber = counter;
        counter++;
        this.balance = balance;
    }

    public int getId() {
        return id;
    }

    public int getSubscriberNumber() {
        return subscriberNumber;
    }

    public static int getCounter() {
        return counter;
    }

    public static void setCounter(int counter) {
        Subscriber.counter = counter;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public abstract String getBillingInformation();

    @Override
    public String toString() {
        return "Subscriber{" + "id=" + id + ", subscriberNumber=" + subscriberNumber + ", name=" + name + ", adress=" + adress + ", balance=" + balance + '}';
    }

}
