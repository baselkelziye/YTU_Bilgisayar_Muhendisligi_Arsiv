package yusufsafakoksal;

public class Sandalye {
	private int no;
	private boolean doluluk;
	private final int ucret;
	
	public Sandalye(int no) {
		this.no = no;
		this.doluluk = false;
		this.ucret=15;
	}
	
	public int getNo() {
		return no;
	}

	public int getUcret() {
		return ucret;
	}

	public boolean isDoluluk() {
		return doluluk;
	}
	
	public void setDoluluk(boolean doluluk) {
		this.doluluk = doluluk;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString();
	}
}
