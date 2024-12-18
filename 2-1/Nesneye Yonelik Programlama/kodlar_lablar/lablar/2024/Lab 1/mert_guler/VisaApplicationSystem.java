package mertguler;

import java.util.ArrayList;
import java.util.List;

public class VisaApplicationSystem {
    private List<Application> applications = new ArrayList<>();

    public void addApplication(Applicant applicant, VisaType visaType, int duration){
        Application application = new Application(applicant, visaType, duration);
        application.approveApplication();
        applications.add(application);
        application.applicationInfo();
    }
}
