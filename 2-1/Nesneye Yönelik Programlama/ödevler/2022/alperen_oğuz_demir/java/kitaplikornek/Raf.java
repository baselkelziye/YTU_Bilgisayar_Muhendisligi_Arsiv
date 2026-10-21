package kitaplikornek;
import java.util.ArrayList;
public class Raf {
	ArrayList<Kitap> kitaplar;

	public Raf() {
		this.kitaplar =new ArrayList<Kitap>();
	}
	public void kitapEkle(Kitap ktp) {
		this.kitaplar.add(ktp);
	}
	public void kitapSil(Kitap ktp) {
		this.kitaplar.remove(ktp);
	}
	public void kitapSil(int index) {
		this.kitaplar.remove(index);	
	}
	
}
