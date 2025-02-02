package yusufsafakoksal;

public class KitapKafe {
	private Masa masalar[];

	public KitapKafe(int masaSayisi) {
		masalar=new Masa[masaSayisi];
	}
	
	public boolean yerAyir(Kisi kisi) {
		for(int i=0;i<2;i++) {
			if(masalar[i]!=null) {
				for(int j=0;j<3;j++) {
					if(masalar[i].getSandalyeler()[j]!=null && !masalar[i].getSandalyeler()[j].isDoluluk()) {
						masalar[i].getSandalyeler()[j].setDoluluk(true);
						System.out.println(i+".masaya " +j+".sandalyeye atandiniz");
						kisi.odemeYap(masalar[i].getSandalyeler()[j].getUcret());
						return true;
					}
				}
			}
		}
		return false;
	}
	
	public void tumMasalariGoster() {
		System.out.println("Kafedeki Tum Masalari Goster");
		for(int i=0;i<2;i++) {
			if(masalar[i]!=null) {
				System.out.println(i+".masa");
				masalar[i].masaDolulukGoster();
			}
		}
	}
	
	public void masaEkle(Masa masa) {
		for(int i=0;i<2;i++) {
			if(masalar[i]==null) {
				masalar[i]=masa;
				return;
			}
		}
		System.out.println("Bos Masa Yok");
	}
}
