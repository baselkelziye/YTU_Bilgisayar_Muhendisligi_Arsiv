package hospital;

import java.util.LinkedList;

public class Patient implements IMedicalPersonnel{
    private String name;
    private LinkedList<Treatment> treatments;

    public Patient(String name) {
        this.name = name;
        treatments = new LinkedList<>();
    }

    @Override
    public String getName() {
        return name;
    }

    public void addTreatment(Treatment t){
        if(t == null) return;
        for(Treatment p: treatments){
            if(p.equals(t)) return;
        }
        treatments.add(t);
    }

    public LinkedList<Treatment> getTreatments() {
        return treatments;
    }

    @Override
    public String toString() {
        return "Patient{" +
                "name='" + name + '\'' +
                ", treatments=" + treatments +
                '}';
    }
}
