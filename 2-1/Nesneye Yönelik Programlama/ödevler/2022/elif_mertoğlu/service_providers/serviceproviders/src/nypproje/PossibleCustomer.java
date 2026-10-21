package nypProje;

public class PossibleCustomer extends Customer {
	
private Subscription subscription;
	
	public PossibleCustomer(String CitizenshipNr) {
		super(CitizenshipNr);
	}
	
	public PossibleCustomer(String CitizenshipNr, Subscription subscription) {
		super(CitizenshipNr);
		this.subscription=subscription;
	}
	
	public Subscription getSubscription() {
		return subscription;
	}
	
	public void setsubscription(Subscription subscription) {
		this.subscription=subscription;
	}
	
}
