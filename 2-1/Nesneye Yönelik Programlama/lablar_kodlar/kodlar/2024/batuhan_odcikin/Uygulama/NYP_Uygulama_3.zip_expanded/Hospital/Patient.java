package Hospital;

import java.util.LinkedList;

class Patient implements IMedicalPersonnel {
    private String name;
    private LinkedList<Treatment> treatments; 

    public Patient(String name) {
        this.name = name;
        this.treatments = new LinkedList<>();
    }

    @Override
    public String getName() {
        return name;
    }

    public LinkedList<Treatment> getTreatments() {
        return treatments;
    }

    @Override
    public String toString() {
        return "Patient: " + name;
    }
}
