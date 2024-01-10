package lab2_2021;

public class Test {

	public static void main(String[] args) {
		Sirket sirket = new Sirket("Bilişim Firması");
		
		Calisan c[] = new Calisan[12];
		c[0]= new Yazılımcı("Yazılımcı-1", 6,3, 7500);
		c[1]= new Analist("Analist-1", 5,6500);
		c[2]= new Analist("Analist-2", 6, 6500);
		c[3]= new Yazılımcı("Yazılımcı-2", 6,4, 7500);
		c[4]= new Yazılımcı("Yazılımcı-3",5 ,5, 7500);
		c[5]= new Yazılımcı("Yazılımcı-4", 6,4, 7500);
		c[6]= new Yazılımcı("Yazılımcı-5", 6,3, 7500);
		c[7]= new Analist("Analist-3", 6, 6500);
		c[8]= new Analist("Analist-4", 6, 6500);
		c[9]= new Yazılımcı("Yazılımcı-6", 9, 7, 7500);
		c[10]= new Analist("Analist-5", 9, 6500);
		
		
		System.out.println(c[8].kendiniTanıt());
		System.out.println(c[9].kendiniTanıt());
		System.out.println("**********************************");
		
		System.out.println("zamYap metodu çalışıyor...");
		for(int i=0; i<c.length; i++){
			if(c[i]!=null)
				c[i].zamYap();
		}
		
		System.out.println("**********************************");
		System.out.println(c[8].kendiniTanıt());
		System.out.println(c[9].kendiniTanıt());
		System.out.println("**********************************");
		
		System.out.println("Çalışanlar departmanlara yerleştiriliyor...");
		for(int i=0; i<c.length; i++){
			sirket.calisanEkle(c[i]);
		}
		
		System.out.println("**********************************");
		sirket.depMaasOrt(3); 
		
		System.out.println("**********************************");
		System.out.println("Görev yılı en fazla olan kişilerin isimleri:");
		sirket.maxGorevYili();
		
		System.out.println("**********************************");
		sirket.sirketTanıt();
		
		

	}

}
