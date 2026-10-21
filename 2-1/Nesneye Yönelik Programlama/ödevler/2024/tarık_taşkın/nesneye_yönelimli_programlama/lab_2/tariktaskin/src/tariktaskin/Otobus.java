package tariktaskin;

public class Otobus {
	private String otobusNo;
	private Durak[] duraklar;
	
	public Otobus(String otobusNo) {
		this.otobusNo = otobusNo;
		duraklar = new Durak[3];
	}
	
	public void durakEkle(Durak durak) {
		int i = 0;
		
		if (durak != null) {
			while (i < duraklar.length && durak != duraklar[i]) {
				i++;
			}
			
			if(i != duraklar.length) {
				i = 0;
				while (i < 3 && duraklar[i] != null) {
					i++;
				}
				duraklar[i] = durak;
			}
			else {
				System.out.println("Bu durak zaten var.");
			}
			
		}
		else {
			System.out.println("Boyle bir durak yok");
		}
		
	}
	
	public void durakEkle(Durak durak, int sira) {
		if(durak != null && duraklar[sira] != null) {
			duraklar[sira] = durak;
		}
	}
	
	public void durakSil(Durak durak) {
		int i = 0;
		
		while(i<duraklar.length && duraklar[i] != durak) {
			i++;
		}
		
		if(i != duraklar.length) {
			duraklar[i] = null;
		}
		else {
			System.out.println("boyle bir durak zaten yok");
		}
	}
	
	public void duraklariGoster() {
		int i = 0;

		System.out.print("Duraklar: ");
		while (i < 3) {
			if (duraklar[i] != null) {
				System.out.print(duraklar[i] + " ");
			}
			i++;
		}
	}

	public String getOtobusNo() {
		return otobusNo;
	}

	public Durak[] getDuraklar() {
		return duraklar;
	}
	
	public int getDurakSayisi() {
		int i = 0;
		int durakSayisi=0;
		
		for(i=0;i<duraklar.length;i++){
			if(duraklar[i] != null) {
				durakSayisi++;
			}
		}
		 return durakSayisi;	
	}
}