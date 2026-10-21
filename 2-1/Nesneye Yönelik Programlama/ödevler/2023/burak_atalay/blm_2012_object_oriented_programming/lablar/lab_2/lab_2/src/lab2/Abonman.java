package lab2;

public class Abonman extends Kisi{
	private int kredi;
	public Abonman(String ad, int id, double bakiye, int kredi) {
		super(ad, id, bakiye);
		this.kredi = kredi;
	}

	@Override
	public boolean odemeYap(double odeme) {
		if(kredi >= 5) {
			kredi -= 5;
			return true;
		}
		else if(getBakiye() >= odeme) {
			setBakiye(getBakiye()-odeme);
			kredi++;
			return true;
		}
		return false;
	}

	public int getKredi() {
		return kredi;
	}

	public void setKredi(int kredi) {
		this.kredi = kredi;
	}

	@Override
	public String toString() {
		return super.toString() + "Abonman [girisHakki=" + kredi + "]";
	}
	
	

}
