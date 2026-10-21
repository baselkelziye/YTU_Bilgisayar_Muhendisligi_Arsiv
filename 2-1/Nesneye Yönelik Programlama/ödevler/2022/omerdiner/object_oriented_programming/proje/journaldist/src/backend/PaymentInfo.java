package backend;

import java.io.Serial;
import java.io.Serializable;

public class PaymentInfo implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private final double discountRatio;
    private double receivedPayment;


    public PaymentInfo(double discountRatio) {
        this.discountRatio = discountRatio;
        this.receivedPayment = 0;
    }



    public void increasePayment(double amount){
        receivedPayment+=amount;
    }

    public double getDiscountRatio() {
        return discountRatio;
    }

    public double getReceivedPayment() {
        return receivedPayment;
    }

    public void setReceivedPayment(double receivedPayment) {
        this.receivedPayment = receivedPayment;
    }

    @Override
    public String toString() {
        return "PaymentInfo{" +
                "discountRatio=" + discountRatio +
                ", receivedPayment=" + receivedPayment +
                '}';
    }
}
