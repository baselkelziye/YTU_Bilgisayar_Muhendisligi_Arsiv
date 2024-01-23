/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication5;

import java.util.ArrayList;

/**
 *
 * @author Toprak
 */
public class Sepet {

    private ArrayList<Urun> Urunler;
    private double Toplam;

    public Sepet() {
        this.Urunler = new ArrayList<Urun>();
        this.Toplam = 0;
    }

    public double getToplam() {
        return Toplam;
    }

    public void setToplam(double Toplam) {
        this.Toplam = Toplam;
    }

    public void SepeteEkle(Urun u) {
        Urunler.add(u);
        setToplam(getToplam() + u.getFiyat());
    }

    public void SepettenSil(Urun u) {
        if (Urunler.contains(u))
        {
            setToplam(getToplam() - u.getFiyat());
            Urunler.remove(u);
            
        }
    }
    
    public void SepettenSil(int i)
    {
        if (Urunler.size() > i)
        {
            setToplam(getToplam() - Urunler.get(i).getFiyat());
            Urunler.remove(i);
        }
        
    }
    
    public void sepetiBosalt()
    {
        Urunler.clear();
        this.Toplam = 0;
    }

    @Override
    public String toString() {
        return "Sepet{" + "Urunler=" + Urunler + ", Toplam=" + Toplam + '}';
    }
    
    
    
}
