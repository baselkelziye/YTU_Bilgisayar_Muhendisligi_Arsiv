package nyp5;

public class Yuzucu extends MilliSporcu{
    private String kasProfili;
    private String yuzmeSekli;
    int yuzmeSaati;

    public Yuzucu(String kasProfili, String isim, char cinsiyet, String dogumTarihi, int sporcuNo) {
        super(isim, cinsiyet, dogumTarihi, sporcuNo);
        this.kasProfili = kasProfili;
    }
    
    public String SporcuProfili(){
        String profil;
        profil = "Merhaba ben " + super.sporcuNo + " nolu Milki Sporcuyum." +
                "Toplam " + yuzmeSaati + " saat yüzdüm.";
        return profil;
    }

    public String getKasProfili() {
        return kasProfili;
    }

    public void setKasProfili(String kasProfili) {
        this.kasProfili = kasProfili;
    }

    public String getYuzmeSekli() {
        return yuzmeSekli;
    }

    public void setYuzmeSekli(String yuzmeSekli) {
        this.yuzmeSekli = yuzmeSekli;
    }

    public int getYuzmeSaati() {
        return yuzmeSaati;
    }

    public void setYuzmeSaati(int yuzmeSaati) {
        this.yuzmeSaati = yuzmeSaati;
    }
}
