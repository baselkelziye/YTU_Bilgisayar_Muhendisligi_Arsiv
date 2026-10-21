package kitaplikornek;

public class Kitaplik {
	Raf[] raflar;

	public Kitaplik(int rafSayisi) {
		raflar =new Raf[rafSayisi];
		for(int i=0 ; i<rafSayisi ; i++) {
			raflar[i]=new Raf();
		}
	}
	public void kitapEkle(Kitap ktp) {
		raflar[ktp.getRafNo()].kitapEkle(ktp);
	}
	public void kitapSil(Kitap ktp)	{
		raflar[ktp.getRafNo()].kitapSil(raflar[ktp.getRafNo()].kitaplar.indexOf(ktp));
	}
	public Kitap kitapAra(String kitapAdi) {
		
		for(int i=0; i<raflar.length ; i++) {
			for(int j=0; j<raflar[i].kitaplar.size(); j++) {
				
				if(raflar[i].kitaplar.get(j).getKitapAd().compareTo(kitapAdi)==0){
					return raflar[i].kitaplar.get(j);
				}	
			}
		}
		return null;
	}
	public boolean rafKontrol(int index) {
		if(raflar[index]==null) {
			return false;
		}
		return true;
	}
	public void gosterRaf(int rafno){
		System.out.println(rafno + ".Raftaki Kitaplar...\nKitap Adı\t\t\tYazar\\ISBN");
		for(int i=0; i<raflar[rafno].kitaplar.size(); i++) {
			System.out.println(raflar[rafno].kitaplar.get(i).getKitapAd()+"\t\t"+raflar[rafno].kitaplar.get(i).getYazar()+"\\"+raflar[rafno].kitaplar.get(i).getISBN());
		}
		System.out.println("\n\n");
	}
}
