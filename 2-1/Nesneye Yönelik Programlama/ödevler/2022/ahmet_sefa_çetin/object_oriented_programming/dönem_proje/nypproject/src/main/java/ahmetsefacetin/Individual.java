package ahmetsefacetin;

public class Individual extends Subscriber {

    private String creditCardNr;
    private int expireMonth;
    private int expireYear;
    private int CCV;

    public Individual(int id, String name, String adress, double balance, String creditCardNr, int expireMonth, int expireYear, int CCV) {
        super(id, name, adress, balance);
        this.creditCardNr = creditCardNr;
        this.expireMonth = expireMonth;
        this.expireYear = expireYear;
        this.CCV = CCV;
    }

    public String getCreditCardNr() {
        return creditCardNr;
    }

    public void setCreditCardNr(String creditCardNr) {
        this.creditCardNr = creditCardNr;
    }

    public int getExpireMonth() {
        return expireMonth;
    }

    public void setExpireMonth(int expireMonth) {
        this.expireMonth = expireMonth;
    }

    public int getExpireYear() {
        return expireYear;
    }

    public void setExpireYear(int expireYear) {
        this.expireYear = expireYear;
    }

    public int getCCV() {
        return CCV;
    }

    public void setCCV(int CCV) {
        this.CCV = CCV;
    }

    @Override
    public String getBillingInformation() {
        return this.toString();
    }

    @Override
    public String toString() {
        return super.toString() + "Individual{" + "creditCardNr=" + creditCardNr + ", expireMonth=" + expireMonth + ", expireYear=" + expireYear + ", CCV=" + CCV + '}';
    }

}
