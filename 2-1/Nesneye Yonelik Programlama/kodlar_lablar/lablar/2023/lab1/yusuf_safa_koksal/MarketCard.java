package yusufsafakoksal;

public class MarketCard {
	private int cardNo;
	private double points;
	
	public MarketCard(int cardNo) {
		this.cardNo = cardNo;
		points=0;
	}
	
	public void addPoints(double pointsToAdded) {
		points+=pointsToAdded;
	}
	
	public double getPoints() {
		return points;
	}
	
}
