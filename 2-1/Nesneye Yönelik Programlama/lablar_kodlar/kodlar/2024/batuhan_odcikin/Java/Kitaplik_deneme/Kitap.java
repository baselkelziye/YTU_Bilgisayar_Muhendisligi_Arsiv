package deneme;

public class Kitap {
	private String ad;
	private String yazar;
	private String ISBN;
	private int rafNo;
	private int siraNo;
	
	public Kitap(String ad, String yazar,String ISBN,int rafNo,int siraNo) {
		this.ad = ad;
		this.yazar = yazar;
		this.ISBN = ISBN;
		this.rafNo = rafNo;
		this.siraNo = siraNo;
		
	}
	public Kitap(String ad, String yazar,String ISBN) {
		this.ad = ad;
		this.yazar = yazar;
		this.ISBN = ISBN;
	}
	
	public String getAd() {
		return this.ad;
	}
	public void setAd(String ad) {
		this.ad = ad;
	}
	
	public String getYazar() {
		return this.yazar;
	}
	public void setYazar(String yazar) {
		this.yazar = yazar;
	}
	
	public String getISBN() {
		return this.ISBN;
	}
	public void setISBN(String ISBN) {
		this.ISBN = ISBN;
	}
	
	public int getRafNo() {
		return this.rafNo;
	}
	public void setRafNo(int rafNo) {
		this.rafNo = rafNo;
	}
	
	public int getSiraNo() {
		return this.siraNo;
	}
	public void getSiraNo(int siraNo) {
		this.siraNo = siraNo;
	}

}
