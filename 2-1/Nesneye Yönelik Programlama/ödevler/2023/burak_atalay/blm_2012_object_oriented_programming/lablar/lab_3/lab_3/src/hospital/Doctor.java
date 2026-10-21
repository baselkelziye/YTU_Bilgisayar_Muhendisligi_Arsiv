package hospital;

import javax.print.Doc;
import java.util.ArrayList;
import java.util.List;

public class Doctor implements ISurgeon, IMedicalPersonnel {
    private static ArrayList<Doctor> doctorList = new ArrayList<>();
    private String name;
    private double experience;
    private int surgeries;

    public Doctor(String name) {
        this.name = name;
        experience = 0.0;
        surgeries = 0;
        doctorList.add(this);
    }

    public static List<Doctor> getDoctorList(){
        return doctorList;
    }

    @Override
    public void performSurgery() throws SurgeryUnsuccessfulException{
        double r = Math.random()*100;
        if(r < 20) throw new SurgeryUnsuccessfulException("Surgery by " + name + " was unsuccesfull.");
        else{
            experience += 2.5;
            surgeries++;
        }
    }

    public int getSurgery() {
        return surgeries;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Doctor{" +
                "name='" + name + '\'' +
                ", experience=" + experience +
                ", surgeries=" + surgeries +
                '}';
    }
}
