package nyp_lab_excersize_21;

public class Main {

	public static void main(String[] args) {
		Musteri batuhan = new Musteri("Batuhan", "Odcikin");
		Urun ekmek = new Urun(1, "ekmek", 1.5);
		Urun sut = new Urun(1, "sut", 3.4);
		Urun sucuk = new Urun(1, "sucuk", 4.2);
		Urun yag = new Urun(1, "yag", 2.0);
		Urun pirinc = new Urun(1, "pirinc", 4.3);
		
		batuhan.siparisVer(0, pirinc);
		batuhan.siparisVer(0, ekmek);
		batuhan.siparisVer(0, yag);
		
		batuhan.siparisVer(1, sucuk);
		batuhan.siparisVer(1, sut);
		batuhan.siparisVer(1, yag);
		
		batuhan.tumSiparisler();
		System.out.println("Siparis 0: "+batuhan.getSiparisTutari(0));
		batuhan.kacSiparis("yag");
	}
}
