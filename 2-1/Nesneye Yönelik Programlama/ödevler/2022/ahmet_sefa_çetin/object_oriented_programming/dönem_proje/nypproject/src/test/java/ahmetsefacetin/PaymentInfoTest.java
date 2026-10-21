package ahmetsefacetin;

import org.junit.Test;

import static org.junit.jupiter.api.Assertions.*;

public class PaymentInfoTest {

    PaymentInfo paymentInfo = new PaymentInfo(0.3);
    double receivedPayment = 0;

    @Test
    public void getIssuePrice() {
        assertTrue(paymentInfo.getDiscountRatio() == 0.3);
    }

    @Test
    public void increasePayment() {
        paymentInfo.increasePayment(25.6);
        receivedPayment += 25.6;
        assertTrue(paymentInfo.getReceivedPayment() == receivedPayment);
    }

}