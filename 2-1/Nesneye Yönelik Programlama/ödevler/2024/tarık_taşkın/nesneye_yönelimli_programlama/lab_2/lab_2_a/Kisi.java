package lab2_a;

public abstract class Kisi {
	private String ad;
	private int id;
	private double bakiye;

	public Kisi(String ad, int id, double bakiye) {
		this.ad = ad;
		this.id = id;
		this.bakiye = bakiye;
	}

	public double getBakiye() {
		return bakiye;
	}

	public void setBakiye(double bakiye) {
		this.bakiye = bakiye;
	}

	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", id=" + id + ", bakiye=" + bakiye + "]";
	}

	public abstract boolean odemeYap(double ucret);

}
