package nyp_lab_excersize_21;

import java.util.ArrayList;

public class Siparis {
	private ArrayList<Urun> urunler;

	public Siparis() {
		urunler = new ArrayList<Urun>(5);
	}

	public ArrayList<Urun> getUrunler() {
		return urunler;
	}
	
	public void urunEkle(Urun urun) {
		urunler.add(urun);
	}
	
	public void urunleriGoster() {
		if (urunler.isEmpty()) {
			System.out.println("Bu sipariste herhangi bir urun bulunmamaktadır!!");
		} else {
			for(Urun urun:urunler) {
				System.out.println(urun.toString()); 
			}
		}
	}
	
	public void urunCıkar(Urun urun) {
		if(urunler.isEmpty() == false) {
			if(urunler.remove(urun) == true) {
				System.out.println(urun.getAd() + " urunu siparisten cıkarıldı.");
			}
			else {
				System.out.println("Urun cıkartılamadı, bu sipariste " + urun.getAd() + " urunu bulunmamaktadır.");
			}
		}
		else {
			System.out.println("Bu sipariste herhangi bir urun bulunmamaktadır!!");
		}
	}
	
	public double getToplamTutar() {
		double toplam = 0;
		for(Urun urun: urunler) {
			toplam += urun.getFiyat();
		}
		return toplam;
	}
	
}
