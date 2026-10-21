package lab2;

public class NormalKisi extends Kisi{

	public NormalKisi(String ad, int id, double bakiye) {
		super(ad, id, bakiye);
	}

	@Override
	public boolean odemeYap(double odeme) {
		if(getBakiye() >= odeme) {
			setBakiye(getBakiye() - odeme);
			return true;
		}
		return false;
	}
	
}
