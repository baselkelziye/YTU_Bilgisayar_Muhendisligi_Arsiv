package subscriber;

public class Individual extends Subscriber implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private CreditCard creditCard;

    public Individual(int id, String address, String name, String creditCardNr, int expireMonth,
                      int expireYear, int CCV, double balance) {
        super(id, address, name);
        this.creditCard = new CreditCard(creditCardNr, expireMonth, expireYear, CCV, balance);
    }

    @Override
    public String getBillingInformation() {
        return this.toString();
    }

    @Override
    public boolean canSend(int issueMonth, double amount) {
        if(this.getCreditCard().getBalance() >= amount){
            this.getCreditCard().discount(amount);
            return true;
        }
        return false;
    }

    public CreditCard getCreditCard() {
        return creditCard;
    }

    @Override
    public String toString() {
        return "Individual{" + super.toString() +
                "creditCard=" + creditCard.toString() +
                "}";
    }

}
