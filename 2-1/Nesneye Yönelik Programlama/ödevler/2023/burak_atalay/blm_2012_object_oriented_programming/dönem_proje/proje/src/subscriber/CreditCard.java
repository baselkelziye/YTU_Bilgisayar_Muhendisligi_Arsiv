package subscriber;

public class CreditCard implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private String creditCardNr;
    private int expireMonth, expireYear, CCV;
    private double balance;

    public CreditCard(String creditCardNr, int expireMonth, int expireYear, int CCV, double balance) {
        this.creditCardNr = creditCardNr;
        this.expireMonth = expireMonth;
        this.expireYear = expireYear;
        this.CCV = CCV;
        this.balance = balance;
    }

    public String getCreditCardNr() {
        return creditCardNr;
    }

    public int getExpireMonth() {
        return expireMonth;
    }

    public int getExpireYear() {
        return expireYear;
    }

    public int getCCV() {
        return CCV;
    }

    public double getBalance() {
        return balance;
    }

    public void discount(double amount) {
        this.balance -= amount;
    }

    @Override
    public String toString() {
        return "CreditCard{" +
                "creditCardNr='" + creditCardNr + '\'' +
                ", expireMonth=" + expireMonth +
                ", expireYear=" + expireYear +
                ", CCV=" + CCV +
                ", balance=" + balance +
                '}';
    }
}
