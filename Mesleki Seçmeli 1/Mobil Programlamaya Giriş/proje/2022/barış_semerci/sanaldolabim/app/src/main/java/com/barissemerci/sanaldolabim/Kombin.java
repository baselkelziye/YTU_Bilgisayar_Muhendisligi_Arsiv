package com.barissemerci.sanaldolabim;

import java.io.Serializable;

public class Kombin  implements Serializable {
    Kiyafet basustu;
    Kiyafet surat;
    Kiyafet ustBeden;
    Kiyafet altBeden;
    Kiyafet ayak;
    String isim;
    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }



    public Kombin() {







    }

    public Kiyafet getBasustu() {
        return basustu;
    }

    public void setBasustu(Kiyafet basustu) {
        this.basustu = basustu;
    }

    public Kiyafet getSurat() {
        return surat;
    }

    public void setSurat(Kiyafet surat) {
        this.surat = surat;
    }

    public Kiyafet getUstBeden() {
        return ustBeden;
    }

    public void setUstBeden(Kiyafet ustBeden) {
        this.ustBeden = ustBeden;
    }

    public Kiyafet getAltBeden() {
        return altBeden;
    }

    public void setAltBeden(Kiyafet altBeden) {
        this.altBeden = altBeden;
    }

    public Kiyafet getAyak() {
        return ayak;
    }

    public void setAyak(Kiyafet ayak) {
        this.ayak = ayak;
    }
}
