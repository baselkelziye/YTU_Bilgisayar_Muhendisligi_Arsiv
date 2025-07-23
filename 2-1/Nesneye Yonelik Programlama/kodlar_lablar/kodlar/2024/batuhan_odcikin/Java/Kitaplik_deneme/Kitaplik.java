package deneme;

public class Kitaplik {
	Raf raflar[];
	
	public Kitaplik(int rafSayisi) {
		this.raflar = new Raf[rafSayisi];
		for (int i = 0; i < rafSayisi; i++) {
			raflar[i] = new Raf();
		}
	}
	
	public boolean kitapEkle(Kitap ktp) {
		return raflar[ktp.getRafNo()].kitapEkle(ktp);
	}
	
	public Kitap kitapSil(Kitap ktp) {
		return raflar[ktp.getRafNo()].kitapSil(raflar[ktp.getRafNo()].kitaplar.indexOf(ktp ));
	}
	
	public Kitap kitapAra(String kitapAdi) {
		for(int i = 0; i < raflar.length; i++) { // raf[i]
			for(Kitap tmp_kitap : raflar[i].kitaplar) {
				if(tmp_kitap.getAd().compareTo(kitapAdi) == 0){
					return tmp_kitap;
				}
			}
		}
		return null;
	}
	public void rafYazdir(int rafNo) {
		System.out.println(rafNo + ".raftaki kitapların Listesi");
		System.out.println("Kitap\t|\tYazar\t|\tISBN");
		for(int i = 0; i < raflar[rafNo].kitaplar.size();i++) {
			System.out.println(i+")"+raflar[i].kitaplar.get(i).getAd()+
					"\t\t"+raflar[i].kitaplar.get(i).getYazar()+
					"\t\t"+raflar[i].kitaplar.get(i).getISBN());
		}
	}
}
