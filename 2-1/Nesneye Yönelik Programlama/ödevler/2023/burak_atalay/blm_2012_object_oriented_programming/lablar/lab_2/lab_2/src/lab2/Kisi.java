package lab2;

public abstract class Kisi {
	protected String ad;
	private int id;
	private double bakiye;
	public Kisi(String ad, int id, double bakiye) {
		super();
		this.ad = ad;
		this.id = id;
		this.bakiye = bakiye;
	}
	
	public void setBakiye(double bakiye) {
		this.bakiye = bakiye;
	}
	
	public double getBakiye() {
		return bakiye;
	}

	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", id=" + id + ", bakiye=" + bakiye + "]";
	}
	
	public abstract boolean odemeYap(double odeme);
}
