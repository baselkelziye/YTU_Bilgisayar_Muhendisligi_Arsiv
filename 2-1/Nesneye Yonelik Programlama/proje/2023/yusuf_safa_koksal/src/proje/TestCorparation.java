package proje;

import java.util.Hashtable;

import junit.framework.TestCase;

public class TestCorparation extends TestCase {
	private Corparation corparation;
	
	protected void setUp() {
		corparation=new Corparation("Köksal A.Ş.","Samsun");
	}
	
	public void testGetName() {
		String result=corparation.getName();
		assertEquals(result, "Köksal A.Ş.");
	}
	
	public void testGetBillingInformation() {
		corparation.setPaymentInfo(0001,"Ziraat",1,1,2024,5555);
		String result="[bankCode=" + 0001 + ", bankName=" + "Ziraat" + ", issueDay=" + 1
				+ ", issueMonth=" + 1 + ", issueYear=" + 2024 + ", accountNumber=" + 5555 + "]";
		assertEquals(corparation.getBillingInformation(),result);
	}
}
