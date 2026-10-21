package hospital;

import javax.print.Doc;
import java.util.ArrayList;
import java.util.List;

public class Hospital {
    private ArrayList<Doctor> medicalPersonnelList;

    public Hospital() {
        medicalPersonnelList = new ArrayList<>();
        medicalPersonnelList.addAll(Doctor.getDoctorList());
    }

    public void addMedicalPersonnel(Doctor personnel){
        if(personnel == null) return;
        for(Doctor p: medicalPersonnelList){
            if(p.equals(personnel)) return;
        }
        medicalPersonnelList.add(personnel);
    }

    public void assignPatientToDoctor (Doctor d, Patient p, Treatment t){
        if (d == null || p == null || t == null) return;
        try{
            d.performSurgery();
            t.setRestPeriodDays((int) (Math.random() * 10) + 1);
            Room r = new Room(t.getRestPeriodDays());
            System.out.println(d.getName() + " performed successfull surgery  on Patient: " +
                    p.getName() + " Prediscribed Treatment: " + t + "\nAllocated Room: " + r +
                    " Daily fee for Patient: " + p.getName() + ": " +
                    t.getSurgeryCost() / t.getRestPeriodDays() + " Total fee for Patient: " +
                    p.getName() + ": " + t.getSurgeryCost());
        }
        catch (SurgeryUnsuccessfulException e){
            System.out.println(e.getMessage());
            System.out.println(p.getName() + " did not survive the surgery.\nTotal fee for " +
                    "Patient: 0.0");
        }
    }


    public static <Z> void showList(List<Z> doctors){
        for(Z a: doctors){
            System.out.println(a);
        }
    }
}
