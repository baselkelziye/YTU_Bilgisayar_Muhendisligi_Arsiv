package lab2_a;

public class Masa {

	private Sandalye[] sandalyeler;

	public Masa() {
		this.sandalyeler = new Sandalye[3];
	}

	public void sandalyeEkle(Sandalye s) {
		int i = 0;
		while (i < sandalyeler.length && sandalyeler[i] != null)
			i++;

		if (i != sandalyeler.length)
			sandalyeler[i] = s;
		else
			System.out.println("masada yer olmadıgı ıcın sandalye eklenemiyor.");
	}

	public void sandalyeEkle(Sandalye sandalye, int sira) {
		if (sira < sandalyeler.length && sandalyeler[sira] == null)
			sandalyeler[sira] = sandalye;

		else
			System.out.println("masa ekleme için uygun değil");
	}

	public void sandalyeSil(Sandalye s) {
		int i = 0;
		while (i < sandalyeler.length && sandalyeler[i] == s)
			i++;
		if (i != sandalyeler.length) {
			sandalyeler[i] = null;
			System.out.println("Sandalye silme işlemi gerçekleşti.");
		}
	}

	public void masaDolulukGoster() {
		for (int i = 0; i < sandalyeler.length; i++)
			System.out.println(sandalyeler[i]);
	}

	public Sandalye[] getSandalyeler() {
		return sandalyeler;
	}
	
	

}
