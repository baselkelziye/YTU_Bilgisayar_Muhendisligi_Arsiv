package lab2_a;

public class Abonman extends Kisi {
	private int kredi;

	public Abonman(String ad, int id, double bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi = kredi;
	}

	@Override
	public boolean odemeYap(double fiyat) {
		if (getKredi() >= 5) {
			System.out.println("Giriş hakkından düşüm gerçekleşti");
			setKredi(getKredi() - 5);
			return true;
		}
		if (getBakiye() >= fiyat) {
			System.out.println("Bakiyenizden düşüm gerçekleşti");
			setBakiye(getBakiye() - fiyat);
			kredi += 1;
			return true;
		}

		return false;

	}

	public int getKredi() {
		return kredi;
	}

	public void setKredi(int kredi) {
		this.kredi = kredi;
	}

	@Override
	public String toString() {
		return super.toString() + " Abonman [girisHakki=" + kredi + "]";

	}

}
