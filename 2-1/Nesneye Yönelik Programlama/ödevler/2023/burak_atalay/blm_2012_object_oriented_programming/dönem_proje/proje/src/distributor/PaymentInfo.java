package distributor;

public class PaymentInfo implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private final double discountRatio;
    private double receivedPayment;

    public PaymentInfo(double discountRatio) {
        this.discountRatio = discountRatio;
        this.receivedPayment = 0.0;
    }

    public void increaseReceivedPayment(double amount){
        receivedPayment += amount;
    }

    public double getDiscountRatio() {
        return discountRatio;
    }

    public double getReceivedPayment() {
        return receivedPayment;
    }

    @Override
    public String toString() {
        return "PaymentInfo{" +
                "discountRatio=" + discountRatio +
                ", receivedPayment=" + receivedPayment +
                '}';
    }
}
