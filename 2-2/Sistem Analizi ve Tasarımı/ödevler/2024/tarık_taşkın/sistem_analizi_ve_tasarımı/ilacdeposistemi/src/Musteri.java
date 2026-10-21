
public class Musteri {
    
    private int eczaneno;
    private String isim;
    private String adres;
    private String telefonno;
    private String kullaniciadi;
    private String parola;

    public String getParola() {
        return parola;
    }

    public void setParola(String parola) {
        this.parola = parola;
    }

    public String getKullaniciadi() {
        return kullaniciadi;
    }

    public void setKullaniciadi(String kullaniciadi) {
        this.kullaniciadi = kullaniciadi;
    }
    public Musteri(int eczaneno, String isim, String adres, String telefonno,String kullaniciadi, String parola) {
        this.eczaneno = eczaneno;
        this.isim = isim;
        this.adres = adres;
        this.telefonno = telefonno;
        this.kullaniciadi= kullaniciadi;
        this.parola = parola;
    }

    public int getEczaneno() {
        return eczaneno;
    }

    public void setEczaneno(int eczaneno) {
        this.eczaneno = eczaneno;
    }

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public String getAdres() {
        return adres;
    }

    public void setAdres(String adres) {
        this.adres = adres;
    }

    public String getTelefonno() {
        return telefonno;
    }

    public void setTelefonno(String telefonno) {
        this.telefonno = telefonno;
    }
    
    
    
    
    
}
