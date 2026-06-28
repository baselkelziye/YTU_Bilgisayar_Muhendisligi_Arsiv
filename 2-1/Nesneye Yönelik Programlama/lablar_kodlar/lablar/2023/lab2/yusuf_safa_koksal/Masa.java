package yusufsafakoksal;

public class Masa {
	private Sandalye sandalyeler[];

	public Masa() {
		sandalyeler=new Sandalye[3];
	}
	
	public Sandalye[] getSandalyeler() {
		return sandalyeler;
	}

	public void sandalyeEkle(Sandalye sandalye) {
		for(int i=0;i<3;i++) {
			if(sandalyeler[i]==null) {
				sandalyeler[i]=sandalye;
				return;
			}
		}
		System.out.println("Masada yer olmadigi icin sandalye eklenemiyor");
	}
	
	public void sandalyeEkle(Sandalye sandalye, int sira) {
		if(sandalyeler[sira]==null) {
			sandalyeler[sira]=sandalye;
			return;
		}
		System.out.println("Masada yer olmadigi icin sandalye eklenemiyor");
	}
	
	public void sandalyeSil(Sandalye sandalye) {
		for(int i=0;i<3;i++) {
			if(sandalyeler[i].getNo()==sandalye.getNo()) {
				sandalyeler[i]=null;
				System.out.println("Sandalye silme islemi gerceklesti");
				return;
			}
		}
		System.out.println("Sandalye bulunamadi");
	}
	
	public void masaDolulukGoster() {
		for(Sandalye sandalye:sandalyeler) {
			if(sandalye!=null) {
				System.out.println("Sandalye [no="+sandalye.getNo()+",  doluluk="+sandalye.isDoluluk()+"]");
			}
			else {
				System.out.println("null");
			}
		}
	}
	
}
