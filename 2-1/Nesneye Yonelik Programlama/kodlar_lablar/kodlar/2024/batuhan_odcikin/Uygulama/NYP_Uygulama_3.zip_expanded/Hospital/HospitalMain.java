package Hospital;

public class HospitalMain {
    public static void main(String[] args) {
        Hospital hospital = new Hospital();

        Doctor doctor1 = new Doctor("Dr. Smith");
        Doctor doctor2 = new Doctor("Dr. Johnson");
        
        Patient patient1 = new Patient("Carrie Shawn");
        Patient patient2 = new Patient("Ashley Daisy");
        
        Treatment treatment1 = new Treatment("Painkillers", 7, 500.0);
        Treatment treatment2 = new Treatment("Antibiotics", 10, 0.0); // No surgery

        System.out.println("****** Doctors ******");
        Hospital.showList(Doctor.getDoctorList());
        
        System.out.println("\n****** Treatment ******");
        hospital.assignPatientToDoctor(doctor1, patient1, treatment1);
        hospital.assignPatientToDoctor(doctor2, patient2, treatment2);

        System.out.println("\n****** Doctors after surgeries ******");
        Hospital.showList(Doctor.getDoctorList());
    }
}
