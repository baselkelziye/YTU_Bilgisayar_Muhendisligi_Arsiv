package lab2_a;

public class Sandalye {
	private int no;
	private boolean doluluk;
	private final int ucret;

	public Sandalye(int no) {
		this.no = no;
		ucret= 15;
	}

	public int getNo() {
		return no;
	}

	public void setNo(int no) {
		this.no = no;
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

	@Override
	public String toString() {
		return "Sandalye [no=" + no + ", doluluk=" + doluluk + "]";
	}

	

}
