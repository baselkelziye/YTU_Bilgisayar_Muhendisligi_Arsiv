package Hospital;

import java.util.ArrayList;
import java.util.List;

class Hospital {
    private ArrayList<Doctor> medicalPersonnelList;
    
    public Hospital() {
        medicalPersonnelList = new ArrayList<>();
    }
    
    
    public void addMedicalPersonnel(Doctor personnel) {
        medicalPersonnelList.add(personnel);
    }

    public void assignPatientToDoctor(Doctor doctor, Patient patient, Treatment treatment) {
    	double dailyFee = 100.0;
    	double totalFee;
        try {
            doctor.performSurgery();

            for (int i = 0; i < doctor.getSurgery(); i++) {
                System.out.println(doctor.getName() + " performed successful surgery on " + patient);
                System.out.println("Prescribed Treatment: " + treatment);

                
                int durationOfStay = (int) (Math.random() * 10) + 1;
                Room room = new Room(durationOfStay);
                System.out.println("Allocated Room: " + room);

                room.addTreatment(treatment);
                System.out.println("Daily Fee for " + patient + ": $" + dailyFee);

                totalFee = durationOfStay * dailyFee;
                System.out.println("Total Fee for " + patient + ": $" + totalFee);
                System.out.println("****** Treatment End ******\n");
            }

        } catch (SurgeryUnsuccessfulException e) {
            System.out.println(e.getMessage());
            System.out.println("Patient " + patient + " did not survive the surgery.");

            totalFee = 0.0;
            System.out.println("Total Fee for " + patient + ": $" + totalFee);
            System.out.println("***** Treatment Fail*****\n");
        }
    }
	public static <Z> void showList(List<Z> doctor) {

		for (Z x : doctor)
			System.out.println(x);
		
	}
}
