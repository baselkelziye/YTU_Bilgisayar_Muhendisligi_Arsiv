package lab2;

public class KitapKafe {
	private Masa[] masalar;

	public KitapKafe(int n) {
		if(n > 0 && n < 3) {
			masalar = new Masa[2];
		}
	}
	
	public boolean yerAyir(Kisi kisi) {
		for(int i=0;i<masalar.length;i++) {
			if(masalar[i] != null) {
				for(int j=0;j<masalar[i].getSandalyeler().length;j++) {
					if(masalar[i].getSandalyeler()[j] != null && masalar[i].getSandalyeler()[j].isDoluluk() == false) {
						if(kisi.odemeYap(15)) {
							masalar[i].getSandalyeler()[j].setDoluluk(true);
							return true;	
						}					
					}
				}
			}
		}
		return false;
	}
	
	public void tumMasalariGoster() {
		for(int i=0;i<masalar.length;i++) {
			if(masalar[i] != null) {
				System.out.println(i + ".masa");
				masalar[i].masaDolulukGoster();
			}
		}
	}
	
	public void masaEkle(Masa masa) {
		for(int i=0;i<masalar.length;i++) {
			if(masalar[i] == null) {
				masalar[i] = masa;
				return;
			}
		}
	}
}
