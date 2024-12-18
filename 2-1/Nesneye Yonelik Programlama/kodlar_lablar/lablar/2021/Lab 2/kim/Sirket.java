package lab2_2021;

public class Sirket {
	private String isim;
	private final int depSayisi = 4;
	private Departman[] dep = new Departman[depSayisi];	
	
	public Sirket(String isim) {
		this.isim = isim;
		for(int i=0;i<depSayisi;i++)
			dep[i] = new Departman();
	}
	
	
	
	public Departman[] getDep() {
		return dep;
	}

	public void calisanEkle(Calisan calisan) {
		for(int i=0;i<depSayisi;i++)
			for(int j=0;j<dep[i].getCalSayisi();j++)
				if(dep[i].getCalisan()[j]==null){
					dep[i].getCalisan()[j]=calisan;
					return;  //return diyerek metottan çıkış yapılacağını söylüyoruz. Aksi halde for döngüsü devam edecek, aynı çalışanı dizinin tüm elemanlarına ekleyecektir.
				}		
		
	}
	
	public int maxYil(){  //tüm çalışanlar arasındaki en uzun görev yılını döndürür.
		int max=0;
		int a=0;
		for(int i=0;i<depSayisi;i++)
			for(int j=0;j<dep[i].getCalSayisi();j++){
				if(dep[i].getCalisan()[j]!=null){
					 a = dep[i].getCalisan()[j].getGorevYili();
					
					if(a>=max)
						max=a;
				}
					
			}
		return max;
	}
	
	
	public void maxGorevYili(){
		
		int max = maxYil();  //bir metodun başında nesne veya sınıf adı yazmadan çağırıyorsak, bu sınıf içinde tanımlı bir metot demektir.
		
		for(int i=0;i<depSayisi;i++)
			for(int j=0;j<dep[i].getCalSayisi();j++){
				if(dep[i].getCalisan()[j]!=null && dep[i].getCalisan()[j].getGorevYili()== max ){
					System.out.println(dep[i].getCalisan()[j].getIsim()); 
				}
				
				
			}
		
	}




	public void depMaasOrt(int depNo) {
		System.out.println(depNo + " numaralı departmanda çalışanların maaş ortalaması: "+ dep[depNo].maasOrtalama());
		
	}




	public void sirketTanıt() {
		for(int i=0; i<depSayisi; i++)
			dep[i].depBilgisi(i);
		
	}



	public String getIsim() {
		return isim;
	}
	
	
	


}
