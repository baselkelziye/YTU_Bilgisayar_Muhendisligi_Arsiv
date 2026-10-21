package tariktaskin;

public class Durak {
	private int durakKodu;

	public Durak(int durakKodu) {
		this.durakKodu = durakKodu;
	}

	public int getDurakKodu() {
		return durakKodu;
	}

	@Override
	public String toString() {
		return "Durak [durakKodu=" + durakKodu + "]";
	}
	
	
}
