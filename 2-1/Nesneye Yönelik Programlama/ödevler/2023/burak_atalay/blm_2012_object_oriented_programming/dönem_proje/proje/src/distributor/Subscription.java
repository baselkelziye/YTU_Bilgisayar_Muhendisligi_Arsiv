package distributor;

import subscriber.Corporation;
import subscriber.Individual;
import subscriber.Subscriber;

public class Subscription implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private final DateInfo dates;
    private PaymentInfo payment;
    private final Journal journal;
    private final Subscriber subscriber;
    private int copies;

    public Subscription(int startMonth, int startYear, Journal journal, Subscriber subscriber, int copies){
        this.journal = journal;
        this.subscriber = subscriber;
        this.payment = new PaymentInfo(journal.getDiscountRatio());
        this.dates = new DateInfo(startMonth, startYear);
        this.copies = copies;
    }

    public boolean canSend(int issueMonth){
        double amount = journal.getIssuePrice() * (1 - journal.getDiscountRatio()) * copies;
        if(subscriber.canSend(issueMonth, amount)){
            acceptPayment(amount);
            return true;
        }
        return false;
    }

    public void acceptPayment(double amount){
        payment.increaseReceivedPayment(amount);
    }

    public DateInfo getDates() {
        return dates;
    }

    public PaymentInfo getPayments() {
        return payment;
    }

    public Journal getJournal() {
        return journal;
    }

    public Subscriber getSubscriber() {
        return subscriber;
    }

    public int getCopies() {
        return copies;
    }

    public void setCopies(int amount) {
        copies = amount;
    }

    @Override
    public String toString() {
        return "Subscription{" +
                "dates=" + dates +
                ", payment=" + payment +
                ", journal=" + journal +
                ", subscriber=" + subscriber +
                ", copies=" + copies +
                '}';
    }

    public boolean equals(Subscription subscription){
        if(this == subscription) return true;
        if(this.journal.getIssn().compareTo(subscription.journal.getIssn()) != 0) return false;
        if(this.subscriber.getId() != subscription.subscriber.getId()) return false;
        if(this.dates.getStartYear() != subscription.dates.getStartYear()) return false;
        if(this.dates.getStartMonth() != subscription.dates.getStartMonth()) return false;
        return true;
    }
}
