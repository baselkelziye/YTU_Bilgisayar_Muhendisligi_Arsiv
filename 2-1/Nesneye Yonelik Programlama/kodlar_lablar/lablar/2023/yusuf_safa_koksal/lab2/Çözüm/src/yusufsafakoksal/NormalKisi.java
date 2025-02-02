package yusufsafakoksal;

public class NormalKisi extends Kisi {

	public NormalKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	@Override
	public boolean odemeYap(double amount) {
		if(amount<=this.bakiye) {
			this.bakiye-=amount;
			System.out.println("Bakiyenizden dusum gerceklesti");
			return true;
		}
		System.out.println("Bakiye yetersiz");
		return false;
	}
}
