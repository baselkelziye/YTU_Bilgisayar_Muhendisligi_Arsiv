package subscriber;

public class Corporation extends Subscriber implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private int issueDay, issueMonth, issueYear;
    private String bankName;
    private int bankCode, accountNumber;

    public Corporation(int id, String address, String name, int issueDay, int issueMonth,
                       int issueYear, String bankName, int bankCode, int accountNumber) {
        super(id, address, name);
        this.issueDay = issueDay;
        this.issueMonth = issueMonth;
        this.issueYear = issueYear;
        this.bankName = bankName;
        this.bankCode = bankCode;
        this.accountNumber = accountNumber;
    }

    @Override
    public String getBillingInformation() {
        return this.toString();
    }

    @Override
    public boolean canSend(int issueMonth, double amount) {
        return true;
    }

    @Override
    public String toString() {
        return "Corporation{" + super.toString() +
                "issueDay=" + issueDay +
                ", issueMonth=" + issueMonth +
                ", issueYear=" + issueYear +
                ", bankName='" + bankName + '\'' +
                ", bankCode=" + bankCode +
                ", accountNumber=" + accountNumber +
                "}";
    }
}
