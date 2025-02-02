package proje;

public class Corparation extends Subscriber {
	private int bankCode;
	private String bankName;
	private int issueDay;
	private int issueMonth;
	private int issueYear;
	private int accountNumber;
	
	public Corparation(String name, String address) {
		super(name, address);
	}
	
	public void setPaymentInfo(int bankCode,String bankName,int issueDay,int issueMonth,int issueYear,int accountNumber) {
		this.bankCode=bankCode;
		this.bankName=bankName;
		this.issueDay=issueDay;
		this.issueMonth=issueMonth;
		this.issueYear=issueYear;
		this.accountNumber=accountNumber;
	}
	
	@Override
	public String getBillingInformation() {
		return "[bankCode=" + bankCode + ", bankName=" + bankName + ", issueDay=" + issueDay
				+ ", issueMonth=" + issueMonth + ", issueYear=" + issueYear + ", accountNumber=" + accountNumber + "]";
	}
}
