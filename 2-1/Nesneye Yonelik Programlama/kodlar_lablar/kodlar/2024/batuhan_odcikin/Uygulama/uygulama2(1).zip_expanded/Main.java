public class Main {
    public static void main(String[] args) {
        // Bireysel hesap oluştur
    	int bireyselHesapNo = 1001;
    	String sifre = "1234";
    	double gunlukLimit = 1000;
        BireyselHesap bireysel = new BireyselHesap(bireyselHesapNo, sifre, gunlukLimit);
        
        bireysel.bilgiGoster();
        bireysel.paraYatir(2000);
        bireysel.paraCek(500, "1234");
        bireysel.paraCek(1500, "0000"); // Hatalı şifre
        bireysel.paraCek(1000, "1234"); // Günlük limit aşımı
        bireysel.gunlukLimitSifirla();
        bireysel.paraCek(1000, "1234");
        System.out.println();

        // Ticari hesap oluştur
        int ticariHesapNo = 2001;
        double limit = 5000;
        TicariHesap ticari = new TicariHesap(ticariHesapNo, limit);
        ticari.bilgiGoster();
        ticari.paraYatir(10000);
        ticari.paraCek(12000); // Krediden çekme
        ticari.paraCek(5000);  // Kredi limiti biter
        System.out.println();

        ticari.bilgiGoster();
    }
}