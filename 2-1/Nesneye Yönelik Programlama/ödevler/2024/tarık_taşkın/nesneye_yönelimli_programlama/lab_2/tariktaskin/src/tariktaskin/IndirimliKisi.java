package tariktaskin;
//toString
public class IndirimliKisi extends Kisi{
	private int kredi;
	
	public IndirimliKisi(String ad, int id, double bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi = kredi;
	}

	@Override
	public boolean odemeYap(int durakSayisi) {
		int tutar = birimUcret * durakSayisi;
		System.out.println("Odemeniz gereken tutar:"+tutar);
		if(kredi>=tutar) {
			kredi-= tutar;
			System.out.println("Krediden dusum gerceklesti");
			return true;
		}
		else if(bakiye>= tutar) {
			bakiye -= tutar;
			kredi += durakSayisi;
			System.out.println("Bakiyeden dusum gerceklesti");
			return true;
		}
		else {
			System.out.println("Bakiye yetersiz");
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
		return super.toString() + "IndirimliKisi [kredi=" + kredi +"]";
	}
	
}
