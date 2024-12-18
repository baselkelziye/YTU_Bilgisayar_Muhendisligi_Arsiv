package Lab3;

import java.io.Serializable;

public class Ogrenci implements Serializable{
	private static final long serialVersionUID = 1L;
	private String ogrenciAdi;
	private String ogrenciNo;
	private int vize;
	private int final_;
	private double genelNot;
	public Ogrenci(String ogrNo,String ogrAdi, int vize, int final_) {
		this.ogrenciAdi=ogrAdi;
		this.ogrenciNo=ogrNo;
		this.final_=final_;
		this.vize=vize;
	}
	public String getOgrenciAdi() {
		return ogrenciAdi;
	}
	public String getOgrenciNo() {
		return ogrenciNo;
	}
	public int getVize() {
		return vize;
	}
	public int getFinal_() {
		return final_;
	}
	public double getGenelNot() {
		return genelNot;
	}
	public void genelNotHesapla() {
		this.genelNot=vize*0.4+final_*0.6;
	}
	public String toString() {
		return this.ogrenciNo + " numarali " + this.ogrenciAdi + 
				" adindaki ogrencinin genel notu= " + this.genelNot+
				"'dur";
	}
}
