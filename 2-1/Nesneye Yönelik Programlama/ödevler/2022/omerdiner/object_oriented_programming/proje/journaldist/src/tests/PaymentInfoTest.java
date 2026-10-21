package tests;

import backend.PaymentInfo;
import junit.framework.TestCase;

public class PaymentInfoTest extends TestCase {

    private PaymentInfo paymentInfo;

    protected void setUp() {
        paymentInfo = new PaymentInfo(0.3);
    }

    public void testgetDiscountRatio() {
        assertEquals(0.3, paymentInfo.getDiscountRatio());
    }

    public void testgetReceivedPayment() {
        assertEquals(0.0, paymentInfo.getReceivedPayment());
    }

    public void testsetReceivedPayment() {
        paymentInfo.setReceivedPayment(5.4);
        assertEquals(5.4, paymentInfo.getReceivedPayment());
    }

    public void testincreasePayment() {
        paymentInfo.increasePayment(200);
        assertEquals(200.0, paymentInfo.getReceivedPayment());
    }
}
