package proje;

public class Individual extends Subscriber {
	private String creditCardNr;
	private int expireMonth;
	private int expireYear;
	private int CCV;
	
	public Individual(String name, String address) {
		super(name, address);
	}
	
	public void setPaymentInfo(String creditCardNr,int expireMonth,int expireYear,int CCV) {
		this.creditCardNr=creditCardNr;
		this.expireMonth=expireMonth;
		this.expireYear=expireYear;
		this.CCV=CCV;
	}

	@Override
	public String getBillingInformation() {
		return "[creditCardNr=" + creditCardNr + ", expireMonth=" + expireMonth + ", expireYear="
				+ expireYear + ", CCV=" + CCV + "]";
	}
}
