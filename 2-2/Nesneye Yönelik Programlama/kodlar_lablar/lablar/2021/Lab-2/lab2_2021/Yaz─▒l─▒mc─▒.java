package lab2_2021;

public class Yazılımcı extends Calisan {
	private int sertifikaSayisi;

	public Yazılımcı(String isim, int gorevYili, int sertifikaSayisi, double maas) {
		super(isim, gorevYili, maas);
		this.sertifikaSayisi = sertifikaSayisi;
		
	}

	public int getSertifikaSayisi() {
		return sertifikaSayisi;
	}
	
	
	@Override
	public void zamYap() {
		setMaas(maas+maas*0.15);
		setGorevYili(getGorevYili()+1);
		
	}

	@Override
	public String kendiniTanıt() {
		return super.kendiniTanıt() + getSertifikaSayisi() +" adet sertifikam var.";
	}
	
	
	
	
	



	
		
	
	
}
