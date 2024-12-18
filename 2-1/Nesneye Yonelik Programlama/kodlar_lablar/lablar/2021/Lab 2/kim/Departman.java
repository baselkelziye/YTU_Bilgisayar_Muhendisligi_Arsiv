package lab2_2021;

public class Departman {
	private final int calSayisi = 3;
	private Calisan[] calisan = new Calisan[calSayisi];
	
	
	public int getCalSayisi() {
		return calSayisi;
	}
	
	
	public Calisan[] getCalisan() {
		return calisan;
	}
	
	public void depBilgisi(int depNo){
		int aSayisi=0;
		int ySayisi=0;
		for(int i=0; i<calSayisi; i++){
			if(calisan[i] instanceof Analist)
				aSayisi++;
			else if(calisan[i] instanceof Yazılımcı) //sadece else deyip bırakırsak, boş dizi elemanını da yazılımcı olarak sayar.
				ySayisi++;
		}
		System.out.println(depNo+" numaralı departmanda "+aSayisi+" tane Analist, "+ySayisi+" tane Yazılımcı vardır.");
		
	}
	
		

	public double maasOrtalama(){
		double toplam=0;
		int count=0;
		for(int i=0; i<calisan.length;i++){
			if(calisan[i]!=null){
				toplam += calisan[i].getMaas();
				count++;
			}
		}
		return toplam/count;
		
	}

	

}
