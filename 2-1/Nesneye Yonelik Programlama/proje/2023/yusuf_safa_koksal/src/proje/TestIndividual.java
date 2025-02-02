package proje;

import junit.framework.TestCase;

public class TestIndividual extends TestCase{
	private Individual individual;
	
	protected void setUp() {
		individual=new Individual("Yusuf Safa Köksal","Samsun");
	}
	
	public void testGetName() {
		String result=individual.getName();
		assertEquals(result, "Yusuf Safa Köksal");
	}
	
	
	public void testGetBillingInformation() {
		individual.setPaymentInfo("0001",1,28,555);
		String result="[creditCardNr=" + "0001" + ", expireMonth=" + 1 + ", expireYear="
				+ 28 + ", CCV=" + 555 + "]";
		assertEquals(individual.getBillingInformation(),result);
	}
	
}
