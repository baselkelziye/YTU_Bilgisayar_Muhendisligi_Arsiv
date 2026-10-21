package lab2_b;

import lab2_C.Sandalye;
import uyg2.Kart;
import uyg2.Kitap;

public class Otobus {
	private String otobusNo;
	private Durak[] duraklar;

	public Otobus(String otobusNo) {
		this.otobusNo = otobusNo;
		this.duraklar = new Durak[3];
	
	}

	public void durakEkle(Durak d) {
		int i = 0;
		while (i < duraklar.length && duraklar[i] != null)
			i++;

		if (i != duraklar.length)
			duraklar[i] = d;
		else
			System.out.println("yer olmadıgı ıcın durak eklenemiyor.");
	}

	public void durakEkle(Durak durak, int sira) {
		if (sira < duraklar.length && duraklar[sira] == null)
			duraklar[sira] = durak;

		else
			System.out.println("ilgili yer bos olmadığı için eklenemiyor.");
	}

	public void durakSil(Durak d) {
		int i = 0;
		while (i < duraklar.length && duraklar[i] != d)
			i++;
		if (i != duraklar.length) {
			duraklar[i] = null;
			System.out.println("Durak silme işlemi gerçekleşti.");
		}
	}

	public void duraklariGoster() {
		for (int i = 0; i < duraklar.length; i++)
			System.out.println(duraklar[i]);
	}

	public int getDurakSayisi() {
		int count = 0;
		for (int i = 0; i < duraklar.length; i++)
			if (duraklar[i] != null)
				count++;

		return count;
	}

	public Durak[] getDuraklar() {
		return duraklar;
	}

	public String getOtobusNo() {
		return otobusNo;
	}

	
}
