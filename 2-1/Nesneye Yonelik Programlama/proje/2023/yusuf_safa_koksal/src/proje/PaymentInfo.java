package proje;

import java.io.Serializable;

public class PaymentInfo implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = -4508217877687387366L;
	private final double discountRatio;
	private double receivedPayment;
	
	public PaymentInfo(double discountRatio) {
		this.discountRatio = discountRatio;
		this.receivedPayment = 0;
	}

	public void increasePayment(double payment) {
		this.receivedPayment+=payment;
	}
	
	public double getReceivedPayment() {
		return this.receivedPayment;
	}

	public double getDiscountRatio() {
		return discountRatio;
	}
}
