
public class Ilac {
    
    private String isim;
    private int barkodno;
    private String tur;
    private int fiyat;
    private int adet;

    public Ilac(String isim, int barkodno, String tur, int fiyat, int adet) {
        this.isim = isim;
        this.barkodno = barkodno;
        this.tur = tur;
        this.fiyat = fiyat;
        this.adet = adet;
    }

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public int getBarkodno() {
        return barkodno;
    }

    public void setBarkodno(int barkodno) {
        this.barkodno = barkodno;
    }

    public String getTur() {
        return tur;
    }

    public void setTur(String tur) {
        this.tur = tur;
    }

    public int getFiyat() {
        return fiyat;
    }

    public void setFiyat(int fiyat) {
        this.fiyat = fiyat;
    }

    public int getAdet() {
        return adet;
    }

    public void setAdet(int adet) {
        this.adet = adet;
    }
}
