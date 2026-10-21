package lab2_a;

import uyg2.Raf;

public class KitapKafe {
	private Masa[] masalar;

	public KitapKafe(int masaSayisi) {
		this.masalar = new Masa[masaSayisi];
	}

	
	public boolean yerAyir(Kisi kisi) {
        int n = masalar.length;
        for (int i = 0; i < n; i++){
        	Sandalye[] sandalyeler= masalar[i].getSandalyeler();
        	for (int j=0; j<sandalyeler.length; j++){
                if(sandalyeler[j] != null && !sandalyeler[j].isDoluluk())
                {
                	if (kisi.odemeYap(sandalyeler[j].getUcret())){            
                        //System.out.println("Satış Gerçekleşti.");
                		sandalyeler[j].setDoluluk(true);
            			System.out.println(i + ".masa "+ j +".sandalyeye atandınız");
            			return true;
                    }
                    
                    else{            
                        System.out.println("Bakiye Yetersiz.");
                        return false;
                    }
                }                    
            }
        }
        System.out.println("Bos Masa Yok");
        return false;
    }
	
	
	
	/*
	 * public void masaGoster(int n) { if(n<masalar.length)
	 * masalar[n].masaDolulukGoster(); }
	 */

	public void tumMasalariGoster() {
		for (int i = 0; i < masalar.length; i++) {
			if (masalar[i] != null) {
				System.out.println(i + ".masa");
				//masaGoster(masalar[i]);
				masalar[i].masaDolulukGoster();;
				// masaGoster(i);
			}
		}
	}

	public void masaGoster(Masa m) {
		// if (m != null)
		m.masaDolulukGoster();
	}

	public void masaEkle(Masa masa) {
		int i = 0;
		while (i < masalar.length && masalar[i] != null)
			i++;

		if (i != masalar.length)
			masalar[i] = masa;
	}

}
