package lab2_a;

public class NormalKisi extends Kisi {

	public NormalKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	@Override
	public boolean odemeYap(double ucret) {
		if (getBakiye() >= ucret) {
			System.out.println("Bakiyenizden düşüm gerçekleşti");
			setBakiye(getBakiye() - ucret);
			return true;
		}
		return false;

	}

}
