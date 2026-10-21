package ahmetsefacetin;

import java.util.ArrayList;
import java.util.Random;

public class Firefighter implements IRescuer, IMedicalPersonnel {

    private static ArrayList<Firefighter> firefighterList = new ArrayList<Firefighter>();
    private String name;
    private double experience;
    private int interventions;

    public Firefighter(String name) {
        this.name = name;
        this.experience = 0;
        this.interventions = 2;
        firefighterList.add(this);
    }

    public static ArrayList<Firefighter> getFirefighterList() {
        return firefighterList;
    }

    public int getInterventions() {
        return interventions;
    }

    @Override
    public String toString() {
        return "Firefighter{" + "name=" + name + ", experience=" + experience + ", interventions=" + interventions + '}';
    }

    @Override
    public String getName() {
        return name;
    }

    double random = new Random().nextDouble();
    @Override
    public void performRescue() throws RescueUnsuccessfulException {
        this.interventions++;
        if (random < 0.2) {
            this.interventions = 0;
           throw new RescueUnsuccessfulException("Rescue by " + this.name + " was unsuccessful.");
        }
        else {
            this.experience += 2.5;
            
        }
        
        
    }

}
