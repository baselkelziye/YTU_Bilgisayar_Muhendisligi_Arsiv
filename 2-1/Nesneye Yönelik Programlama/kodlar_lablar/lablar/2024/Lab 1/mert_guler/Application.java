package mertguler;

public class Application {
    private Applicant applicant;
    private VisaType visaType;
    private String status;
    private int duration;

    public Application(Applicant applicant, VisaType visaType, int duration){
        this.applicant = applicant;
        this.visaType = visaType;
        this.duration = duration;
        status = "beklemede";
    }

    public void approveApplication(){
        status = "Onaylandi";

        if (duration > visaType.getMaxStayDuration() && visaType.getType().equals("Turist")){
            status = "Turist Vizesi Reddedildi";
        }

        if (visaType.getType().equals("Çalışma") && applicant.hasWorkPermit() == false){
            status = "Calisma Vizesi Reddedildi";
        }

    }

    public void applicationInfo(){
        System.out.println(applicant);
        System.out.println("Basvurulan Vize Turu: " + visaType.getType());
        System.out.println("Durum: " + status);

        if (status.equals("Onaylandi")){
            System.out.println("Onaylanan Kalis Suresi: " +  duration + " gun");
        }

        if (status.equals("Turist Vizesi Reddedildi")){
            System.out.println("Reddetme Nedeni: Turist vizesi icin maksimum kalis suresi asildi");
        }

        if(status.equals("Calisma Vizesi Reddedildi")){
            System.out.println("Reddetme Nedeni: Calisma izni yok");
        }
    }

    public String getStatus(){
        return status;
    }
}
