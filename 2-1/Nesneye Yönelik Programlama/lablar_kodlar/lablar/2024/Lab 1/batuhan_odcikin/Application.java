package batuhanodcikin;

public class Application {
	private Applicant applicant;
	private VisaType visaType;
	private String status;
	private int duration;
	
	public Application(Applicant applicant, VisaType visaType, int duration) {
		this.applicant = applicant;
		this.visaType = visaType;
		this.status = "beklemede";
		this.duration = duration;
	}
	
	public void approveApplication() {
		if(visaType.getType().compareTo("Turist") == 0 && duration > visaType.getMaxStayDuration()) {
			status = "Turist Vizesi Reddedildi";
		}
		
		else if (visaType.getType().compareTo("Çalışma") == 0 && applicant.isHasWorkPermit() != true) {
			status = "Çalışma Vizesi Reddedildi";
		}
		
		else {
			status = "Onaylandı";
		}
	}
	
	public void applicationInfo() {
		System.out.println("Başvuru Sahibi: " + applicant.getName());
		System.out.println("Pasaport Numarası: " + applicant.getPassportName());
		
		if (applicant.isHasWorkPermit() == true)
			System.out.println("Çalışma İzni: Var");			
		else
			System.out.println("Çalışma İzni: Yok");
		
		System.out.println("Başvurulan Vize Türü: " + visaType.getType());
		System.out.println("Durum: " + status);
		
		if(status.compareTo("Turist Vizesi Reddedildi") == 0) 
			System.out.println("Reddedilme Nedeni: Turist vizesi için maksimum kalış süresi aşıldı");
		
		else if(status.compareTo("Çalışma Vizesi Reddedildi") == 0) 
			System.out.println("Reddedilme Nedeni: Çalışma izni yok");
		
		else 
			System.out.println("Onaylanan kalış Süresi: " + duration + " gün");
		
		
		System.out.println("---------------------------------\n");
	}

	public String getStatus() {
		return status;
	}
	
	
	
}
