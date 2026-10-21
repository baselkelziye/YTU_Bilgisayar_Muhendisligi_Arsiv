package Lab3;

import java.io.Serializable;

public class Ogrenci implements Serializable{
	private static final long serialVersionUID = 1L;
	private String ogrenciAdi;
	private String ogrenciNo;
	private int vize;
	private int final_;
	private double genelNot;
	public Ogrenci(String ogrenciNo, String ogrenciAdi, int vize, int final_) {
		this.ogrenciAdi = ogrenciAdi;
		this.ogrenciNo = ogrenciNo;
		this.vize = vize;
		this.final_ = final_;
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
	@Override
	public String toString() {
		return "Ogrenci [ogrenciAdi=" + ogrenciAdi + ", ogrenciNo=" + ogrenciNo + ", genelNot=" + genelNot + "]";
	}
	
	public void genelNotHesapla() {
		genelNot = 0.4*getVize()+0.6*getFinal_();
	}
	
	
}
