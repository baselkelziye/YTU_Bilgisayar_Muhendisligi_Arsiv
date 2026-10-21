package test;

import distributor.PaymentInfo;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PaymentInfoTest {
    @Test
    void increasePaymentTest1(){
        PaymentInfo paymentInfo = new PaymentInfo(0.5);
        paymentInfo.increaseReceivedPayment(10.5);
        paymentInfo.increaseReceivedPayment(5.3);
        assertEquals(15.8, paymentInfo.getReceivedPayment());
    }
    @Test
    void increasePaymentTest2(){
        PaymentInfo paymentInfo = new PaymentInfo(0.6);
        paymentInfo.increaseReceivedPayment(100);
        paymentInfo.increaseReceivedPayment(6.9);
        assertEquals(106.9, paymentInfo.getReceivedPayment());
    }
}