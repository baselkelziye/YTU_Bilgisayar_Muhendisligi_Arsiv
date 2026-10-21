package uyg2;

public class Kitap {
    
    private String Ad;
    private String Yazar;
    private final String ISBN;
    private static int kitapSayiyi;
    private double fiyat;

    public Kitap(String Ad, String Yazar, String ISBN) {
        this.Ad = Ad;
        this.Yazar = Yazar;
        this.ISBN = ISBN;
        kitapSayiyi++;
        this.fiyat = 10.0;
    }

    public double getFiyat() {
        return fiyat;
    }

    public void setFiyat(double fiyat) {
        this.fiyat = fiyat;
    }

    public String getAd() {
        return Ad;
    }

    public void setAd(String Ad) {
        this.Ad = Ad;
    }

    public String getYazar() {
        return Yazar;
    }

    public void setYazar(String Yazar) {
        this.Yazar = Yazar;
    }

    public static int getKitapSayiyi() {
        return kitapSayiyi;
    }
    
    public static int getkitapSayiyi(){
        return kitapSayiyi;
    }

    public String getISBN() {
        return ISBN;
    }
    
    public static String isbnNedir(){
        String s = "isbn kitapları ayırt etmek için eşşiz bir numaradır";
        return s;
    }

    @Override
    public String toString() {
        return "Kitap{" + "Ad=" + Ad + ", Yazar=" + Yazar + ", ISBN=" + ISBN + '}';
    }
    
    
    
}
