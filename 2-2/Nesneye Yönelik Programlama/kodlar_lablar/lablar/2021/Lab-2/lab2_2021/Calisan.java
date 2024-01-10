package lab2_2021;

public abstract class Calisan {
	protected String isim;
	protected int gorevYili;
	protected double maas;
	
	

	public Calisan(String isim, int gorevYili, double maas){
		this.isim = isim;
		this.gorevYili = gorevYili;
		this.maas = maas;
	}
	
	public abstract void zamYap();
	
	public String getIsim() {
		return isim;
	}

	public double getMaas() {
		return maas;
	}

	public void setMaas(double maas) {
		this.maas = maas;
	}

	public int getGorevYili() {
		return gorevYili;
	}

	public void setGorevYili(int gorevYili) {
		this.gorevYili = gorevYili;
	}

	public String kendiniTanıt() {
		String s = "İsmim: "+ getIsim() +", "+ getGorevYili()+" yıldır çalışıyorum. "+getMaas()+" lira maaş alıyorum.";
		return s;
		
	}
	
	
	

}
