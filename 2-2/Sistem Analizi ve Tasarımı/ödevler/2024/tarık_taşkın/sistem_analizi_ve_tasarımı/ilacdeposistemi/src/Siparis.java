
public class Siparis {
    
    private String eczaneismi;
    private int eczaneno;
    private int siparisno;
    private String siparis;
    private String tutar;
    private String tamamlandi;

    public Siparis(String eczaneismi, int eczaneno, int siparisno, String siparis, String tutar, String tamamlandi) {
        this.eczaneismi = eczaneismi;
        this.eczaneno = eczaneno;
        this.siparisno = siparisno;
        this.siparis = siparis;
        this.tutar = tutar;
        this.tamamlandi = tamamlandi;
        
        
    }

    public String getEczaneismi() {
        return eczaneismi;
    }

    public void setEczaneismi(String eczaneismi) {
        this.eczaneismi = eczaneismi;
    }

    public int getEczaneno() {
        return eczaneno;
    }

    public void setEczaneno(int eczaneno) {
        this.eczaneno = eczaneno;
    }

    public int getSiparisno() {
        return siparisno;
    }

    public void setSiparisno(int siparisno) {
        this.siparisno = siparisno;
    }

    public String getSiparis() {
        return siparis;
    }

    public void setSiparis(String siparis) {
        this.siparis = siparis;
    }

    public String getTutar() {
        return tutar;
    }

    public void setTutar(String tutar) {
        this.tutar = tutar;
    }

    public String getTamamlandi() {
        return tamamlandi;
    }

    public void setTamamlandi(String tamamlandi) {
        this.tamamlandi = tamamlandi;
    }
    
    
    
    
    
    
    
    
    
    
}
