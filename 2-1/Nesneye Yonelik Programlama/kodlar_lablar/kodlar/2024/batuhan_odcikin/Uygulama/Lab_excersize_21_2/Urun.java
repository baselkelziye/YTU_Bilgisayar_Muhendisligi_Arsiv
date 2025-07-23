package nyp_lab_excersize_21;

public class Urun {

	private int ID;
	private String ad;
	private double fiyat;
	private static int zamSayisi;
	
	public Urun(int iD, String ad, double fiyat) {
		ID = iD;
		this.ad = ad;
		this.fiyat = fiyat;
	}

	public String getAd() {
		return ad;
	}
	public int getID() {
		return ID;
	}

	public double getFiyat() {
		return fiyat;
	}
	
	public void setAd(String ad) {
		this.ad = ad;
	}

	public void zamYap (double zamOrani) {
		fiyat = fiyat*zamOrani;
		zamSayisi++;
	}
	
	public int getzamSayisi() {
		return zamSayisi;
	}

	@Override
	public String toString() {
		return "Urun [ID=" + ID + ", ad=" + ad + ", fiyat=" + fiyat + "]";
	}
	
}
