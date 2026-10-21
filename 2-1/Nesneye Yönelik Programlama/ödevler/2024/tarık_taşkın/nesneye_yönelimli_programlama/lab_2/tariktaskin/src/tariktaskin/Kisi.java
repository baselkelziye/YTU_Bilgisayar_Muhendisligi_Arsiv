package tariktaskin;

public abstract class Kisi {
	protected String ad;
	protected int id;
	protected double bakiye;
	protected final int birimUcret = 2;

	public Kisi(String ad, int id, double bakiye) {
		super();
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

	public int getBirimUcret() {
		return birimUcret;
	}
	
	public abstract boolean odemeYap(int ucret);

	@Override
	public String toString() {
		return "Kisi [ad=" + ad + ", id=" + id + ", bakiye=" + bakiye + "]";
	}
}
