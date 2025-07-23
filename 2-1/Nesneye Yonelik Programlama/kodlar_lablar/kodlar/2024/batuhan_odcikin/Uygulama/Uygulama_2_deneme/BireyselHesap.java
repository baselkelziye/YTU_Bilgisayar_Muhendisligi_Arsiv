package uyg2;

public class BireyselHesap extends Hesap{

	private String sifre;
	private double gunlukCekimLimiti;
	private double bugunCekilenMiktar;
	
	public BireyselHesap (int hesapNo, String sifre, double gunlukCekimLimiti) {
		super(hesapNo,0);
		this.sifre = sifre;
		this.gunlukCekimLimiti = gunlukCekimLimiti;
	}
	
	public void paraYatir(double para, String sifre) {
		if(sifre.equals(this.sifre) == true) {
			bakiye += para; 
			System.out.println(para + " TL hesaba yatırıldı. Yeni bakiye: " + bakiye);
		}
		else {
			System.out.println("Para yatirma islemi icin Sifre Hatali !!");
		}
	}
	
	public void paraCek(double para, String sifre) {
		if(sifre.equals(this.sifre) == true) {
			if (gunlukCekimLimiti >= bugunCekilenMiktar - para) {
				bugunCekilenMiktar += para;
				bakiye -= para;
				System.out.println(para + " TL hesaptan çekildi. Bugün çekilen miktar:" + bugunCekilenMiktar + " Yeni bakiye: " + bakiye);
			}
			else {
				System.out.println("Para cekme islemi icin Cekme Limiti yetersiz !!");
			}
		}
		else {
			System.out.println("Para cekme islemi icin Sifre Hatali !!");
		}
	}

	public void bilgiGoster() {
		System.out.println("Bireysel Hesap Detayları:");
        System.out.println("Hesap No: " + hesapNo);
        System.out.println("Bakiye: " + bakiye + " TL");
        System.out.println("Günlük Çekim Limiti: " + gunlukCekimLimiti + " TL");
        System.out.println("Bugün Çekilen: " + bugunCekilenMiktar + " TL");
	}
	
	public void gunlukLimitiSifirla() {
		bugunCekilenMiktar = 0;
		System.out.println("Gunluk limit sıfırlandı! ");
	}
	
}
