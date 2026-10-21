package com.barissemerci.sanaldolabim;

import java.io.Serializable;
import java.util.ArrayList;

public class Etkinlik implements Serializable {
    String isim;
    String tur;
    String tarih;
    String lokasyon;
    ArrayList<Kiyafet> kiyafetler= new ArrayList<>();

    public Etkinlik() {
    }

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public String getTur() {
        return tur;
    }

    public void setTur(String tur) {
        this.tur = tur;
    }

    public String getTarih() {
        return tarih;
    }

    public void setTarih(String tarih) {
        this.tarih = tarih;
    }

    public String getLokasyon() {
        return lokasyon;
    }

    public void setLokasyon(String lokasyon) {
        this.lokasyon = lokasyon;
    }

    public ArrayList<Kiyafet> getKiyafetler() {
        return kiyafetler;
    }

    public void setKiyafetler(ArrayList<Kiyafet> kiyafetler) {
        this.kiyafetler = kiyafetler;
    }
}
