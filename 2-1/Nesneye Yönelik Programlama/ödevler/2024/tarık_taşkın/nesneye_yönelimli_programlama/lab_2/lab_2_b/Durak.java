package lab2_b;

public class Durak {
	private int durakKodu;

	public Durak(int durakKodu) {
		this.durakKodu = durakKodu;
	}


	@Override
	public String toString() {
		return "Durak [durakKodu=" + durakKodu + "]";
	}


	public int getDurakKodu() {
		return durakKodu;
	}

	
	
}
