package myPackage;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
/* Ýstatistiklerle alakalý tüm iþlem ve kontrolleri burada yapýyorum.
  */
 
public class Istatistik {
	private int yaridaBirakilanOyun;
	private int basarisizOyun;
	private int basariliOyun;
	private int satirSayisi;
	private int toplamSure;
	private String[] string;
	public Istatistik(int yaridaBirakilanOyun, int basarisizOyun, int basariliOyun,int satirSayisi,int  toplamSure) {
		this.yaridaBirakilanOyun=yaridaBirakilanOyun;
		this.basariliOyun=basariliOyun;
		this.basarisizOyun=basarisizOyun;
		this.toplamSure=toplamSure;
		this.satirSayisi=satirSayisi;
		string = new String[6];
		istatistikDizisi();
	}
	public void istatistikYaz() { 
		try {
		      File myObj = new File("istatistik.txt");
		      myObj.createNewFile();
		     
		    } catch (IOException c) {
		      c.printStackTrace();
		    }
		try {
		      FileWriter myWriter = new FileWriter("istatistik.txt");
		      myWriter.write(yaridaBirakilanOyun + "\n");
		      myWriter.write(basarisizOyun + "\n");
		      myWriter.write(basariliOyun + "\n");
		      myWriter.write(satirSayisi + "\n");
		      myWriter.write(toplamSure +"");
		      myWriter.close();
		    } catch (IOException c) {
		      c.printStackTrace();
		    }
	}
	public int getSatirSayisi() {
		return satirSayisi;
	}
	public void setSatirSayisi(int satirSayisi) {
		this.satirSayisi = satirSayisi;
		istatistikDizisi();
	}
	public void istatistikDizisi() {

		string = new String[6];
		string[0] = "Meraklýsý için istatistikler";
		string[1]="Yarýda Býrakýlan Oyun Sayýsý = " + yaridaBirakilanOyun;
		string[2]="Baþarýlý Oyun Sayýsý = " +basariliOyun;
		string[3]="Baþarýsýz Oyun Sayýsý = " +basarisizOyun;
		if(basariliOyun!=0) {
			string[4]="Bitirenlerin Ortalama Satýr Sayýsý = " + (double)satirSayisi/basariliOyun;
			string[5]="Bitirenlerin Ortalama Süresi = " + (double)toplamSure/basariliOyun;
		}
		else {
			string[4]="Bitirenlerin Ortalama Satýr Sayýsý = " + (double)0;
			string[5]="Bitirenlerin Ortalama Süresi = " + (double)0;
		}
		
		int i=0;
		while(string[4].charAt(i)!='.') {
			i++;
		}
		int k=0;
		while(k<2 && string[4].length()>k+i) {
			k++;
		}
		string[4]=string[4].substring(0,i+k);
		 i=0;
		while(string[5].charAt(i)!='.') {
			i++;
		}
		 k=0;
		while(k<2 && string[5].length()>k+i) {
			k++;
		}
		string[5]=string[5].substring(0,i+k);
		
		
	}
	public String[] getIstatistik() {
		return string;
	}
	public int getYaridaBirakilanOyun() {
		return yaridaBirakilanOyun;
	}
	public void setYaridaBirakilanOyun(int yaridaBirakilanOyun) {
		this.yaridaBirakilanOyun = yaridaBirakilanOyun;
		istatistikDizisi();
	}
	public int getBasarisizOyun() {
		return basarisizOyun;
	}
	public void setBasarisizOyun(int basarisizOyun) {
		this.basarisizOyun = basarisizOyun;
		istatistikDizisi();
	}
	public int getBasariliOyun() {
		return basariliOyun;
	}
	public void setBasariliOyun(int basariliOyun) {
		this.basariliOyun = basariliOyun;
		istatistikDizisi();
	}
	public int getToplamSure() {
		return toplamSure;
	}
	public void setToplamSure(int toplamSure) {
		this.toplamSure = toplamSure;
		istatistikDizisi();
	}
	public String[] getString() {
		return string;
	}
	public void setString(String[] string) {
		this.string = string;
	}
	
}
