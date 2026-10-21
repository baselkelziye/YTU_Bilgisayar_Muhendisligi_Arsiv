package subscriber;

import distributor.Subscription;

import java.util.ArrayList;

public abstract class Subscriber implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private String address;
    private String name;
    private int id;
    private ArrayList<Subscription> subscriptions;

    public Subscriber(int id, String address, String name) {
        this.address = address;
        this.name = name;
        this.id = id;
        subscriptions = new ArrayList<>();
    }

    public abstract String getBillingInformation();

    public int getId() {
        return id;
    }

    public String getAddress() {
        return address;
    }

    public String getName() {
        return name;
    }

    public ArrayList<Subscription> getSubscriptions() {
        return subscriptions;
    }

    public void addSubscription(Subscription subscription){
        for(Subscription s: subscriptions){
            if(s.equals(subscription)) return; //zaten journala eklerken copies'i artırıyoruz. burda gerek yok
        }
        subscriptions.add(subscription);
    }

    public abstract boolean canSend(int issueMonth, double amount);

    @Override
    public String toString() {
        return "Subscriber{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", address=" + address +
                " }";
    }
}
