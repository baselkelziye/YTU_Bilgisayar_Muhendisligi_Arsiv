package distributor;

import jdk.jshell.JShell;

import java.util.ArrayList;

public class Journal implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private String name, issn;
    private double issuePrice;
    private double discountRatio;
    private int frequency;
    private ArrayList<Subscription> subscriptions;

    public Journal(String name, String issn, double issuePrice, double discountRatio,
                   int frequency) {
        this.name = name;
        this.issn = issn;
        this.issuePrice = issuePrice;
        this.discountRatio = discountRatio;
        this.frequency = frequency;
        subscriptions = new ArrayList<>();
    }

    public void addSubscription(Subscription subscription){
        for(Subscription s: subscriptions){
            if(s.equals(subscription)){
                s.setCopies(s.getCopies() + subscription.getCopies());
                return;
            }
        }
        subscriptions.add(subscription);
    }

    public String getName() {
        return name;
    }

    public String getIssn() {
        return issn;
    }

    public double getIssuePrice() {
        return issuePrice;
    }

    public double getDiscountRatio() {
        return discountRatio;
    }

    public int getFrequency() {
        return frequency;
    }

    public ArrayList<Subscription> getSubscriptions() {
        return subscriptions;
    }

    @Override
    public String toString() {
        return "Journal{" +
                "name='" + name + '\'' +
                ", issn='" + issn + '\'' +
                ", issuePrice=" + issuePrice +
                ", discountRatio=" + discountRatio +
                ", frequency=" + frequency +
                '}';
    }
}
