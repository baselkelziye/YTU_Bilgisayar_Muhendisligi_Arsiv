package ahmetsefacetin;

import java.io.Serializable;
import java.time.LocalDate;

public class Subscription implements Serializable {

    private static final long serialVersionUID = 1L;
    private final DateInfo dates;
    private PaymentInfo payment;
    private int copies;
    private final Journal journal;
    private final Subscriber subscriber;

    public Subscription(Journal journal, Subscriber subscriber, PaymentInfo payment) {
        LocalDate currentDate = LocalDate.now();

        int startYear = currentDate.getYear();
        int startMonth = currentDate.getMonthValue();

        int endMonth = startMonth - 1;
        if (startMonth == 1) {
            endMonth = 12;
        }

        int endYear = startYear + 1;
        if (startMonth == 1) {
            endYear = startYear;
        }

        this.dates = new DateInfo(startMonth, endMonth, startYear, endYear);

        this.copies = 1;
        this.payment = payment;
        this.journal = journal;
        this.subscriber = subscriber;
    }

    public PaymentInfo getPayment() {
        return payment;
    }

    public void setPayment(PaymentInfo payment) {
        this.payment = payment;
    }

    public int getCopies() {
        return copies;
    }

    public void setCopies(int copies) {
        this.copies = copies;
    }

    public DateInfo getDates() {
        return dates;
    }

    public Journal getJournal() {
        return journal;
    }

    public Subscriber getSubscriber() {
        return subscriber;
    }

    public void acceptPayment(double amount) {
        payment.increasePayment(amount);
        subscriber.setBalance(subscriber.getBalance() - amount);
    }

    public boolean canSend() {
        double amount = journal.getIssuePrice() * (1 - payment.getDiscountRatio()) * copies;
        return subscriber.getBalance() >= amount;
    }

    @Override
    public String toString() {
        return "Subscription{" + dates + "," + payment + ", copies=" + copies + ", journal ISSN=" + journal.getIssn() + ", subscriber ID=" + subscriber.getId() + '}';
    }

}
