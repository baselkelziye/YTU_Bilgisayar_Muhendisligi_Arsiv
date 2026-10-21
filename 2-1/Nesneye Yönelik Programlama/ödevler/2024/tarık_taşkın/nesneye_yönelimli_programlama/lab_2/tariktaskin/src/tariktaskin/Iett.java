package tariktaskin;

public class Iett {
	private Otobus otobusler[];

	public Iett(int kapasite) { // en fazla 2 otobus alabilir
		otobusler = new Otobus[kapasite];
	}

	public boolean otobusBin(Kisi kisi, Durak durak) {
		int i=0;
		int j;
		if(kisi != null) {
			if(durak != null) {
				while(i<otobusler.length) {
					if(otobusler[i] != null) {
						Durak[] geciciDuraklar = otobusler[i].getDuraklar();
						j = 0;
						while(j<geciciDuraklar.length && geciciDuraklar[j]!=durak) {
							j++;
						}
						if(j != geciciDuraklar.length) {
							kisi.odemeYap(otobusler[i].getDurakSayisi());
							System.out.println(otobusler[i].getOtobusNo() + " otobusune bindiniz");
							return true;
						}
						else{
							i++;
						}
					}
					else {
						i++;
					}
					
				}
			}
			else {
				System.out.println("Boyle bir durak yok");
			}
		}
		else {
			return false;
		}
		return false;
	}

	public void tumOtobusleriGoster() {
		int i = 0;

		System.out.print("Otobusler: ");
		while (i < 2) {
			if (otobusler[i] != null) {
				System.out.print(otobusler[i] + " ");
			}
			i++;
		}
	}

	public void otobusEkle(Otobus otobus) {
		int i = 0;

		if (otobus != null) {
			while (i < otobusler.length && otobus != otobusler[i]) {
				i++;
			}
			
			if(i != otobusler.length) {
				i = 0;
				while (i < 2 && otobusler[i] != null) {
					i++;
				}
				otobusler[i] = otobus;
			}
			else {
				System.out.println("Bu otobus zaten var.");
			}
			
		}
	}
}
