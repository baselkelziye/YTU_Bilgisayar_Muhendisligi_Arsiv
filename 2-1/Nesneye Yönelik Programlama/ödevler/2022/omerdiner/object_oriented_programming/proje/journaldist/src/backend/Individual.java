package backend;

import java.io.Serial;
import java.io.Serializable;

public class Individual extends Subscriber implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private String creditCardNo;
    private int expireMonth;
    private int expireYear;
    private int CCV;

    public Individual(String name, String address, String creditCardNr, int expireMonth, int expireYear, int CCV) {
        super(name, address);
        this.creditCardNo = creditCardNr;
        this.expireMonth = expireMonth;
        this.expireYear = expireYear;
        this.CCV = CCV;
    }
    public Individual(String name, String address) {
        super(name, address);

    }
    @Override
    public String getBillingInformation() {

        return "Credit Card No: " + creditCardNo + "\n" +
                "Expire Date: " + expireMonth + "/" + expireYear + "\n" +
                "CCV: " + CCV;
    }

    public String getCreditCardNo() {
        return creditCardNo;
    }

    public void setCreditCardNo(String creditCardNo) {
        this.creditCardNo = creditCardNo;
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
    public String toString() {
        return super.toString()+"Individual{" +
                "creditCardNo='" + creditCardNo + '\'' +
                ", expireMonth=" + expireMonth +
                ", expireYear=" + expireYear +
                ", CCV=" + CCV +
                '}';
    }
}
