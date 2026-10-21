package ahmetsefacetin;

public class IndirimliKisi extends Kisi {

    private int kredi;

    public IndirimliKisi(String ad, int id, double bakiye, int kredi) {
        super(ad, id, bakiye);
        this.kredi = kredi;
    }

    @Override
    public boolean odemeYap(int durakSayisi) {
        if (kredi >= getBirimUcret()) {
            setKredi(getKredi() - getBirimUcret() * durakSayisi);
            System.out.println("Krediden düşüm gerçekleşti.");
            return true;
        } else if (getBakiye() >= getBirimUcret()) {
            setBakiye(getBakiye() - getBirimUcret() * durakSayisi);
            kredi += durakSayisi;
            System.out.println("Bakiyeden düşüm gerçekleşti.");
            return true;
        }
        else {
            System.out.println("Bakiye Yetersiz");
            return false;
        }
        
    }

    public int getKredi() {
        return kredi;
    }

    public void setKredi(int kredi) {
        this.kredi = kredi;
    }

    @Override
    public String toString() {
        return super.toString() + " IndirimliKisi[kredi=" + kredi + "]";
    }

}
