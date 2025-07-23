package Hospital;

import java.util.ArrayList;
import java.util.List;

class Doctor implements IMedicalPersonnel, ISurgeon {

	 private static ArrayList<Doctor> doctorList = new ArrayList<>();
	    private String name;
	    private double experience; 
	    int surgeries = 2;
	    
	    public Doctor(String name) {
	        this.name = name;
	        doctorList.add(this);
	    }

	    public static List<Doctor> getDoctorList() {
	        return doctorList;
	    }

	    @Override
	    public String getName() {
	        return name;
	    }

	    @Override
	    public void performSurgery() throws SurgeryUnsuccessfulException {

	       for (int i = 0; i < surgeries; i++) {
	            boolean surgerySuccessful = Math.random() < 0.8; 

	            if (surgerySuccessful) {
	                experience += 2.5;
	            } else {
	            	experience = 0;
	                throw new SurgeryUnsuccessfulException("Surgery by " + name + " was unsuccessful.");
	            }
	        }
	    }

	    public double getSurgery() {
	        return surgeries;
	    }

	    @Override
	    public String toString() {
	        return "Doctor: " + name + ", Experience: " + experience + " surgeries";
	    }
	}

