package lab2_b;

public class AnonimKisi extends Kisi {

	public AnonimKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	@Override
	public boolean odemeYap(int durakSayisi) {
		int odenecekTutar = getBirimUcret() * durakSayisi;
		System.out.println("Odenmesi gereken tutar:" + odenecekTutar);
		if (getBakiye() >= odenecekTutar) {
			System.out.println("Odeme gerçekleşti");
			setBakiye(getBakiye() - odenecekTutar);
			return true;
		}
		return false;

	}

}
