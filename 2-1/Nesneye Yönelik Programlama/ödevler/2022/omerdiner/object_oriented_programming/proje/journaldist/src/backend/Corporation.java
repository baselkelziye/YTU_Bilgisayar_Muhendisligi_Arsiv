package backend;

import java.io.Serial;
import java.io.Serializable;

public class Corporation extends Subscriber implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private int bankCode;
    private String bankName;
    private int issueDay;
    private int issueMonth;
    private int issueYear;
    private int accountNumber;

    @Override
    public String getBillingInformation() {

        return "Bank Code: " + bankCode + "\n" +
                "Bank Name: " + bankName + "\n" +
                "Issue Date: " + issueDay + "/" + issueMonth + "/" + issueYear + "\n" +
                "Account Number: " + accountNumber;
    }

    public Corporation(String name, String address) {
        super(name, address);

    }

    public Corporation(String name, String address, int bankCode, String bankName, int issueDay, int issueMonth, int issueYear, int accountNumber) {
        super(name, address);
        this.bankCode = bankCode;
        this.bankName = bankName;
        this.issueDay = issueDay;
        this.issueMonth = issueMonth;
        this.issueYear = issueYear;
        this.accountNumber = accountNumber;
    }

    public int getBankCode() {
        return bankCode;
    }

    public void setBankCode(int bankCode) {
        this.bankCode = bankCode;
    }

    public String getBankName() {
        return bankName;
    }

    public void setBankName(String bankName) {
        this.bankName = bankName;
    }

    public int getIssueDay() {
        return issueDay;
    }

    public void setIssueDay(int issueDay) {
        this.issueDay = issueDay;
    }

    public int getIssueMonth() {
        return issueMonth;
    }

    public void setIssueMonth(int issueMonth) {
        this.issueMonth = issueMonth;
    }

    public int getIssueYear() {
        return issueYear;
    }

    public void setIssueYear(int issueYear) {
        this.issueYear = issueYear;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(int accountNumber) {
        this.accountNumber = accountNumber;
    }

    @Override
    public String toString() {
        return super.toString()+"Corporation{" +
                "bankCode=" + bankCode +
                ", bankName='" + bankName + '\'' +
                ", issueDay=" + issueDay +
                ", issueMonth=" + issueMonth +
                ", issueYear=" + issueYear +
                ", accountNumber=" + accountNumber +
                '}';
    }
}
