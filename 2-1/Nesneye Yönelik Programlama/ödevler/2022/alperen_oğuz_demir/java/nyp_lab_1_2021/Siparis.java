package nyp_lab1_2021;

public class Siparis {
	Urun[] urunler=new Urun[5];
	int index=0;
	public Siparis(){
		for(int i=0; i<5;i++) {
			this.urunler[i]=new Urun(i, null, i);
		}
	}
	public Urun[] getUrunler() {
		return urunler;
	}
	public void urunEkle(Urun urun) {
		if(index<5) {
			this.urunler[index]=urun;
			index++;
		}
	}
	public void urunleriGoster() {
		for(Urun a:urunler) {
			if(a.getAd()!=null) {
				System.out.println(a.toString());
			}
			else {
				System.out.println("null");
			}
		}
	}
	public void urunCikar(Urun urun) {
		for(int i=0; i<urunler.length; i++) {
			if(urunler[i]==urun) {
				urunler[i].setAd(null);
			}
		}
	}
	public double getToplamTutar() {
		double toplam=0;
		for(Urun a:urunler) {
			if(a.getAd()!=null) {
				toplam+=a.getFiyat();
			}
		}
		return toplam;
	}
}
