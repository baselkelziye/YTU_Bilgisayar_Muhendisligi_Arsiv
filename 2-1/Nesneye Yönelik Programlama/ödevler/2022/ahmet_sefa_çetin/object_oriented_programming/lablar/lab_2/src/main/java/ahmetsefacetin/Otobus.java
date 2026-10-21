package ahmetsefacetin;

public class Otobus {

    private String otobusNo;
    private Durak duraklar[];

    public Otobus(String otobusNo) {
        this.otobusNo = otobusNo;
        duraklar = new Durak[3];
    }

    public String getOtobusNo() {
        return otobusNo;
    }

    public Durak[] getDuraklar() {
        return duraklar;
    }

    public void durakEkle(Durak durak) {
        int i = 0;
        while (i < duraklar.length && duraklar[i] != null) {
            i++;
        }
        if (duraklar.length != i) {
            duraklar[i] = durak;
        }
    }

    public void durakEkle(Durak durak, int sira) {
        duraklar[sira] = durak;
    }

    public void durakSil(Durak durak) {
        int i = 0;
        while (i < duraklar.length && duraklar[i] != durak) {
            i++;
        }
        if (duraklar.length != i) {
            duraklar[i] = null;
        }
        System.out.println("Durak silme işlemi gerçekleşti.");
    }

    public void duraklariGoster() {
        for (int i = 0; i < duraklar.length; i++) {
            if (duraklar[i] != null) {
                ;
            }
        }
    }

    public int getDurakSayisi() {
        int counter = 0;
        for (int i = 0; i < duraklar.length; i++) {
            if (duraklar[i] != null) {
                counter++;
            }
        }
        return counter;
    }

}
