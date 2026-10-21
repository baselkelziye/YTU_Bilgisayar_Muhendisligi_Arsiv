package tariktaskin;
//toString
public class AnonimKisi extends Kisi{

	public AnonimKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	@Override
	public boolean odemeYap(int durakSayisi) {
		int tutar = birimUcret * durakSayisi;
		System.out.println("Odemeniz gereken tutar:"+tutar);
		if(bakiye>= tutar) {
			bakiye -= tutar;
			System.out.println("Odeme gerceklesti");
			return true;
		}
		else {
			System.out.println("Bakiye yetersiz");
			return false;
		}
		
	}
	
}
