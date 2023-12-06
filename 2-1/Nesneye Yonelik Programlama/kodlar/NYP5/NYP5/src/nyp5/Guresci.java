package nyp5;

public class Guresci extends MilliSporcu{
    private String siklet;
    private int toplamSaat;
    private int galibiyet;
    private int beraberlik;
    private int malubiyet;

    public Guresci(String siklet, int toplamSaat, String isim, char cinsiyet, String dogumTarihi, int sporcuNo) {
        super(isim, cinsiyet, dogumTarihi, sporcuNo);
        this.siklet = siklet;
        this.toplamSaat = toplamSaat;
    }
    
    public String SporcuProfili(){
        String profil;
        profil = "Merhaba ben " + super.sporcuNo + " nolu Milli Güreşçiyim. " +
                this.siklet + " sikletinde güreşiyorum. Toplam " + this.galibiyet +
                " galibiyetim var.";
        return profil;
    }

    public String getSiklet() {
        return siklet;
    }

    public void setSiklet(String siklet) {
        this.siklet = siklet;
    }

    public int getToplamSaat() {
        return toplamSaat;
    }

    public void setToplamSaat(int toplamSaat) {
        this.toplamSaat = toplamSaat;
    }

    public int getGalibiyet() {
        return galibiyet;
    }

    public void setGalibiyet(int galibiyet) {
        this.galibiyet = galibiyet;
    }

    public int getBeraberlik() {
        return beraberlik;
    }

    public void setBeraberlik(int beraberlik) {
        this.beraberlik = beraberlik;
    }

    public int getMalubiyet() {
        return malubiyet;
    }

    public void setMalubiyet(int malubiyet) {
        this.malubiyet = malubiyet;
    }
    
    
}
