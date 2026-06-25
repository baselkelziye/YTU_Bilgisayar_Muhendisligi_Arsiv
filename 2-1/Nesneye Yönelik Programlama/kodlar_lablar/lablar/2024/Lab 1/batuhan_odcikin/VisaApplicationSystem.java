package batuhanodcikin;

import java.util.ArrayList;

public class VisaApplicationSystem {
	private ArrayList<Application> applications;

	public VisaApplicationSystem() {
		applications = new ArrayList<Application>();
	}

	
	public void addApplication(Applicant applicant, VisaType visaType, int duration) {
		Application application = new Application(applicant, visaType, duration);
		application.approveApplication();
		applications.add(application);
		application.applicationInfo();
	}
}
