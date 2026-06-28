package batuhanodcikin;

public class Main{
    public static void main(String[] args) {
        VisaApplicationSystem system = new VisaApplicationSystem();

        // Başvuru sahibi bilgilerini oluştur
        Applicant applicant1 = new Applicant("Begum Ozbay", "P0123", false);
        Applicant applicant2 = new Applicant("Hatice Erdirik", "P4567", true);
        Applicant applicant3 = new Applicant("Toprak Kesgin", "P7890", false);
        Applicant applicant4 = new Applicant("İdris Demir", "P1112", false);

        // Vize türlerini oluştur
        VisaType touristVisa = new VisaType("Turist", 90, false);
        VisaType workVisa = new VisaType("Çalışma", 365, true);

        // Başvuru ekle (örnek 1: Turist vizesi, geçerli süre)
        int duration1 = 30; // 30 gün kalış süresi
        System.out.println("---- Örnek Başvuru 1 ----");
        system.addApplication(applicant1, touristVisa, duration1);

        // Başvuru ekle (örnek 2: Çalışma vizesi, geçerli çalışma izni ile)
        int duration2 = 180; // 180 gün kalış süresi
        System.out.println("---- Örnek Başvuru 2 ----");
        system.addApplication(applicant2, workVisa, duration2);

        // Başvuru ekle (örnek 3: Turist vizesi, geçersiz süre)
        int duration3 = 120; // 120 gün kalış süresi (90 gün üzerinde)
        System.out.println("---- Örnek Başvuru 3 ----");
        system.addApplication(applicant3, touristVisa, duration3);

        // Başvuru ekle (örnek 4: Çalışma vizesi, çalışma izni olmadan)
        int duration4 = 365; // 365 gün kalış süresi
        System.out.println("---- Örnek Başvuru 4 ----");
        system.addApplication(applicant4, workVisa, duration4);
    }
}

