package nyp5;

public class UzunAtlamaAtleti extends MilliSporcu{
    private String atletizmeBaslamaTarihi;
    private float maxMesafe;
    private int katildigiYarismaSayisi;

    public UzunAtlamaAtleti(String isim, char cinsiyet, String dogumTarihi, int sporcuNo) {
        super(isim, cinsiyet, dogumTarihi, sporcuNo);
    }
    
    public String SporcuProfili(){
        String profil;
        profil = "Merhaba ben " + super.sporcuNo + " nolu Milli Atletim. " +
                "Atletizme " + this.atletizmeBaslamaTarihi + " tarihinde başladım." +
                " Toplam " + this.katildigiYarismaSayisi + " adet yarışmaya katıldım " +
                "ve maksimum " + this.maxMesafe + " uzaklığa atladım.";
        return profil;
    }

    public String getAtletizmeBaslamaTarihi() {
        return atletizmeBaslamaTarihi;
    }

    public void setAtletizmeBaslamaTarihi(String atletizmeBaslamaTarihi) {
        this.atletizmeBaslamaTarihi = atletizmeBaslamaTarihi;
    }

    public float getMaxMesafe() {
        return maxMesafe;
    }

    public void setMaxMesafe(float maxMesafe) {
        this.maxMesafe = maxMesafe;
    }

    public int getKatildigiYarismaSayisi() {
        return katildigiYarismaSayisi;
    }

    public void setKatildigiYarismaSayisi(int katildigiYarismaSayisi) {
        this.katildigiYarismaSayisi = katildigiYarismaSayisi;
    }
    
    
}
