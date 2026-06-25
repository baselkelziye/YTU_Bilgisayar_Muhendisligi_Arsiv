package yusufsafakoksal;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Hospital {
	private ArrayList<Doctor> medicalPersonelList;
	
	public Hospital() {
		medicalPersonelList=new ArrayList<Doctor>();
	}
	
	public void addMedicalPersonel(Doctor personel) {
		if(!medicalPersonelList.contains(personel)) {
			medicalPersonelList.add(personel);
		}
	}
	
	public void assignPatientToDoctor(Doctor doctor, Patient patient, Treatment treatment) {
		double dailyFee=100, totalFee=0;
		boolean wasSurgerySuccessful=true;
		
		try {
			doctor.performSurgery();
		} catch (Exception e) {
			System.out.println(e.getMessage());
			wasSurgerySuccessful=false;
		}
		
		if(wasSurgerySuccessful) {
			System.out.println(doctor.getName()+ " performed successful surgery on Patient: "+patient.getName());
			int durationOfStay=(int) (new Random().nextDouble()*10);
			totalFee=durationOfStay*dailyFee;
			Room room=new Room(durationOfStay);
			System.out.println(treatment);
			System.out.println(room.toString());
			System.out.println("Daily Fee for Patient: "+patient.getName()+": $"+dailyFee);
			System.out.println("Total Fee for Patient: "+patient.getName()+": $"+totalFee);
			System.out.println("*******Treatment End**********\n");
		}
		else {
			System.out.println("Surgery by "+doctor.getName()+" was unsuccessful.");
			System.out.println("Patient: "+patient.getName()+" did not survive the surgery.");
			System.out.println("Total Fee for Patient: "+patient.getName()+": $"+totalFee);
			System.out.println("*******Treatment Fail**********\n");
		}
		
		
	}
	
	public static <Z> void showList(List<Z> doctors) {
		for(Z doctor:doctors) {
			System.out.println(doctor);
		}
	}
}
