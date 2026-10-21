package com.barissemerci.sanaldolabim;

import java.io.Serializable;

public class Kiyafet implements Serializable {
    String tur;
    String renk;
    String desen;
    String tarih;
    String fiyat;
    String foto;

    public Kiyafet() {
    }

    public String getTur() {
        return tur;
    }

    public void setTur(String tur) {
        this.tur = tur;
    }

    public String getRenk() {
        return renk;
    }

    public void setRenk(String renk) {
        this.renk = renk;
    }

    public String getDesen() {
        return desen;
    }

    public void setDesen(String desen) {
        this.desen = desen;
    }

    public String getTarih() {
        return tarih;
    }

    public void setTarih(String tarih) {
        this.tarih = tarih;
    }

    public String getFiyat() {
        return fiyat;
    }

    public void setFiyat(String fiyat) {
        this.fiyat = fiyat;
    }

    public String getFoto() {
        return foto;
    }

    public void setFoto(String foto) {
        this.foto = foto;
    }

    @Override
    public String toString() {
        return "Kiyafet{" +
                "tur='" + tur + '\'' +
                ", renk='" + renk + '\'' +
                ", desen='" + desen + '\'' +
                ", tarih='" + tarih + '\'' +
                ", fiyat='" + fiyat + '\'' +
                '}';
    }
}
