package kemalselcuk;

public class ExistingCustomer extends Customer{
	private Subscription subscription; //attributes

	public ExistingCustomer(String citizenshipNr) {	//constructor
		super(citizenshipNr);
	}
	public ExistingCustomer(String citizenshipNr,Subscription sub) {	//constructor
		super(citizenshipNr);
		this.subscription = sub;
	}
	public Subscription getSubscription() {
		return subscription;
	}
	public void setSubscription(Subscription subscription) {
		this.subscription = subscription;
	}
	
	
	
}
