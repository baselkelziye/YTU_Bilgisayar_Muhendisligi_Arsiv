package ahmetsefacetin;

public class AhmetSefaCetin {

    public static void main(String[] args) {
        Durak durak1 = new Durak(1);
        Durak durak2 = new Durak(2);
        Durak durak3 = new Durak(3);
        Durak durak4 = new Durak(4);
        Durak durak5 = new Durak(5);

        Otobus oto1 = new Otobus("MK15");
        Otobus oto2 = new Otobus("MK14");

        AnonimKisi kisi1 = new AnonimKisi("A", 1, 10);
        AnonimKisi kisi2 = new AnonimKisi("B", 2, 2);
        AnonimKisi kisi3 = new AnonimKisi("B", 2, 0);

        IndirimliKisi kisi3_ind = new IndirimliKisi("C", 3, 6, 5);
        IndirimliKisi kisi4_ind = new IndirimliKisi("D", 4, 0, 3);

        Iett iett = new Iett(2);
        iett.tumOtobusleriGoster();

        System.out.println("-------------------------LAB2_A-------------------------------");

        //otobuse durak ekleme
        oto1.durakEkle(durak1);
        oto1.durakEkle(durak2, 2);
        //System.out.println("Otobus 1 duraklari");
        //oto1.duraklariGoster();

        oto1.durakSil(durak1);
        //System.out.println("Otobus1 durak silme sonrasi");
        //oto1.duraklariGoster();

        oto2.durakEkle(durak3);
        oto2.durakEkle(durak4);
        oto2.durakEkle(durak5);
        //System.out.println("Otobus2 duraklari");
        //oto2.duraklariGoster();

        // otobus ekleme
        iett.otobusEkle(oto1);
        iett.otobusEkle(oto2);

        System.out.println("\nOnceki  durum:\t" + kisi1);
        iett.otobusBin(kisi1, durak1);
        System.out.println("Sonraki sonrası durum:\t" + kisi1);

        System.out.println("\nOnceki  durum:\t" + kisi1);
        iett.otobusBin(kisi1, durak2);
        System.out.println("Sonraki sonrası durum:\t" + kisi1);

        System.out.println("\nOnceki  durum:\t" + kisi1);
        iett.otobusBin(kisi1, durak2);
        System.out.println("Sonraki sonrası durum:\t" + kisi1);

        System.out.println("\nOnceki  durum:\t" + kisi2);
        iett.otobusBin(kisi2, durak2);
        System.out.println("Sonraki sonrası durum:\t" + kisi2);

        System.out.println("\nOnceki  durum:\t" + kisi3_ind);
        iett.otobusBin(kisi3_ind, durak4);
        System.out.println("Sonraki durum:\t" + kisi3_ind);

        System.out.println("\nOnceki  durum:\t" + kisi3_ind);
        iett.otobusBin(kisi3_ind, durak5);
        System.out.println("Sonraki durum:\t" + kisi3_ind);

        System.out.println("\nOnceki  durum:\t" + kisi3);
        iett.otobusBin(kisi3, durak5);
        System.out.println("Sonraki durum:\t" + kisi3);
    }
}
