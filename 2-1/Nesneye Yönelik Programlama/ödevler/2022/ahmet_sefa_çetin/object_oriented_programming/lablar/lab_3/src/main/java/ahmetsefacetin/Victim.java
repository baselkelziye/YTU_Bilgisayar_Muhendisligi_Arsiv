package ahmetsefacetin;

import java.util.LinkedList;

public class Victim implements IMedicalPersonnel{
    private  String name;
    private LinkedList<EmergencyProcedure> emergencyProcedures;

    public Victim(String name) {
        this.name = name;
        emergencyProcedures = new LinkedList<EmergencyProcedure>();
    }

    public String getName() {
        return name;
    }

    public LinkedList<EmergencyProcedure> getEmergencyProcedures() {
        return emergencyProcedures;
    }

    @Override
    public String toString() {
        return "Victim{" + "name=" + name + '}';
    }
    
    
    
    
    
    
}
