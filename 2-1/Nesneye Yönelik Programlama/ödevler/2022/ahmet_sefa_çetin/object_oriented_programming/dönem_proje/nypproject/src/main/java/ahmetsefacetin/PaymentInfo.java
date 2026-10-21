package ahmetsefacetin;

import java.io.Serializable;

public class PaymentInfo implements Serializable {

    private static final long serialVersionUID = 1L;
    private final double discountRatio;
    private double receivedPayment;

    public PaymentInfo(double discountRatio) {
        this.discountRatio = discountRatio;
        this.receivedPayment = 0;
    }

    public double getDiscountRatio() {
        return discountRatio;
    }

    public double getReceivedPayment() {
        return receivedPayment;
    }

    public void increasePayment(double amount) {
        receivedPayment += amount;
    }

    @Override
    public String toString() {
        return "PaymentInfo{" + "discountRatio=" + discountRatio + ", receivedPayment=" + receivedPayment + '}';
    }

}
