package lab2_2021;

public class Analist extends Calisan {

	public Analist(String adi, int yili, double maasi) {
		super(adi, yili, maasi);
		
	}

	@Override
	public void zamYap() {
		setMaas(maas+maas*0.1);
		setGorevYili(getGorevYili()+1);
		
	}
	
		
	
}
