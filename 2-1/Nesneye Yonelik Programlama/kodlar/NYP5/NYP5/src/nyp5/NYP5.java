package nyp5;

public class NYP5 {
    public static void main(String[] args){
        Yuzucu yuzucu1 = new Yuzucu("Serbest Stile Uygun", "Nezir Karap", 'E', "1992-01-01", 1);
        yuzucu1.setBoy(183);
        yuzucu1.setKilo(77);
        yuzucu1.setYuzmeSaati(3000);
        yuzucu1.setYuzmeSekli("Serbest Stil");
        yuzucu1.setDogumYeri("Trabzon");
        
        Yuzucu yuzucu2 = new Yuzucu("Kelebek Stile Uygun", "Alpkan Örnek", 'E', "1993-01-01", 2);
        yuzucu2.setBoy(163);
        yuzucu2.setKilo(57);
        yuzucu2.setYuzmeSaati(2000);
        yuzucu2.setYuzmeSekli("Kelebek Stil");
        yuzucu2.setDogumYeri("Muğla");
        
        Guresci guresci1 = new Guresci("57 Kilo", 1000, "Seyhan Atlı", 'K', "1991-01-01", 5);
        guresci1.setBeraberlik(12);
        guresci1.setGalibiyet(124);
        guresci1.setMalubiyet(5);
        guresci1.setBoy(176);
        guresci1.setDogumYeri("Yozgat");
        guresci1.setKilo(57);
        
        Guresci guresci2 = new Guresci("130 Kilo", 2000, "Rıza Kayaalp", 'E', "1990-01-01", 6);
        guresci2.setBeraberlik(1);
        guresci2.setGalibiyet(1245);
        guresci2.setMalubiyet(17);
        guresci2.setBoy(185);
        guresci2.setDogumYeri("Ordu");
        guresci2.setKilo(130);
        
        
        UzunAtlamaAtleti atlet1 = new UzunAtlamaAtleti("Necati Er", 'E', "1987-01-01", 9);
        atlet1.setAtletizmeBaslamaTarihi("2015-01-01");
        atlet1.setBoy(167);
        atlet1.setDogumYeri("Edirne");
        atlet1.setKatildigiYarismaSayisi(156);
        atlet1.setMaxMesafe(8);
        atlet1.setKilo(68);
        
        UzunAtlamaAtleti atlet2 = new UzunAtlamaAtleti("Elif Zengin", 'K', "1985-01-01", 11);
        atlet2.setAtletizmeBaslamaTarihi("2013-01-01");
        atlet2.setBoy(157);
        atlet2.setDogumYeri("Sinop");
        atlet2.setKatildigiYarismaSayisi(126);
        atlet2.setMaxMesafe(7);
        atlet2.setKilo(64);
        
        Kafile kafilem = new Kafile("Tokyo Olimpiyatları", "Engin Gökdeniz");
        kafilem.setYarismaUlkesi("Japonya");
        System.out.println(kafilem.KafileyeSporcuEkle(yuzucu1));
        System.out.println(kafilem.KafileyeSporcuEkle(yuzucu2));
        System.out.println(kafilem.KafileyeSporcuEkle(guresci1));
        System.out.println(kafilem.KafileyeSporcuEkle(guresci2));
        System.out.println(kafilem.KafileyeSporcuEkle(atlet1));
        System.out.println(kafilem.KafileyeSporcuEkle(atlet2));
        
        System.out.println("Kafiledeki Toplam Kadın Sayısı: " + kafilem.getKadinSayisi());
	System.out.println("Kafiledeki Toplam Erkek Sayısı: " + kafilem.getErkekSayisi());
        System.out.println(kafilem.KafileProfili());
        
        System.out.println(kafilem.getMilliSporcu(11).SporcuProfili());
        System.out.println(kafilem.getMilliSporcu(1).SporcuProfili());
        System.out.println(kafilem.getMilliSporcu(5).SporcuProfili());
        
        //super(kafilem.getMilliSporcu(2)).SporcuProfili();
        //Yuzucu yz = new MilliSporcu("Çağatay", 'E', "2000-01-01", 12);
       
    }
}
