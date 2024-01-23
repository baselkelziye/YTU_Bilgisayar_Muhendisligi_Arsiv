
package javaapplication5;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        BankKart k1 = new BankKart(1, "Ali", 100);
        KrediKart k2 = new KrediKart(2, "Ayse",100);
        GencKart k3 = new GencKart(3,"Veli",100);
        
        System.out.println(k1);
        ArrayList<Kart> kartlar = new ArrayList<Kart>();
        kartlar.add(k1);
        kartlar.add(k2);
        kartlar.add(k3);
        
//        kartKontrol(kartlar);
        
        
        System.out.println(k2);
        k2.odemeYap(100);
        System.out.println(k2);
        k2.odemeYap(9);
        System.out.println(k2);
        
        
//        k2.odemeYap(1200);
//        System.out.println(k2);
        
//        
//        k1.paraGonder(k2, 50);
//        System.out.println(k2.toString());
        // System.out.println(k2.getBakiye());
        
    }
    
    public static void kartKontrol(ArrayList<Kart> kartlar)
    {
        for (Kart k : kartlar)
        {
            System.out.println(k);
        }
    }
    
}
