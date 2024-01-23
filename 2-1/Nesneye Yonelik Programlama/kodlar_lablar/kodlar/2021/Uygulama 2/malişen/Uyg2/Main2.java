/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package javaapplication5;

/**
 *
 * @author Toprak
 */
public class Main2 {

    public static void main(String[] args) {

        Urun u1 = new Urun("Yag", 600);
        Urun u2 = new Urun("Laptop", 15000);
        Urun u3 = new Urun("Karton Bardak", 1);
        Musteri m1 = new Musteri(1,"Ali");
        Kart k1 = new KrediKart(1,"Ali",1000,20000);
        
        m1.sepeteEkle(u1);
        m1.sepeteEkle(u2);
        m1.sepeteEkle(u3);
        
        System.out.println(m1);
        m1.SatinAl(k1);
        System.out.println(m1);
        System.out.println(k1);
        
    }

}
