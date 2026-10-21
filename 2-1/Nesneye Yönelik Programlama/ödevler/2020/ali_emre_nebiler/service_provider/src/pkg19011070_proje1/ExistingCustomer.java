
package pkg19011070_proje1;

public class ExistingCustomer extends Customer {

    private Subscription subscription;
    
    public ExistingCustomer(String CitizenshipNr, String name) {
       super(CitizenshipNr, name); // got the info from customer
    }
    
    public ExistingCustomer(String CitizenshipNr, String name,
            Subscription subscription) {
       super(CitizenshipNr, name); // got the info from customer
       this.subscription = subscription;
    }
    
    public Subscription getSubscription() {
        return subscription;
    }

    public void setSubscription(Subscription subscription) {
        this.subscription = subscription;
    }
}
