package myPackage;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Istatistik {
	private int interruptedGame;
	private int failedGame;
	private int successGame;
	private int satirSayisi;
	private int toplamSure;
	private String[] string;
	public Istatistik(int interruptedGame, int failedGame, int successGame,int  toplamSure) {
		this.interruptedGame=interruptedGame;
		this.successGame=successGame;
		this.failedGame=failedGame;
		this.toplamSure=toplamSure;

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
		      myWriter.write(interruptedGame + "\n");
		      myWriter.write(failedGame + "\n");
		      myWriter.write(successGame + "\n");
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
		string[0] = "Satistics";
		string[1]="Leave Game := " + interruptedGame;
		string[2]="Successful Game :" +successGame;
		string[3]="Failed Game= " +failedGame;
	}	
		
		
	public String[] getIstatistik() {
		return string;
	}
	public int getYaridaBirakilanOyun() {
		return interruptedGame;
	}
	public void setYaridaBirakilanOyun(int interruptedGame) {
		this.interruptedGame = interruptedGame;
		istatistikDizisi();
	}
	public int getBasarisizOyun() {
		return failedGame;
	}
	public void setBasarisizOyun(int failedGame) {
		this.failedGame = failedGame;
		istatistikDizisi();
	}
	public int getBasariliOyun() {
		return successGame;
	}
	public void setBasariliOyun(int successGame) {
		this.successGame = successGame;
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
