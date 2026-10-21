package backend;

import backend.DateInfo;
import backend.Journal;
import backend.PaymentInfo;
import backend.Subscriber;

import java.io.Serial;
import java.io.Serializable;

public class Subscription implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private final DateInfo dates;
    private PaymentInfo payment;
    private int copies;
    private final Journal journal;
    private final Subscriber subscriber;

    public Subscription(DateInfo dates,  int copies, Journal journal, Subscriber subscriber) {
        this.dates = dates;
        this.copies = copies;
        this.journal = journal;
        this.subscriber = subscriber;
        this.payment = new PaymentInfo(0);
    }
    public void acceptPayment(double amount){
        payment.increasePayment(amount);
    }
    public boolean canSend(int issueMonth, int issueYear){


        if(payment.getReceivedPayment()>=(journal.getIssuePrice()*(1.0- getPayment().getDiscountRatio())*copies)){
            if(issueYear>=dates.getStartYear()&&issueYear<=dates.getStartYear()+1){

                if(issueYear==dates.getStartYear()&&issueMonth>=dates.getStartMonth()){
                    return true;
                }
                else if(issueYear==dates.getStartYear()+1&&issueMonth<=dates.getEndMonth()) {
                    return true;
                }
            }

        }

        return false;



    }
    public DateInfo getDates() {
        return dates;
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

    public Journal getJournal() {
        return journal;
    }

    public Subscriber getSubscriber() {
        return subscriber;
    }

    @Override
    public String toString() {
        return "Subscription Bilgileri: "+"\n"+
                "Tarihler: " +dates.getStartMonth()+"-"+dates.getEndMonth()+" aylari arasinda "+" baslangic yili:"+dates.getStartYear() +"\n"+
                "Odeme Bilgileri: " + payment +"\n"+
                "Kopya Sayisi: " + copies +"\n"+
                "Dergi Bilgileri: " + journal +"\n"+
                "Abone Bilgileri: " + subscriber +"\n";

    }
}
