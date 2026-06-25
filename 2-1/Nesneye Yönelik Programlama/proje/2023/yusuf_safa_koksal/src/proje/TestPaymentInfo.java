package proje;

import junit.framework.TestCase;

public class TestPaymentInfo extends TestCase{
	private PaymentInfo paymentInfo;
	
	protected void setUp() {
		paymentInfo=new PaymentInfo(10.0);
	}
	
	public void testGetDiscountRatio() {
		double result=paymentInfo.getDiscountRatio();
		assertEquals(result, 10.0);
	}
	
	public void testIncreasePayment() {
		paymentInfo.increasePayment(15.0);
		double result=paymentInfo.getReceivedPayment();
		assertEquals(result, 15.0);
	}
}
