package uyg2;

public abstract class Hesap {

	protected int hesapNo;
	protected double bakiye;
	
	public Hesap(int hesapNo, double bakiye) {
		this.hesapNo = hesapNo;
		this.bakiye = bakiye;
	}
	
	public Hesap(double bakiye) {
		this.bakiye = bakiye;
	}
	
	public void paraYatir(double para) {
		bakiye += para;
	}

	public void paraCek(double para) {
		bakiye -= para;
	}
	
	public abstract void bilgiGoster();
}
