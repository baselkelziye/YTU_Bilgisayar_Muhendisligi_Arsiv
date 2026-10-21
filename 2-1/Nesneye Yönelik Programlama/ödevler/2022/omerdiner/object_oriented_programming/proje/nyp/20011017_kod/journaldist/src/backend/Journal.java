package backend;

import java.io.Serial;
import java.io.Serializable;
import java.util.ArrayList;

public class Journal implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private String name;
    private String issn;
    private int frequency;
    private double issuePrice;
    private ArrayList<Subscription> subscriptions=new ArrayList<>();



    public Journal(String name, String issn, int frequency, double issuePrice) {
        this.name = name;
        this.issn = issn;
        this.frequency = frequency;
        this.issuePrice = issuePrice;
    }
    public void addSubscription(Subscription s){


        subscriptions.add(s);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getIssn() {
        return issn;
    }

    public void setIssn(String issn) {
        this.issn = issn;
    }

    public int getFrequency() {
        return frequency;
    }

    public void setFrequency(int frequency) {
        this.frequency = frequency;
    }

    public double getIssuePrice() {
        return issuePrice;
    }

    public void setIssuePrice(double issuePrice) {
        this.issuePrice = issuePrice;
    }

    public ArrayList<Subscription> getSubscriptions() {
        return subscriptions;
    }

    public void setSubscriptions(ArrayList<Subscription> subscriptions) {
        this.subscriptions = subscriptions;
    }

    @Override
    public String toString() {
        return "Journal{" +
                "name='" + name + '\'' +
                ", issn='" + issn + '\'' +
                ", frequency=" + frequency +
                ", issuePrice=" + issuePrice +
                '}';
    }
}
