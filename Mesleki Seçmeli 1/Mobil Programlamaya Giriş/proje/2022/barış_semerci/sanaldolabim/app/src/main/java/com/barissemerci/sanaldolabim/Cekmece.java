package com.barissemerci.sanaldolabim;

import java.io.Serializable;
import java.util.ArrayList;

public class Cekmece implements Serializable {
    String ikon;

    public String getIkon() {
        return ikon;
    }

    public void setIkon(String ikon) {
        this.ikon = ikon;
    }

    String isim;
    ArrayList<Kiyafet> kiyafetler = new ArrayList<Kiyafet>();

    public Cekmece() {
    }

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public ArrayList<Kiyafet> getKiyafetler() {
        return kiyafetler;
    }

    public void setKiyafetler(ArrayList<Kiyafet> kiyafetler) {
        this.kiyafetler = kiyafetler;
    }
}
