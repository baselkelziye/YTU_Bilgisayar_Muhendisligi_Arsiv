package uyg2;

public class Test {
    
    public static void main(String[] args) {
        
        
        System.out.println(Kitap.isbnNedir());
        
        
        Kitap kitap1 = new Kitap("Kitap1","Yazar1","1234");
        Kitap kitap2 = new Kitap("Kitap2","Yazar2","1235");
        Kitap kitap3 = new Kitap("Kitap3","Yazar3","1236");
//        System.out.println(kitap1);
//        kitap1.setAd("Kitap2");
//        System.out.println(kitap1);
//        System.out.println(kitap1.isbnNedir());
//        System.out.println(Kitap.getkitapSayiyi());
        
//        Raf raf1 = new Raf(); //bu ÅŸekilde de raf nesnesini oluÅŸturabilirdik ancak tasarÄ±m gereÄŸi kitaplÄ±k nesnesi iÃ§erisinde oluÅŸturulmasÄ±nÄ± istedik.
//        raf1.kitapEkle(kitap1);
//        raf1.kitapEkle(kitap2);
//        raf1.kitapEkle(kitap3);
//        raf1.rafGoster();
//        raf1.kitapSil(1);
//        raf1.kitapSil(kitap3);
//        raf1.rafGoster();
        Kitap kitap4 = new Kitap("Kitap4","Yazar4","1237");
        Kitap kitap5 = new Kitap("Kitap5","Yazar5","1238");
        Kitap kitap6 = new Kitap("Kitap6","Yazar6","1239");
        
        Kitaplık kitaplık = new Kitaplık(5);
        
        kitaplık.kitapEkle(kitap3, 0);
        kitaplık.kitapEkle(kitap1, 0);
        kitaplık.kitapEkle(kitap2, 0);
        
        kitaplık.kitapEkle(kitap4, 1);
        kitaplık.kitapEkle(kitap5, 1);
        kitaplık.kitapEkle(kitap6, 2);


        
        
//        kitaplÄ±k.tumRaflariGoster();
        
//        kitaplÄ±k.kitapSil(0, kitap1);
//        kitaplÄ±k.kitapSil(1, 1);
        
        kitaplık.tumRaflariGoster();
        
        System.out.println("----- Uyg2 -----");

        kitaplık.kitapEkle(kitap3, 0);
        kitaplık.kitapEkle(kitap1, 0);
        kitaplık.kitapEkle(kitap2, 0);
        
        kitaplık.kitapEkle(kitap4, 1);
        kitaplık.kitapEkle(kitap5, 1);
        kitaplık.kitapEkle(kitap6, 2);
        
        
        
        KitaplıkYonetim kitaplıkYonetim = new KitaplıkYonetim(kitaplık);
        
     
        
        Kart kart1 = new OgrenciKartı(0,"Ali",50);
//        OgrenciKartÄ± kart1 = new OgrenciKartÄ±(0,"Ali",50);
        
        
        Kart kart2 = new YetiskinKartı(1,"AyÅŸe",50);
//        YetiskinKartÄ± kart2 = new YetiskinKartÄ±(1,"AyÅŸe",50);
      
        
        System.out.println(kart1);
        System.out.println(kart2);
    
        
        kitaplıkYonetim.kitapSat(kitap1, kart1);
        kitaplıkYonetim.kitapSat(kitap2, kart1);
        kitaplıkYonetim.kitapSat(kitap3, kart1);
        kitaplıkYonetim.kitapSat(kitap4, kart1);
        kitaplıkYonetim.kitapSat(kitap5, kart1);
        System.out.println(kart1);
        kitaplıkYonetim.kitapSat(kitap6, kart1);
        System.out.println(kart1);
        
        System.out.println("********************");
        
        kitaplıkYonetim.kitapSat(kitap1, kart2);
        kitaplıkYonetim.kitapSat(kitap2, kart2);
        kitaplıkYonetim.kitapSat(kitap3, kart2);
        kitaplıkYonetim.kitapSat(kitap4, kart2);
        kitaplıkYonetim.kitapSat(kitap5, kart2);
        System.out.println(kart2);
        kitaplıkYonetim.kitapSat(kitap6, kart2);

        //kitaplÄ±k.tumRaflariGoster();

        


    }
    
}
