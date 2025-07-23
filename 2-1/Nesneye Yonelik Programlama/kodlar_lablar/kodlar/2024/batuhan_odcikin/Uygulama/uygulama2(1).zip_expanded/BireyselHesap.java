

class BireyselHesap extends Hesap {
    private String sifre;
    private double gunlukCekimLimiti;
    private double bugunCekilenMiktar; // Günlük çekilen toplam tutar

    public BireyselHesap(int hesapNo, String sifre, double gunlukCekimLimiti) {
        super(hesapNo);
        this.sifre = sifre;
        this.gunlukCekimLimiti = gunlukCekimLimiti;
        this.bugunCekilenMiktar = 0;
    }
    
    

    @Override
	public void paraCek(double tutar) {
		// TODO Auto-generated method stub
		super.paraCek(tutar);
	}



	public void paraCek(double tutar, String girilenSifre) {
        if (!girilenSifre.equals(sifre)) {
            System.out.println("Hatalı şifre! İşlem iptal edildi.");
        } else if (tutar <= 0) {
            System.out.println("Hatalı tutar! Girilen tutar pozitif olmalı.");
        } else if (bugunCekilenMiktar + tutar > gunlukCekimLimiti) {
            System.out.println("Günlük çekim limiti aşıldı! Limit: " + gunlukCekimLimiti + ", Bugün çekilen: " + bugunCekilenMiktar);
        } else if (tutar <= bakiye) {
            bakiye -= tutar;
            bugunCekilenMiktar += tutar;
            System.out.println(tutar + " TL çekildi. Bugün toplam çekim: " + bugunCekilenMiktar + " TL. Yeni bakiye: " + bakiye);
        } else {
            System.out.println("Yetersiz bakiye.");
        }
    }

    

    public void gunlukLimitSifirla() {
        bugunCekilenMiktar = 0;
        System.out.println("Günlük çekim limiti sıfırlandı.");
    }

    @Override
    public void bilgiGoster() {
        System.out.println("Bireysel Hesap Detayları:");
        System.out.println("Hesap No: " + hesapNo);
        System.out.println("Bakiye: " + bakiye + " TL");
        System.out.println("Günlük Çekim Limiti: " + gunlukCekimLimiti + " TL");
        System.out.println("Bugün Çekilen: " + bugunCekilenMiktar + " TL");
    }
}
