package ahmetsefacetin;

public class Iett {

    private Otobus otobusler[];

    public Iett(int n) {
        otobusler = new Otobus[n];

    }

    public boolean otobusBin(Kisi kisi, Durak durak) {
        int a = 0;
        for (int i = 0; i < otobusler.length; i++) {
            if (otobusler[i] != null) {
                for (int j = 0; j < otobusler[i].getDuraklar().length; j++) {
                    if (otobusler[i].getDuraklar()[j] != null && otobusler[i].getDuraklar()[j] == durak) {
                        System.out.println("Odemesi gereken tutar:" + otobusler[i].getDurakSayisi() * kisi.getBirimUcret());
                        if (kisi.odemeYap(otobusler[i].getDurakSayisi())) {
                            System.out.println(otobusler[i].getOtobusNo() + " otobüsüne bindidiz.");
                        }
                        a = 1;
                        
                        return true;
                    }
                }
            }

        }
        System.out.println("Böyle bir durak yok");

        return false;
    }

    public void tumOtobusleriGoster() {

    }

    public void otobusEkle(Otobus otobus) {
        int i = 0;
        while (i < otobusler.length && otobusler[i] != null) {
            i++;
        }
        if (i != otobusler.length) {
            otobusler[i] = otobus;
        }
    }

}
