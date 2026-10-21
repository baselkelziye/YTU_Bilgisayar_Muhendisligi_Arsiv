package lab2_b;

public abstract class Kisi {
	private String ad;
	private int id;
	private double bakiye;
	private final int birimUcret;

	public Kisi(String ad, int id, double bakiye) {
		this.ad = ad;
		this.id = id;
		this.bakiye = bakiye;
		birimUcret=2;
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

	public int getBirimUcret() {
		return birimUcret;
	}

	public abstract boolean odemeYap(int durakSayisi);

}
