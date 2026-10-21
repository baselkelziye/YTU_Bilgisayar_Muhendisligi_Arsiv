package lab2_b;

public class IndirimliKisi extends Kisi {
	private int kredi;

	public IndirimliKisi(String ad, int id, int bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi = kredi;
	}

	@Override
	public boolean odemeYap(int durakSayisi) {
		int odenecekTutar = getBirimUcret() * durakSayisi;
		System.out.println("Odenmesi gereken tutar:" + odenecekTutar);
		if (getKredi() >= odenecekTutar) {
			System.out.println("Krediden düşüm gerçekleşti");
			setKredi(getKredi() - odenecekTutar);
			return true;
		}
		if (getBakiye() >= odenecekTutar) {
			System.out.println("Bakiyenizden düşüm gerçekleşti");
			setBakiye(getBakiye() - odenecekTutar);
			kredi += durakSayisi;
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
		return super.toString() + " IndirimliKisi [kredi=" + kredi + "]";

	}

}
