
public class Hesap {
    protected int hesapNo;
    protected double bakiye;

    public Hesap(int hesapNo) {
        this.hesapNo = hesapNo;
        this.bakiye = 0; // Bakiye başlangıç değeri 0
    }
    
    public Hesap(int hesapNo, double bakiye) {
        this.hesapNo = hesapNo;
        this.bakiye = bakiye;
    }
    
    public void paraYatir(double tutar) {
        if (tutar > 0) {
            bakiye += tutar;
            System.out.println(tutar + " TL yatırıldı. Yeni bakiye: " + bakiye);
        } else {
            System.out.println("Geçersiz tutar: " + tutar);
        }
    }

    public void paraCek(double tutar) {
        if (tutar > 0 && tutar <= bakiye) {
            bakiye -= tutar;
            System.out.println(tutar + " TL çekildi. Yeni bakiye: " + bakiye);
        } else {
            System.out.println("Yetersiz bakiye veya geçersiz tutar.");
        }
    }

    public void bilgiGoster() {
        System.out.println("Hesap No: " + hesapNo + ", Bakiye: " + bakiye);
    }
}
