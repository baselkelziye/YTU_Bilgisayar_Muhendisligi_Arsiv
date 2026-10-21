package lab2;

public class Masa {
	private Sandalye[] sandalyeler;

	public Masa() {
		sandalyeler = new Sandalye[3];
	}

	public Sandalye[] getSandalyeler() {
		return sandalyeler;
	}
	
	public void sandalyeEkle(Sandalye sandalye) {
		for(int i=0;i<sandalyeler.length;i++) {
			if(sandalyeler[i] == null) {
				sandalyeler[i] = sandalye;
				return;
			}
		}
	}
	
	public void sandalyeEkle(Sandalye sandalye, int no) {
		if(sandalyeler[no] != null) {
			System.out.println("Masada yer olmadığı için sandalye eklenemiyor");
			return;
		}
		sandalyeler[no] = sandalye;
	}
	
	public void sandalyeSil(Sandalye sandalye) {
		int i=0;
		while(i < sandalyeler.length && sandalyeler[i].getNo() != sandalye.getNo()) i++;
		if(i < sandalyeler.length) {
			sandalyeler[i] = null;
			System.out.println("sandalye silme işlemi gerçekleşti");
		}
		else {
			System.out.println("sandalye bulunamadı");
		}
	}
	
	public void masaDolulukGoster() {
		for(int i=0;i<sandalyeler.length;i++) {
			if(sandalyeler[i] != null) {
				System.out.println(sandalyeler[i].toString());
			}
		}
	}
}
