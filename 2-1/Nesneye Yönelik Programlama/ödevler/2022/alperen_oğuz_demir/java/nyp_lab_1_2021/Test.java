package nyp_lab1_2021;

public class Test {
	public static void main(String[] args) {
		
		Urun urun1 = new Urun(91,"ekmek",1.25);
		Urun urun2 = new Urun(92,"su",4.5);
		Urun urun3 = new Urun(93,"makarna",2.15);
		Urun urun4 = new Urun(94,"çikolata",1);
		Urun urun5 = new Urun(95,"meşrubat",2.75);
		
		Musteri musteri = new Musteri("Ali","Yılmaz");
	
		musteri.siparisVer(0,urun2);
		musteri.siparisVer(0,urun4);
		musteri.siparisBilgisi(0);
		System.out.println("---------------------");
		musteri.siparisVer(1,urun2);
		musteri.siparisVer(1,urun2);
		musteri.siparisVer(1, urun1);
		musteri.siparisVer(2,urun3);
		musteri.siparisVer(2, urun5);
		musteri.tumSiparisler();
		System.out.println("---------------------");
		musteri.kacSiparis("su");
		System.out.println("---------------------");
		urun3.zamYap(0.05);
		urun5.zamYap(0.1);
		System.out.printf("Toplam %d defa zam yapıldı.\n", Urun.getZamSayisi());
		System.out.println("---------------------");
		musteri.urunCikar(0,urun4);
		musteri.tumSiparisler();
		System.out.println("---------------------");
		musteri.tumSiparislerdenUrunCikar(urun2);
		musteri.tumSiparisler();
		System.out.println("---------------------");
        System.out.println(musteri.getSiparisTutari(2));
        

		
	}
}
