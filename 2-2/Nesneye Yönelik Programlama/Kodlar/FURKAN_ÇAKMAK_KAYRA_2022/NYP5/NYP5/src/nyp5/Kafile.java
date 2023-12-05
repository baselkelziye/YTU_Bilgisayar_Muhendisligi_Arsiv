package nyp5;

import java.util.ArrayList;

public class Kafile {
    private String katilinanYarisma;
    private ArrayList<MilliSporcu> milliler;
    private String kafileBaskani;
    private String yarismaUlkesi;
    private int erkekSayisi;
    private int kadinSayisi;

    public Kafile(String katilinanYarisma, String kafileBaskani) {
        this.katilinanYarisma = katilinanYarisma;
        this.kafileBaskani = kafileBaskani;
        milliler = new ArrayList<MilliSporcu>();
        erkekSayisi = 0;
        kadinSayisi = 0; 
    }
    
    public String KafileyeSporcuEkle(MilliSporcu ms){
        int i = 0;
        while(i < this.milliler.size() && ms.getSporcuNo() != this.milliler.get(i).getSporcuNo())
            i++;
        
        if(i == this.milliler.size()){
            milliler.add(ms);
            if(ms.getCinsiyet() == 'E')
                erkekSayisi++;
            else
                kadinSayisi++;
            return ms.getSporcuNo() + " nolu sporcu eklendi !!!";
        }else{
            return ms.getSporcuNo() + " nolu sporcu zaten var !!!";
        } 
    }
    
    public String KafileProfili(){
        String profil = "";
        profil = profil + "Kafile Başkanı: " + this.kafileBaskani + "\n";
        profil = profil + "Katılınan Yarışma: " + this.katilinanYarisma + "\n";
        profil = profil + "Kadın Sayısı: " + this.kadinSayisi + "\n";
        profil = profil + "Erkek Sayısı: " + this.erkekSayisi + "\n";
        return profil;
    }
    
    public MilliSporcu getMilliSporcu(int s_no){
        for (MilliSporcu msler : milliler) {
            if(msler.getSporcuNo() == s_no)
                return msler;
        }
        return null;
    }

    public String getKatilinanYarisma() {
        return katilinanYarisma;
    }

    public void setKatilinanYarisma(String katilinanYarisma) {
        this.katilinanYarisma = katilinanYarisma;
    }

    public String getKafileBaskani() {
        return kafileBaskani;
    }

    public void setKafileBaskani(String kafileBaskani) {
        this.kafileBaskani = kafileBaskani;
    }

    public String getYarismaUlkesi() {
        return yarismaUlkesi;
    }

    public void setYarismaUlkesi(String yarismaUlkesi) {
        this.yarismaUlkesi = yarismaUlkesi;
    }

    public int getErkekSayisi() {
        return erkekSayisi;
    }

    public void setErkekSayisi(int erkekSayisi) {
        this.erkekSayisi = erkekSayisi;
    }

    public int getKadinSayisi() {
        return kadinSayisi;
    }

    public void setKadinSayisi(int kadinSayisi) {
        this.kadinSayisi = kadinSayisi;
    }

}