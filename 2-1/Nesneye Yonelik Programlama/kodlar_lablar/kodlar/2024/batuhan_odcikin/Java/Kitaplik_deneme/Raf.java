package deneme;

import java.util.ArrayList;

public class Raf {

	ArrayList<Kitap> kitaplar;
	
	public Raf() {
		this.kitaplar = new ArrayList<Kitap>();
	}
	
	public boolean kitapEkle(Kitap ktp) {
		if(ktp.getRafNo() <= 0 || ktp.getSiraNo() <= 0) {
			System.out.println("Raf veya Sıra 1 den küçük olamaz!!");
			return false;
		}
		else {
			this.kitaplar.add(ktp);	
			return true;
		}
	}
	
	public Kitap kitapSil(int index) {
		return kitaplar.remove(index);
		
	}
}
