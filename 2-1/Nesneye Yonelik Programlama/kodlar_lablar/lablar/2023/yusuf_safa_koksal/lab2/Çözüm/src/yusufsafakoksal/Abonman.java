package yusufsafakoksal;

public class Abonman extends Kisi{
	private int kredi;
	
	public Abonman(String ad, int id, double bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi=kredi;
	}

	@Override
	public boolean odemeYap(double amount) {
		if(kredi>=5) {
			kredi-=5;
			System.out.println("Giris hakkindan dusum gerceklesti");
			return true;
		}
		else if(amount<=this.bakiye){
			bakiye-=amount;
			kredi++;
			System.out.println("Bakiyenizden dusum gerceklesti");
			return true;
		}
		System.out.println("Bakiye yetersiz");
		return false;
	}

	@Override
	public String toString() {
		return "Kisi[ad="+this.ad+", id="+this.id+", bakiye="+this.bakiye+"] Abonman [girisHakki="+this.kredi+"]";
	}
	
	
}
