package proje;

import java.io.Serializable;

public class Subscription implements Serializable {
	private static final long serialVersionUID = -4798860936575756872L;
	private final DateInfo dates;
	private final PaymentInfo payment;
	private int copies;
	private Journal journal;
	private Subscriber subscriber;
	
	public Subscription(DateInfo dates, int copies, Journal journal, Subscriber subscriber) {
		this.dates = dates;
		this.copies = copies;
		this.journal = journal;
		this.subscriber = subscriber;
		this.payment=setPayment();
	}
	
	private PaymentInfo setPayment() {           // for corparation discountRatio is 15, other 10
		if(subscriber instanceof Corparation)
			return new PaymentInfo(15);
		else
			return new PaymentInfo(10);
	}
	
	public int getCopies() {
		return copies;
	}
	
	public PaymentInfo getPayment() {
		return this.payment;
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
	
	public DateInfo getDates() {
		return dates;
	}

	@Override
	public String toString() {
		String result="Dergi: "+journal.getName()+", Abone: "+subscriber.getName();
		return result;
	}

	public void acceptPayment(double amount) {
		payment.increasePayment(amount);
	}
	
	public boolean canSend(int issueMonth) {
		double totalPriceToPay;
		double priceToPayPerMonth=journal.getIssuePrice()*copies*(100-payment.getDiscountRatio())/100;
		
		if(dates.getStartMonth()<=issueMonth) {
			totalPriceToPay=priceToPayPerMonth*(issueMonth-dates.getStartMonth()+1);
		}
		else {
			totalPriceToPay=priceToPayPerMonth*(12-(dates.getStartMonth()-issueMonth)+1);
		}
		
		if(payment.getReceivedPayment()>=totalPriceToPay)
			return true;
		else
			return false;
	}
}
