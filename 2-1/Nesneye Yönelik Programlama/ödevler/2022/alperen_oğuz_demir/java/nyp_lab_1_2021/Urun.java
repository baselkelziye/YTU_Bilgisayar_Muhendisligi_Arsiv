package nyp_lab1_2021;

public class Urun {
	private int ID;
	private String ad;
	private double fiyat;
	static int zamSayisi=0;
	public Urun(int iD, String ad, double fiyat) {
		ID = iD;
		this.ad = ad;
		this.fiyat = fiyat;
		
	}
	public String getAd() {
		return ad;
	}
	public void setAd(String ad) {
		this.ad = ad;
	}
	public int getID() {
		return ID;
	}
	public double getFiyat() {
		return fiyat;
	}
	public static int getZamSayisi() {
		return zamSayisi;
	}
	public void zamYap(double zamOrani) {
		zamSayisi++;
		fiyat=fiyat+fiyat*zamOrani;
		///////////////////////
	}
	public String toString(){
		return "Urun [id="+ID+"   ad="+ad+"   fiyat="+fiyat+"]";
	}
}
