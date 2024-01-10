/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication5;

/**
 *
 * @author Toprak
 */
public class Urun {
    
    private String Ad;
    private double Fiyat;

    public Urun(String Ad, double Fiyat) {
        this.Ad = Ad;
        this.Fiyat = Fiyat;
    }

    public String getAd() {
        return Ad;
    }

    public void setAd(String Ad) {
        this.Ad = Ad;
    }

    public double getFiyat() {
        return Fiyat;
    }

    public void setFiyat(double Fiyat) {
        this.Fiyat = Fiyat;
    }

    @Override
    public String toString() {
        return "Urun{" + "Ad=" + Ad + ", Fiyat=" + Fiyat + '}';
    }
    
    
    
    
    
}
