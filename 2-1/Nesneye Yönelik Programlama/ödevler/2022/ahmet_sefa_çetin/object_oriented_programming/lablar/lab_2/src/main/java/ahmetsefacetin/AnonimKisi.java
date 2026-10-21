package ahmetsefacetin;

public class AnonimKisi extends Kisi {

    public AnonimKisi(String ad, int id, double bakiye) {
        super(ad, id, bakiye);
    }

    @Override
    public boolean odemeYap(int durakSayisi) {
        if (getBakiye() >= getBirimUcret()) {
            setBakiye(getBakiye() - getBirimUcret() * durakSayisi);
            System.out.println("Ödeme gerçekleşti.");
            return true;
        }
        else {
            System.out.println("Bakiye Yetersiz");
            return false;
        }
        
    }

}
