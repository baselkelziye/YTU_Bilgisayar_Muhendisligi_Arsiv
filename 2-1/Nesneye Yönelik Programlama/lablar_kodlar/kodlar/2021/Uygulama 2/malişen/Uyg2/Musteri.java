/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication5;

/**
 *
 * @author Toprak
 */
public class Musteri {

    private int Id;
    private String Ad;
    private Sepet sepet;

    public Musteri(int Id, String Ad) {
        this.Id = Id;
        this.Ad = Ad;
        this.sepet = new Sepet();
    }

    public int getId() {
        return Id;
    }

    public void setId(int Id) {
        this.Id = Id;
    }

    public String getAd() {
        return Ad;
    }

    public void setAd(String Ad) {
        this.Ad = Ad;
    }

    public Sepet getSepet() {
        return sepet;
    }

    public void setSepet(Sepet sepet) {
        this.sepet = sepet;
    }

    public void sepeteEkle(Urun u) {
        getSepet().SepeteEkle(u);
    }

    public void SepettenSil(Urun u) {
        getSepet().SepettenSil(u);
    }

    public void SepettenSil(int i) {
        getSepet().SepettenSil(i);
    }
    
    public void SepetiBosalt()
    {
        getSepet().sepetiBosalt();
    }
    
    public boolean SatinAl(Kart k)
    {
        if (k.odemeYap(getSepet().getToplam()))
        {
            SepetiBosalt();
            System.out.println("Odeme Basarili");
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "Musteri{" + "Id=" + Id + ", Ad=" + Ad + ", sepet=" + sepet + '}';
    }
 
    
    
}
