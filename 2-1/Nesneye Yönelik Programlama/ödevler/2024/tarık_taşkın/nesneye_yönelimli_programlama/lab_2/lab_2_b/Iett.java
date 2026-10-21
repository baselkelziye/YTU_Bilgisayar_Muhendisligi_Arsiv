package lab2_b;

public class Iett {
	private Otobus[] otobusler;

	public Iett(int otobusSayisi) {
		this.otobusler = new Otobus[otobusSayisi];
	}

	public boolean otobusBin(Kisi kisi, Durak durak) {
		int n = otobusler.length;
		for (int i = 0; i < n; i++) {
			if(otobusler[i]!=null) {
			Durak[] duraklar = otobusler[i].getDuraklar();
			for (int j = 0; j < duraklar.length; j++) {
				if (duraklar[j] != null && duraklar[j].equals(durak)) {
					if (kisi.odemeYap(otobusler[i].getDurakSayisi())) {
						System.out.println(otobusler[i].getOtobusNo() + " otobusune bindiniz.");
						return true;

					}

					else {
						System.out.println("Bakiye Yetersiz.");
						return false;
					}

				}
			}
		}
		}
		System.out.println("Boyle bir durak Yok");
		return false;
	}

	public void tumOtobusleriGoster() {
		for (int i = 0; i < otobusler.length; i++) {
			if (otobusler[i] != null) {
				System.out.println(i + ".otobus");
				otobusler[i].duraklariGoster();

				// otobusGoster(otobusler[i]);

			}
		}
	}

	/*
	 * public void otobusGoster(Otobus m) { // if (m != null) m.duraklariGoster(); }
	 */

	public void otobusEkle(Otobus otobus) {
		int i = 0;
		while (i < otobusler.length && otobusler[i] != null)
			i++;

		if (i != otobusler.length)
			otobusler[i] = otobus;
	}

}
