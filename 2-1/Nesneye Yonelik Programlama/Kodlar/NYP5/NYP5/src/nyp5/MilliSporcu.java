package nyp5;

public class MilliSporcu {
    protected String isim;
    protected char cinsiyet;
    protected String dogumTarihi;
    protected String dogumYeri;
    protected float boy;
    protected float kilo;
    protected int sporcuNo;

    public MilliSporcu(String isim, char cinsiyet, String dogumTarihi, int sporcuNo) {
        this.isim = isim;
        this.cinsiyet = cinsiyet;
        this.dogumTarihi = dogumTarihi;
        this.sporcuNo = sporcuNo;
    }
    
    public String SporcuProfili(){
        String profil;
        profil = "Merhaba ben " + sporcuNo + " nolu Milli Sporcuyum." +
                "İsim: " + isim + "." + dogumYeri + " ilinde doğdum.";
        return profil;
    }

    public String getIsim() {
        return isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public char getCinsiyet() {
        return cinsiyet;
    }

    public void setCinsiyet(char cinsiyet) {
        this.cinsiyet = cinsiyet;
    }

    public String getDogumTarihi() {
        return dogumTarihi;
    }

    public void setDogumTarihi(String dogumTarihi) {
        this.dogumTarihi = dogumTarihi;
    }

    public String getDogumYeri() {
        return dogumYeri;
    }

    public void setDogumYeri(String dogumYeri) {
        this.dogumYeri = dogumYeri;
    }

    public float getBoy() {
        return boy;
    }

    public void setBoy(float boy) {
        this.boy = boy;
    }

    public float getKilo() {
        return kilo;
    }

    public void setKilo(float kilo) {
        this.kilo = kilo;
    }

    public int getSporcuNo() {
        return sporcuNo;
    }

    public void setSporcuNo(int sporcuNo) {
        this.sporcuNo = sporcuNo;
    }  
}
