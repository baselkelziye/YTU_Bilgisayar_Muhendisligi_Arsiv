package abstraction;
class TicariHesap extends Hesap {
    private double krediLimiti;

    public TicariHesap(int hesapNo, double krediLimiti) {
        super(hesapNo);
        this.krediLimiti = krediLimiti;
    }

    

    @Override
    public void paraCek(double tutar) {
        if (tutar > 0 && tutar <= (bakiye + krediLimiti)) {
            bakiye -= tutar;
            System.out.println(tutar + " TL çekildi. Yeni bakiye: " + bakiye + " (Kredi dahil bakiye sınır: " + krediLimiti + ")");
        } else {
            System.out.println("Yetersiz bakiye ve kredi limiti veya geçersiz tutar.");
        }
    }

    @Override
    public void bilgiGoster() {
        System.out.println("Ticari Hesap Detayları:");
        System.out.println("Hesap No: " + hesapNo);
        System.out.println("Bakiye: " + bakiye + " TL");
        if (bakiye < 0) {
            System.out.println("Kullanılan Kredi: " + bakiye + " TL");
            System.out.println("Kalan Kredi Limiti: " + (krediLimiti - bakiye) + " TL");
        } else {
            System.out.println("Kullanılabilir Kredi Limiti: " + krediLimiti + " TL");
        }
    }
    
}
