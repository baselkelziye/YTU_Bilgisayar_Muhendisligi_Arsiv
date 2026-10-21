package lab2;

public class Sandalye {
	private int no;
	private boolean doluluk;
	private final int ucret;
	public Sandalye(int no) {
		this.no = no;
		ucret = 15;
	}
	
	@Override
	public String toString() {
		return "Sandalye [no=" + no + ", doluluk=" + doluluk + ", ucret=" + ucret + "]";
	}

	public int getNo() {
		return no;
	}

	public boolean isDoluluk() {
		return doluluk;
	}

	public void setDoluluk(boolean doluluk) {
		this.doluluk = doluluk;
	}

	public int getUcret() {
		return ucret;
	}
	
	
}
