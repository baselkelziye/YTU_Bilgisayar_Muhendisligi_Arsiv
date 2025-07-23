package nyp_lab_excersize_21;

import java.util.ArrayList;

public class Musteri {
	private String ad;
	private String soyad;
	private ArrayList<Siparis> siparisler;
	public Musteri(String ad, String soyad) {
		this.ad = ad;
		this.soyad = soyad;
		siparisler = new ArrayList<Siparis>(3);
		
		for (int i = 0; i < 3; i++) {
			siparisler.add(new Siparis());
		}
	}
	
	public void siparisVer(int siparisNo, Urun urun) {
		siparisler.get(siparisNo).urunEkle(urun);
	}
	
	public void siparisBilgisi(int siparisNo) {
		siparisler.get(siparisNo).urunleriGoster();
	}
	
	public void tumSiparisler() {
		for(int i = 0; i<3;i++) {
			System.out.println(i+".siparis icin siparis bilgisi:");
			siparisler.get(i).urunleriGoster();
		}
	}
	
	public void kacSiparis(String urunAdi) {
		int urunSayisi = 0;
		for(Siparis siparis:siparisler) {
			for(Urun urun: siparis.getUrunler()) {
				if(urun.getAd().compareTo(urunAdi) == 0) {
					urunSayisi++;
				}
			}
		}
		System.out.println("Siparislerde " + urunAdi +" urununden " + urunSayisi + " adet bulunmaktadır.");
	}
	
	public void tumSiparislerdenUrunCıkar(Urun urun) {
		for(Siparis siparis:siparisler) {
			siparis.urunCıkar(urun);
		}
	}
	
	public void urunCıkar(int siparisNo, Urun urun) {
		siparisler.get(siparisNo).urunCıkar(urun);
	}
	
	public double getSiparisTutari(int siparisNo) {
		double toplam = 0;
		for(Siparis siparis:siparisler) {
			toplam += siparis.getToplamTutar();
		}
		return toplam;
	}
	
	
}
