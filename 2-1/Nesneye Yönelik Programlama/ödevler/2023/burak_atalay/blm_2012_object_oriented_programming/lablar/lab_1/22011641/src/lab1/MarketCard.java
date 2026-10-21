package lab1;

public class MarketCard {
	private int cardNo;
	private double points;
	public MarketCard(int cardNo) {
		this.cardNo = cardNo;
	}
	
	public double getPoints() {
		return points;
	}

	public void addPoints(double price) {
		points += price / 10.0;
	}
	
}
