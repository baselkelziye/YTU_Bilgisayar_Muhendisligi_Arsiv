package kitaplikornek;

public class Kitap {
	private String kitapAd;
	private String yazar;
	private String ISBN;
	private int rafNo;
	private int sira;
	public Kitap(String kitapAd, String yazar, String iSBN, int rafNo, int sira) {
		this.kitapAd = kitapAd;
		this.yazar = yazar;
		ISBN = iSBN;
		this.rafNo = rafNo;
		this.sira = sira;
	}
	public String getKitapAd() {
		return kitapAd;
	}
	public String getYazar() {
		return yazar;
	}
	public String getISBN() {
		return ISBN;
	}
	public int getRafNo() {
		return rafNo;
	}
	public int getSira() {
		return sira;
	}
	
}
